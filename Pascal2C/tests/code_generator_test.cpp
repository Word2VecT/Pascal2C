#include <string>
#include <gtest/gtest.h>
#include <memory>
#include <fstream>
#include <sstream>
#include "../include/code_generator.h"
#include "../include/ast.h"
#include "../src/pascal_lexer.h"
#include "../src/pascal_parser.h"

// 外部声明
extern FILE* yyin;
extern int yyparse(void);
extern void yyrestart(FILE* input_file);
extern YY_BUFFER_STATE yy_scan_string(const char* str);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);
extern std::unique_ptr<ProgramNode> programRoot;

// 重置解析器状态
void reset_parser() {
    programRoot.reset();
}

class CodeGeneratorTest : public ::testing::Test {
protected:
    void SetUp() override {
        reset_parser();
    }

    void TearDown() override {
        reset_parser();
        // 清理测试生成的文件
        std::remove("test_output.c");
    }

    // 从字符串解析Pascal并生成C代码
    bool generateCodeFromString(const std::string& input, const std::string& outputFile = "test_output.c") {
        YY_BUFFER_STATE buffer = yy_scan_string(input.c_str());
        reset_parser();
        bool parseResult = (yyparse() == 0); // 0表示成功解析
        yy_delete_buffer(buffer);
        
        if (parseResult && programRoot) {
            CodeGenerator generator(outputFile);
            programRoot->generate(generator);
            generator.finalize();
            return true;
        }
        return false;
    }

    // 从文件解析Pascal并生成C代码
    bool generateCodeFromFile(const std::string& inputFile, const std::string& outputFile = "test_output.c") {
        FILE* file = fopen(inputFile.c_str(), "r");
        if (!file) {
            return false;
        }
        
        yyrestart(file);
        reset_parser();
        bool parseResult = (yyparse() == 0); // 0表示成功解析
        fclose(file);
        
        if (parseResult && programRoot) {
            CodeGenerator generator(outputFile);
            programRoot->generate(generator);
            generator.finalize();
            return true;
        }
        return false;
    }

    // 读取生成的C代码
    std::string readGeneratedCode(const std::string& filename = "test_output.c") {
        std::ifstream file(filename);
        if (!file.is_open()) {
            return "";
        }
        
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }
    
    // 检查生成的代码中是否包含指定内容
    bool codeContains(const std::string& generatedCode, const std::string& expectedContent) {
        return generatedCode.find(expectedContent) != std::string::npos;
    }
};

// 测试简单程序的代码生成
TEST_F(CodeGeneratorTest, TestSimpleProgram) {
    std::string input = 
        "program Simple;\n"
        "begin\n"
        "end.";
    
    ASSERT_TRUE(generateCodeFromString(input));
    std::string generatedCode = readGeneratedCode();
    
    EXPECT_TRUE(codeContains(generatedCode, "#include <stdio.h>"));
    EXPECT_TRUE(codeContains(generatedCode, "#include <stdlib.h>"));
    EXPECT_TRUE(codeContains(generatedCode, "int main()"));
    EXPECT_TRUE(codeContains(generatedCode, "return 0;"));
}

// 测试变量声明的代码生成
TEST_F(CodeGeneratorTest, TestVariableDeclaration) {
    std::string input = 
        "program VarTest;\n"
        "var\n"
        "  i, j: integer;\n"
        "  x, y: real;\n"
        "  flag: boolean;\n"
        "  name: string;\n"
        "begin\n"
        "end.";
    
    ASSERT_TRUE(generateCodeFromString(input));
    std::string generatedCode = readGeneratedCode();
    
    // 检查生成的变量声明
    EXPECT_TRUE(codeContains(generatedCode, "int i;"));
    EXPECT_TRUE(codeContains(generatedCode, "int j;"));
    EXPECT_TRUE(codeContains(generatedCode, "double x;"));
    EXPECT_TRUE(codeContains(generatedCode, "double y;"));
    EXPECT_TRUE(codeContains(generatedCode, "bool flag;"));
    EXPECT_TRUE(codeContains(generatedCode, "char* name;"));
}

// 测试赋值语句的代码生成
TEST_F(CodeGeneratorTest, TestAssignment) {
    std::string input = 
        "program AssignTest;\n"
        "var\n"
        "  i: integer;\n"
        "  x: real;\n"
        "  flag: boolean;\n"
        "begin\n"
        "  i := 42;\n"
        "  x := 3.14;\n"
        "  flag := true;\n"
        "end.";
    
    ASSERT_TRUE(generateCodeFromString(input));
    std::string generatedCode = readGeneratedCode();
    
    // 检查生成的赋值语句
    EXPECT_TRUE(codeContains(generatedCode, "i = 42;"));
    EXPECT_TRUE(codeContains(generatedCode, "x = 3.14;"));
    EXPECT_TRUE(codeContains(generatedCode, "flag = true;"));
}

// 测试表达式的代码生成
TEST_F(CodeGeneratorTest, TestExpressions) {
    std::string input = 
        "program ExprTest;\n"
        "var\n"
        "  a, b, c: integer;\n"
        "begin\n"
        "  a := 5;\n"
        "  b := 10;\n"
        "  c := a + b * 2;\n"
        "end.";
    
    ASSERT_TRUE(generateCodeFromString(input));
    std::string generatedCode = readGeneratedCode();
    
    // 检查生成的表达式
    EXPECT_TRUE(codeContains(generatedCode, "a = 5;"));
    EXPECT_TRUE(codeContains(generatedCode, "b = 10;"));
    EXPECT_TRUE(codeContains(generatedCode, "c = (a + (b * 2));"));
}

// 测试条件语句的代码生成
TEST_F(CodeGeneratorTest, TestIfStatement) {
    std::string input = 
        "program IfTest;\n"
        "var\n"
        "  x: integer;\n"
        "begin\n"
        "  x := 10;\n"
        "  if x > 5 then\n"
        "    x := x - 5\n"
        "  else\n"
        "    x := x + 5;\n"
        "end.";
    
    ASSERT_TRUE(generateCodeFromString(input));
    std::string generatedCode = readGeneratedCode();
    
    // 检查生成的if语句
    EXPECT_TRUE(codeContains(generatedCode, "if ((x > 5)) {"));
    EXPECT_TRUE(codeContains(generatedCode, "x = (x - 5);"));
    EXPECT_TRUE(codeContains(generatedCode, "} else {"));
    EXPECT_TRUE(codeContains(generatedCode, "x = (x + 5);"));
}

// 测试循环语句的代码生成
TEST_F(CodeGeneratorTest, TestWhileLoop) {
    std::string input = 
        "program WhileTest;\n"
        "var\n"
        "  i, sum: integer;\n"
        "begin\n"
        "  i := 1;\n"
        "  sum := 0;\n"
        "  while i <= 10 do\n"
        "  begin\n"
        "    sum := sum + i;\n"
        "    i := i + 1;\n"
        "  end;\n"
        "end.";
    
    ASSERT_TRUE(generateCodeFromString(input));
    std::string generatedCode = readGeneratedCode();
    
    // 检查生成的while循环
    EXPECT_TRUE(codeContains(generatedCode, "while ((i <= 10)) {"));
    EXPECT_TRUE(codeContains(generatedCode, "sum = (sum + i);"));
    EXPECT_TRUE(codeContains(generatedCode, "i = (i + 1);"));
}

// 测试复杂表达式的代码生成
TEST_F(CodeGeneratorTest, TestComplexExpressions) {
    std::string input = 
        "program ComplexExprTest;\n"
        "var\n"
        "  a, b, c, d: integer;\n"
        "  flag1, flag2, flag3: boolean;\n"
        "begin\n"
        "  a := 5;\n"
        "  b := 10;\n"
        "  c := 15;\n"
        "  d := (a + b) * c div 3;\n"
        "  flag1 := a < b;\n"
        "  flag2 := b > c;\n"
        "  flag3 := flag1 and not flag2;\n"
        "end.";
    
    ASSERT_TRUE(generateCodeFromString(input));
    std::string generatedCode = readGeneratedCode();
    
    // 检查生成的复杂表达式
    EXPECT_TRUE(codeContains(generatedCode, "d = (((a + b) * c) / 3);") || 
                codeContains(generatedCode, "d = ((a + b) * c / 3);"));
    EXPECT_TRUE(codeContains(generatedCode, "flag1 = (a < b);"));
    EXPECT_TRUE(codeContains(generatedCode, "flag2 = (b > c);"));
    EXPECT_TRUE(codeContains(generatedCode, "flag3 = (flag1 && (!flag2));") || 
                codeContains(generatedCode, "flag3 = ((flag1) && (!flag2));"));
}

// 测试专用于代码生成器的Pascal程序
TEST_F(CodeGeneratorTest, TestGeneratorSpecificProgram) {
    ASSERT_TRUE(generateCodeFromFile("tests/test_samples/generator_test.pas"));
    std::string generatedCode = readGeneratedCode();
    
    // 检查生成代码的关键部分
    EXPECT_TRUE(codeContains(generatedCode, "/* Program GeneratorTest */"));
    EXPECT_TRUE(codeContains(generatedCode, "#include <stdio.h>"));
    EXPECT_TRUE(codeContains(generatedCode, "#include <stdlib.h>"));
    EXPECT_TRUE(codeContains(generatedCode, "#include <stdbool.h>"));
    
    // 检查常量定义
    EXPECT_TRUE(codeContains(generatedCode, "#define PI 3.14159") ||
                codeContains(generatedCode, "const double PI = 3.14159"));
    
    // 检查变量声明
    EXPECT_TRUE(codeContains(generatedCode, "int counter;"));
    EXPECT_TRUE(codeContains(generatedCode, "double ratio;"));
    EXPECT_TRUE(codeContains(generatedCode, "char* message;"));
    EXPECT_TRUE(codeContains(generatedCode, "bool isActive;"));
    
    // 检查函数实现
    EXPECT_TRUE(codeContains(generatedCode, "int Add(int x, int y)") ||
                codeContains(generatedCode, "int Add(int x, int y)"));
    
    // 检查条件语句
    EXPECT_TRUE(codeContains(generatedCode, "if ((counter < 10))"));
    
    // 检查循环结构
    EXPECT_TRUE(codeContains(generatedCode, "while ((counter <= 5))"));
    
    // 检查数组和记录访问
    EXPECT_TRUE(codeContains(generatedCode, "scores[1] = 95.5") ||
                codeContains(generatedCode, "scores[1] = 95.5;"));
    EXPECT_TRUE(codeContains(generatedCode, "person.name = \"John Doe\"") ||
                codeContains(generatedCode, "person.name = \"John Doe\";"));
}

// 测试完整Pascal程序的代码生成
TEST_F(CodeGeneratorTest, TestFullProgram) {
    ASSERT_TRUE(generateCodeFromFile("tests/test_samples/parser_test.pas"));
    std::string generatedCode = readGeneratedCode();
    
    // 检查生成代码的关键部分
    EXPECT_TRUE(codeContains(generatedCode, "/* Program ParserTest */"));
    EXPECT_TRUE(codeContains(generatedCode, "#include <stdio.h>"));
    EXPECT_TRUE(codeContains(generatedCode, "#include <stdlib.h>"));
    EXPECT_TRUE(codeContains(generatedCode, "#include <stdbool.h>"));
    EXPECT_TRUE(codeContains(generatedCode, "int main()"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 