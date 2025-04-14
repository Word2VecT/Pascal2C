# Set flex and bison outputs
FLEX_TARGET(Scanner ${CMAKE_CURRENT_SOURCE_DIR}/pascal_lexer.l ${CMAKE_CURRENT_SOURCE_DIR}/pascal_lexer.cpp)
BISON_TARGET(Parser ${CMAKE_CURRENT_SOURCE_DIR}/pascal_parser.y 
             ${CMAKE_CURRENT_SOURCE_DIR}/pascal_parser.cpp 
             DEFINES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/pascal_parser.h)
ADD_FLEX_BISON_DEPENDENCY(Scanner Parser)

# Source files (excluding main.cpp)
set(LIB_SOURCES
    ${FLEX_Scanner_OUTPUTS}
    ${BISON_Parser_OUTPUTS}
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

# Create library for testing
add_library(Pascal2C_lib STATIC ${LIB_SOURCES} ${HEADERS})

# Generate executable
add_executable(pascal2c main.cpp)
target_link_libraries(pascal2c Pascal2C_lib)

# Install target
install(TARGETS pascal2c DESTINATION bin) 