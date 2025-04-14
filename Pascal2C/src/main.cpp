#include "../include/ast.h"
#include "../include/code_generator.h"
#include "pascal_lexer.h"
#include "pascal_parser.h"
#include <iostream>
#include <string>
#include <cstring>

// 声明外部变量
extern std::unique_ptr<ProgramNode> programRoot;
extern FILE* yyin;

void printUsage(const char* programName) {
    std::cerr << "Usage: " << programName << " -i <input_file>" << std::endl;
    std::cerr << "  -i <input_file>:  Path to the Pascal source code file" << std::endl;
    std::cerr << "  Output will be saved as <input_file>.c in the current directory" << std::endl;
}

// 从路径中提取文件名并更改扩展名为.c
std::string generateOutputFilename(const std::string& inputPath) {
    // 提取文件名（不含路径）
    size_t lastSlash = inputPath.find_last_of("/\\");
    std::string filename = (lastSlash != std::string::npos) ? 
                           inputPath.substr(lastSlash + 1) : inputPath;
    
    // 移除原扩展名并添加.c
    size_t dot = filename.find_last_of(".");
    if (dot != std::string::npos) {
        filename = filename.substr(0, dot);
    }
    
    return filename + ".c";
}

int main(int argc, char* argv[]) {
    // 检查命令行参数
    if (argc < 3) {
        printUsage(argv[0]);
        return 1;
    }
    
    // 解析命令行参数
    std::string inputFile;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
            inputFile = argv[i + 1];
            i++;  // 跳过下一个参数
        }
    }
    
    if (inputFile.empty()) {
        std::cerr << "Error: No input file specified" << std::endl;
        printUsage(argv[0]);
        return 1;
    }
    
    // 生成输出文件名
    std::string outputFile = generateOutputFilename(inputFile);
    
    // 打开输入文件
    yyin = fopen(inputFile.c_str(), "r");
    if (!yyin) {
        std::cerr << "Error: Cannot open input file " << inputFile << std::endl;
        return 1;
    }
    
    // 解析输入文件
    std::cout << "Parsing " << inputFile << "..." << std::endl;
    int parseResult = yyparse();
    fclose(yyin);
    
    // 检查解析结果
    if (parseResult != 0 || !programRoot) {
        std::cerr << "Error: Parsing failed" << std::endl;
        return 1;
    }
    
    // 生成代码
    std::cout << "Generating C code to " << outputFile << "..." << std::endl;
    try {
        CodeGenerator generator(outputFile.c_str());
        programRoot->generate(generator);
        generator.finalize();
        std::cout << "Code generation completed successfully" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error during code generation: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
} 