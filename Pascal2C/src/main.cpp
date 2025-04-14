#include "../include/ast.h"
#include "../include/code_generator.h"
#include "pascal_lexer.h"
#include "pascal_parser.h"
#include <iostream>

// 声明外部变量
extern std::unique_ptr<ProgramNode> programRoot;
extern FILE* yyin;

void printUsage(const char* programName) {
    std::cerr << "Usage: " << programName << " <input_file> <output_file>" << std::endl;
    std::cerr << "  input_file:  Path to the Pascal source code file" << std::endl;
    std::cerr << "  output_file: Path to the output C file" << std::endl;
}

int main(int argc, char* argv[]) {
    // 检查命令行参数
    if (argc < 3) {
        printUsage(argv[0]);
        return 1;
    }
    
    // 打开输入文件
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        std::cerr << "Error: Cannot open input file " << argv[1] << std::endl;
        return 1;
    }
    
    // 解析输入文件
    std::cout << "Parsing " << argv[1] << "..." << std::endl;
    int parseResult = yyparse();
    fclose(yyin);
    
    // 检查解析结果
    if (parseResult != 0 || !programRoot) {
        std::cerr << "Error: Parsing failed" << std::endl;
        return 1;
    }
    
    // 生成代码
    std::cout << "Generating C code to " << argv[2] << "..." << std::endl;
    try {
        CodeGenerator generator(argv[2]);
        programRoot->generate(generator);
        generator.finalize();
        std::cout << "Code generation completed successfully" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error during code generation: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
} 