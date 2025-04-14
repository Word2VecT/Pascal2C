#include <string>
#include <gtest/gtest.h>
#include "../src/pascal_lexer.h"
#include "../src/pascal_parser.h"

// 重定向yylex函数的输入
extern FILE* yyin;
extern int yylex(void);
extern int yylineno;
extern char* yytext;
extern void yyrestart(FILE* input_file);
extern YY_BUFFER_STATE yy_scan_string(const char* str);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);

class PascalLexerTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 重置行号
        yylineno = 1;
    }

    void TearDown() override {
        // 清理工作
    }

    // 使用字符串作为输入进行词法分析的辅助函数
    std::vector<int> scanTokens(const std::string& input) {
        YY_BUFFER_STATE buffer = yy_scan_string(input.c_str());
        std::vector<int> tokens;
        
        int token;
        while ((token = yylex()) != 0) {
            tokens.push_back(token);
        }
        
        yy_delete_buffer(buffer);
        return tokens;
    }
};

// 测试基本关键字
TEST_F(PascalLexerTest, TestKeywords) {
    std::string input = "program begin end var function procedure";
    auto tokens = scanTokens(input);
    
    ASSERT_EQ(tokens.size(), 6);
    EXPECT_EQ(tokens[0], T_PROGRAM);
    EXPECT_EQ(tokens[1], T_BEGIN);
    EXPECT_EQ(tokens[2], T_END);
    EXPECT_EQ(tokens[3], T_VAR);
    EXPECT_EQ(tokens[4], T_FUNCTION);
    EXPECT_EQ(tokens[5], T_PROCEDURE);
}

// 测试控制流关键字
TEST_F(PascalLexerTest, TestControlFlowKeywords) {
    std::string input = "if then else while do for to downto repeat until case of";
    auto tokens = scanTokens(input);
    
    ASSERT_EQ(tokens.size(), 12);
    EXPECT_EQ(tokens[0], T_IF);
    EXPECT_EQ(tokens[1], T_THEN);
    EXPECT_EQ(tokens[2], T_ELSE);
    EXPECT_EQ(tokens[3], T_WHILE);
    EXPECT_EQ(tokens[4], T_DO);
    EXPECT_EQ(tokens[5], T_FOR);
    EXPECT_EQ(tokens[6], T_TO);
    EXPECT_EQ(tokens[7], T_DOWNTO);
    EXPECT_EQ(tokens[8], T_REPEAT);
    EXPECT_EQ(tokens[9], T_UNTIL);
    EXPECT_EQ(tokens[10], T_CASE);
    EXPECT_EQ(tokens[11], T_OF);
}

// 测试数据类型关键字
TEST_F(PascalLexerTest, TestTypeKeywords) {
    std::string input = "const type array record integer real boolean string char";
    auto tokens = scanTokens(input);
    
    ASSERT_EQ(tokens.size(), 9);
    EXPECT_EQ(tokens[0], T_CONST);
    EXPECT_EQ(tokens[1], T_TYPE);
    EXPECT_EQ(tokens[2], T_ARRAY);
    EXPECT_EQ(tokens[3], T_RECORD);
    // 剩下的是类型标识符
    for (int i = 4; i < 9; i++) {
        EXPECT_EQ(tokens[i], T_TYPE_ID);
    }
}

// 测试运算符
TEST_F(PascalLexerTest, TestOperators) {
    std::string input = ":= + - * / = <> < <= > >= div mod and or not";
    auto tokens = scanTokens(input);
    
    ASSERT_EQ(tokens.size(), 16);
    EXPECT_EQ(tokens[0], T_ASSIGN);
    EXPECT_EQ(tokens[1], T_PLUS);
    EXPECT_EQ(tokens[2], T_MINUS);
    EXPECT_EQ(tokens[3], T_MULTIPLY);
    EXPECT_EQ(tokens[4], T_DIVIDE);
    EXPECT_EQ(tokens[5], T_EQUAL);
    EXPECT_EQ(tokens[6], T_NOT_EQUAL);
    EXPECT_EQ(tokens[7], T_LESS);
    EXPECT_EQ(tokens[8], T_LESS_EQUAL);
    EXPECT_EQ(tokens[9], T_GREATER);
    EXPECT_EQ(tokens[10], T_GREATER_EQUAL);
    EXPECT_EQ(tokens[11], T_DIV);
    EXPECT_EQ(tokens[12], T_MOD);
    EXPECT_EQ(tokens[13], T_AND);
    EXPECT_EQ(tokens[14], T_OR);
    EXPECT_EQ(tokens[15], T_NOT);
}

// 测试标点符号
TEST_F(PascalLexerTest, TestPunctuation) {
    std::string input = "( ) [ ] : ; , . ..";
    auto tokens = scanTokens(input);
    
    ASSERT_EQ(tokens.size(), 9);
    EXPECT_EQ(tokens[0], T_LPAREN);
    EXPECT_EQ(tokens[1], T_RPAREN);
    EXPECT_EQ(tokens[2], T_LBRACKET);
    EXPECT_EQ(tokens[3], T_RBRACKET);
    EXPECT_EQ(tokens[4], T_COLON);
    EXPECT_EQ(tokens[5], T_SEMICOLON);
    EXPECT_EQ(tokens[6], T_COMMA);
    EXPECT_EQ(tokens[7], T_DOT);
    EXPECT_EQ(tokens[8], T_DOTDOT);
}

// 测试标识符
TEST_F(PascalLexerTest, TestIdentifiers) {
    std::string input = "identifier x123 _abc a_b_c";
    auto tokens = scanTokens(input);
    
    // 注意：根据Pascal词法规则，标识符不能以下划线开头，所以_abc不是有效标识符
    ASSERT_EQ(tokens.size(), 3); 
    EXPECT_EQ(tokens[0], T_IDENTIFIER);
    EXPECT_EQ(tokens[1], T_IDENTIFIER);
    EXPECT_EQ(tokens[2], T_IDENTIFIER);
}

// 测试常量
TEST_F(PascalLexerTest, TestConstants) {
    std::string input = "123 456.789 'Hello, World!' true false";
    auto tokens = scanTokens(input);
    
    ASSERT_EQ(tokens.size(), 5);
    EXPECT_EQ(tokens[0], T_INT_CONST);
    EXPECT_EQ(tokens[1], T_REAL_CONST);
    EXPECT_EQ(tokens[2], T_STRING_CONST);
    EXPECT_EQ(tokens[3], T_BOOL_CONST);
    EXPECT_EQ(tokens[4], T_BOOL_CONST);
}

// 测试注释忽略
TEST_F(PascalLexerTest, TestComments) {
    std::string input = "program { This is a comment } begin (* This is another comment *) end.";
    auto tokens = scanTokens(input);
    
    ASSERT_EQ(tokens.size(), 4);
    EXPECT_EQ(tokens[0], T_PROGRAM);
    EXPECT_EQ(tokens[1], T_BEGIN);
    EXPECT_EQ(tokens[2], T_END);
    EXPECT_EQ(tokens[3], T_DOT);
}

// 测试完整的简单程序
TEST_F(PascalLexerTest, TestSimpleProgram) {
    std::string input = 
        "program HelloWorld;\n"
        "var\n"
        "    i, sum: integer;\n"
        "    greeting: string;\n"
        "    isRunning: boolean;\n"
        "\n"
        "begin\n"
        "    greeting := 'Hello, World!';\n"
        "end.";
    
    auto tokens = scanTokens(input);
    
    ASSERT_GT(tokens.size(), 0);
    EXPECT_EQ(tokens[0], T_PROGRAM);
    EXPECT_EQ(tokens[1], T_IDENTIFIER); // HelloWorld
    EXPECT_EQ(tokens[2], T_SEMICOLON);
    EXPECT_EQ(tokens[3], T_VAR);
    // ... 以此类推，可以验证所有预期的标记
}

// 测试数字的边界情况
TEST_F(PascalLexerTest, TestNumberEdgeCases) {
    std::string input = "0 12345 0.0 3.14159 1.2e3 1.2e-3 1.2e+3";
    auto tokens = scanTokens(input);
    
    ASSERT_EQ(tokens.size(), 7);
    EXPECT_EQ(tokens[0], T_INT_CONST);
    EXPECT_EQ(tokens[1], T_INT_CONST);
    EXPECT_EQ(tokens[2], T_REAL_CONST);
    EXPECT_EQ(tokens[3], T_REAL_CONST);
    EXPECT_EQ(tokens[4], T_REAL_CONST);
    EXPECT_EQ(tokens[5], T_REAL_CONST);
    EXPECT_EQ(tokens[6], T_REAL_CONST);
}

// 测试字符串的边界情况，包括引号转义
TEST_F(PascalLexerTest, TestStringEdgeCases) {
    std::string input = "'Simple string' '' 'String with ''quoted'' text'";
    auto tokens = scanTokens(input);
    
    ASSERT_EQ(tokens.size(), 3);
    EXPECT_EQ(tokens[0], T_STRING_CONST);
    EXPECT_EQ(tokens[1], T_STRING_CONST);
    EXPECT_EQ(tokens[2], T_STRING_CONST);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 