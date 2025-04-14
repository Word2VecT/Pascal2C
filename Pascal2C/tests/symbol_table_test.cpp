#include "../include/symbol_table.h"

#include <gtest/gtest.h>

// Test fixture for SymbolTable tests
class SymbolTableTest : public ::testing::Test {
protected:
    SymbolTable symbolTable;

    // Set up before each test
    void SetUp() override {
        // Start with a fresh symbol table
        symbolTable = SymbolTable();
    }
};

// Test adding a symbol
TEST_F(SymbolTableTest, AddSymbol) {
    // Add a variable symbol
    SymbolInfo info(SymbolType::VARIABLE, "integer");
    EXPECT_TRUE(symbolTable.addSymbol("x", info));

    // Verify symbol exists
    EXPECT_TRUE(symbolTable.symbolExists("x"));

    // Add another symbol with the same name (should fail)
    SymbolInfo info2(SymbolType::VARIABLE, "real");
    EXPECT_FALSE(symbolTable.addSymbol("x", info2));
}

// Test symbol lookup
TEST_F(SymbolTableTest, SymbolLookup) {
    // Add a variable symbol
    SymbolInfo info(SymbolType::VARIABLE, "integer");
    symbolTable.addSymbol("x", info);

    // Lookup existing symbol
    SymbolInfo* retrievedInfo = symbolTable.getSymbolInfo("x");
    ASSERT_NE(retrievedInfo, nullptr);
    EXPECT_EQ(retrievedInfo->type, SymbolType::VARIABLE);
    EXPECT_EQ(retrievedInfo->dataType, "integer");
    EXPECT_FALSE(retrievedInfo->isParameter);

    // Lookup non-existent symbol
    EXPECT_EQ(symbolTable.getSymbolInfo("y"), nullptr);
}

// Test scoping
TEST_F(SymbolTableTest, Scoping) {
    // Add symbol in global scope
    SymbolInfo globalVar(SymbolType::VARIABLE, "integer");
    symbolTable.addSymbol("x", globalVar);

    // Enter new scope
    symbolTable.enterScope();

    // Add symbol with same name in local scope
    SymbolInfo localVar(SymbolType::VARIABLE, "real");
    EXPECT_TRUE(symbolTable.addSymbol("x", localVar));

    // Check local symbol overrides global
    SymbolInfo* info = symbolTable.getSymbolInfo("x");
    ASSERT_NE(info, nullptr);
    EXPECT_EQ(info->dataType, "real");

    // Exit scope
    symbolTable.exitScope();

    // Check global symbol is accessible again
    info = symbolTable.getSymbolInfo("x");
    ASSERT_NE(info, nullptr);
    EXPECT_EQ(info->dataType, "integer");
}

// Test parameters
TEST_F(SymbolTableTest, Parameters) {
    // Add parameter symbol
    SymbolInfo param(SymbolType::VARIABLE, "integer", true);
    symbolTable.addSymbol("param", param);

    // Verify parameter flag
    SymbolInfo* info = symbolTable.getSymbolInfo("param");
    ASSERT_NE(info, nullptr);
    EXPECT_TRUE(info->isParameter);
}

// Test function and procedure symbols
TEST_F(SymbolTableTest, FunctionProcedure) {
    // Add function symbol
    SymbolInfo func(SymbolType::FUNCTION, "integer");
    symbolTable.addSymbol("calc", func);

    // Verify function type
    SymbolInfo* info = symbolTable.getSymbolInfo("calc");
    ASSERT_NE(info, nullptr);
    EXPECT_EQ(info->type, SymbolType::FUNCTION);

    // Add procedure symbol
    SymbolInfo proc(SymbolType::PROCEDURE, "");
    symbolTable.addSymbol("display", proc);

    // Verify procedure type
    info = symbolTable.getSymbolInfo("display");
    ASSERT_NE(info, nullptr);
    EXPECT_EQ(info->type, SymbolType::PROCEDURE);
}

// Run all tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}