cmake_minimum_required(VERSION 3.10)

# Enable testing
enable_testing()

# Add test executable
add_executable(symbol_table_test symbol_table_test.cpp)

# Add pascal_lexer_test
add_executable(pascal_lexer_test pascal_lexer_test.cpp)

# Add pascal_parser_test
add_executable(pascal_parser_test pascal_parser_test.cpp)

# Add code_generator_test
add_executable(code_generator_test code_generator_test.cpp)

# Link against Google Test and other project libraries
target_link_libraries(symbol_table_test 
    PRIVATE
    GTest::GTest
    GTest::Main
    pthread
    Pascal2C_lib
)

# Link for pascal_lexer_test
target_link_libraries(pascal_lexer_test
    PRIVATE
    GTest::GTest
    GTest::Main
    pthread
    Pascal2C_lib
)

# Link for pascal_parser_test
target_link_libraries(pascal_parser_test
    PRIVATE
    GTest::GTest
    GTest::Main
    pthread
    Pascal2C_lib
)

# Link for code_generator_test
target_link_libraries(code_generator_test
    PRIVATE
    GTest::GTest
    GTest::Main
    pthread
    Pascal2C_lib
)

# Add tests to CTest
add_test(NAME SymbolTableTests COMMAND symbol_table_test) 
add_test(NAME PascalLexerTests COMMAND pascal_lexer_test) 
add_test(NAME PascalParserTests COMMAND pascal_parser_test) 
add_test(NAME CodeGeneratorTests COMMAND code_generator_test) 