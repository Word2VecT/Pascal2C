#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include "symbol_table.h"

// Forward declarations
class ASTNode;
class ProgramNode;
class VarDeclNode;
class BinaryOpNode;
class IdentifierNode;
class LiteralNode;
class AssignNode;
class IfNode;
class WhileNode;
class ProcCallNode;

class CodeGenerator {
private:
    std::ofstream outputFile;
    SymbolTable symbolTable;
    std::stringstream headerStream;
    std::stringstream codeStream;
    int indentLevel;
    bool isInFunctionBody;
    
    // Helper methods
    std::string getIndent();
    void increaseIndent();
    void decreaseIndent();
    std::string pascalToCType(const std::string& pascalType);
    
public:
    CodeGenerator(const std::string& outputFilename);
    ~CodeGenerator();
    
    // Generate code for each node type
    void generate(const ProgramNode& node);
    void generate(const VarDeclNode& node);
    void generate(const BinaryOpNode& node);
    void generate(const IdentifierNode& node);
    void generate(const LiteralNode& node);
    void generate(const AssignNode& node);
    void generate(const IfNode& node);
    void generate(const WhileNode& node);
    void generate(const ProcCallNode& node);
    
    // Finalize and write the complete C program to file
    void finalize();
};

#endif // CODE_GENERATOR_H 