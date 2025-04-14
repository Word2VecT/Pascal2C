#include <string>
#include <gtest/gtest.h>
#include <memory>
#include <fstream>
#include "../src/pascal_lexer.h"
#include "../src/pascal_parser.h"
#include "../include/ast.h"

// 重定向yylex和yyparse函数的输入
extern FILE* yyin;
extern int yyparse(void);
extern void yyrestart(FILE* input_file);
extern YY_BUFFER_STATE yy_scan_string(const char* str);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);
extern std::unique_ptr<ProgramNode> programRoot; // 在parser.cpp中定义

// 重置解析器状态的辅助函数
void reset_parser() {
    // 释放先前的AST
    programRoot.reset();
}

class PascalParserTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 测试前的准备工作
        reset_parser();
    }

    void TearDown() override {
        // 测试后的清理工作
        reset_parser();
    }

    // 使用字符串作为输入进行语法分析的辅助函数
    bool parseString(const std::string& input) {
        YY_BUFFER_STATE buffer = yy_scan_string(input.c_str());
        reset_parser(); // 重置解析器状态
        bool result = (yyparse() == 0); // 0表示成功解析
        yy_delete_buffer(buffer);
        return result;
    }

    // 从文件解析的辅助函数
    bool parseFile(const std::string& filepath) {
        FILE* file = fopen(filepath.c_str(), "r");
        if (!file) {
            return false;
        }
        
        yyrestart(file);
        reset_parser(); // 重置解析器状态
        bool result = (yyparse() == 0); // 0表示成功解析
        
        fclose(file);
        return result;
    }
};

// 测试程序声明解析
TEST_F(PascalParserTest, TestProgramDeclaration) {
    std::string input = "program HelloWorld; begin end.";
    ASSERT_TRUE(parseString(input));
    ASSERT_TRUE(programRoot != nullptr);
    EXPECT_EQ(programRoot->getName(), "HelloWorld");
}

// 测试变量声明解析
TEST_F(PascalParserTest, TestVarDeclaration) {
    std::string input = 
        "program VarTest;\n"
        "var\n"
        "  i, j: integer;\n"
        "  x, y: real;\n"
        "  name: string;\n"
        "begin\n"
        "end.";
    
    ASSERT_TRUE(parseString(input));
    ASSERT_TRUE(programRoot != nullptr);
    EXPECT_EQ(programRoot->getName(), "VarTest");
    
    // 验证声明部分
    const auto& declarations = programRoot->getDeclarations();
    EXPECT_GT(declarations.size(), 0);
}

// 测试基本语句解析
TEST_F(PascalParserTest, TestBasicStatements) {
    std::string input = 
        "program StatementTest;\n"
        "var\n"
        "  i: integer;\n"
        "begin\n"
        "  i := 10;\n"
        "end.";
    
    ASSERT_TRUE(parseString(input));
    ASSERT_TRUE(programRoot != nullptr);
    
    // 验证语句部分
    const auto& statements = programRoot->getStatements();
    EXPECT_GT(statements.size(), 0);
}

// 测试表达式解析
TEST_F(PascalParserTest, TestExpressions) {
    std::string input = 
        "program ExprTest;\n"
        "var\n"
        "  a, b, c: integer;\n"
        "begin\n"
        "  a := 5;\n"
        "  b := 10;\n"
        "  c := a + b * 2;\n"
        "end.";
    
    ASSERT_TRUE(parseString(input));
    ASSERT_TRUE(programRoot != nullptr);
}

// 测试if语句解析
TEST_F(PascalParserTest, TestIfStatement) {
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
    
    ASSERT_TRUE(parseString(input));
    ASSERT_TRUE(programRoot != nullptr);
}

// 测试while循环解析
TEST_F(PascalParserTest, TestWhileLoop) {
    std::string input = 
        "program WhileTest;\n"
        "var\n"
        "  i: integer;\n"
        "begin\n"
        "  i := 10;\n"
        "  while i > 0 do\n"
        "  begin\n"
        "    i := i - 1;\n"
        "  end;\n"
        "end.";
    
    ASSERT_TRUE(parseString(input));
    ASSERT_TRUE(programRoot != nullptr);
}

// 测试for循环解析
TEST_F(PascalParserTest, TestForLoop) {
    std::string input = 
        "program ForTest;\n"
        "var\n"
        "  i, sum: integer;\n"
        "begin\n"
        "  sum := 0;\n"
        "  for i := 1 to 10 do\n"
        "  begin\n"
        "    sum := sum + i;\n"
        "  end;\n"
        "end.";
    
    ASSERT_TRUE(parseString(input));
    ASSERT_TRUE(programRoot != nullptr);
}

// 测试嵌套块语句解析
TEST_F(PascalParserTest, TestNestedBlocks) {
    std::string input = 
        "program NestedTest;\n"
        "var\n"
        "  i, j: integer;\n"
        "begin\n"
        "  i := 1;\n"
        "  begin\n"
        "    j := 2;\n"
        "    begin\n"
        "      i := i + j;\n"
        "    end;\n"
        "  end;\n"
        "end.";
    
    ASSERT_TRUE(parseString(input));
    ASSERT_TRUE(programRoot != nullptr);
}

// 测试过程和函数定义解析
TEST_F(PascalParserTest, TestProcedureFunctionDeclaration) {
    std::string input = 
        "program ProcTest;\n"
        "var\n"
        "  a, b, c: integer;\n"
        "\n"
        "function Add(x, y: integer): integer;\n"
        "begin\n"
        "  Add := x + y;\n"
        "end;\n"
        "\n"
        "procedure Print(val: integer);\n"
        "begin\n"
        "  { procedure body }\n"
        "end;\n"
        "\n"
        "begin\n"
        "  a := 5;\n"
        "  b := 10;\n"
        "  c := Add(a, b);\n"
        "  Print(c);\n"
        "end.";
    
    ASSERT_TRUE(parseString(input));
    ASSERT_TRUE(programRoot != nullptr);
}

// 测试解析错误处理
TEST_F(PascalParserTest, TestParsingErrors) {
    // 缺少分号
    std::string input1 = 
        "program ErrorTest;\n"
        "var\n"
        "  i: integer\n" // 缺少分号
        "begin\n"
        "  i := 10;\n"
        "end.";
    
    EXPECT_FALSE(parseString(input1));
    
    // 缺少end
    std::string input2 = 
        "program ErrorTest;\n"
        "var\n"
        "  i: integer;\n"
        "begin\n"
        "  i := 10;\n"
        "."; // 缺少end
    
    EXPECT_FALSE(parseString(input2));
    
    // 不匹配的括号
    std::string input3 = 
        "program ErrorTest;\n"
        "var\n"
        "  i: integer;\n"
        "begin\n"
        "  i := (10 + 5;\n" // 不匹配的括号
        "end.";
    
    EXPECT_FALSE(parseString(input3));
}

// 测试完整的Pascal程序文件解析
TEST_F(PascalParserTest, TestFullProgramFile) {
    ASSERT_TRUE(parseFile("tests/test_samples/lexer_test.pas"));
    ASSERT_TRUE(programRoot != nullptr);
    EXPECT_EQ(programRoot->getName(), "LexerTest");
}

// 测试专用于解析器的复杂Pascal程序
TEST_F(PascalParserTest, TestComplexParserProgram) {
    ASSERT_TRUE(parseFile("tests/test_samples/parser_test.pas"));
    ASSERT_TRUE(programRoot != nullptr);
    EXPECT_EQ(programRoot->getName(), "ParserTest");
    
    // 验证函数和过程定义
    const auto& declarations = programRoot->getDeclarations();
    EXPECT_GT(declarations.size(), 0);
    
    // 验证语句
    const auto& statements = programRoot->getStatements();
    EXPECT_GT(statements.size(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 