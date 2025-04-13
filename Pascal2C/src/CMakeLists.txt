# Set flex and bison outputs
FLEX_TARGET(Scanner ${CMAKE_CURRENT_SOURCE_DIR}/pascal_lexer.l ${CMAKE_CURRENT_SOURCE_DIR}/pascal_lexer.cpp)
BISON_TARGET(Parser ${CMAKE_CURRENT_SOURCE_DIR}/pascal_parser.y ${CMAKE_CURRENT_SOURCE_DIR}/pascal_parser.cpp)
ADD_FLEX_BISON_DEPENDENCY(Scanner Parser)

# Source files
set(SOURCES
    ${FLEX_Scanner_OUTPUTS}
    ${BISON_Parser_OUTPUTS}
    main.cpp
    ast.cpp
    code_generator.cpp
    symbol_table.cpp
)

# Include headers
set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/../include/ast.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../include/code_generator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../include/symbol_table.h
)

# Generate executable
add_executable(pascal2c ${SOURCES} ${HEADERS})

# Link with system libraries
target_link_libraries(pascal2c)

# Install target
install(TARGETS pascal2c DESTINATION bin) 