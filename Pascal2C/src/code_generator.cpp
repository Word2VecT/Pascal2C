#include "code_generator.h"
#include "ast.h"
#include <iostream>

CodeGenerator::CodeGenerator(const std::string& outputFilename)
    : outputFile(outputFilename), indentLevel(0), isInFunctionBody(false) {
    // 添加标准头文件
    headerStream << "#include <stdio.h>\n";
    headerStream << "#include <stdlib.h>\n";
    headerStream << "#include <stdbool.h>\n";
    headerStream << "#include <string.h>\n\n";
}

CodeGenerator::~CodeGenerator() {
    if (outputFile.is_open()) {
        outputFile.close();
    }
}

std::string CodeGenerator::getIndent() {
    return std::string(indentLevel * 4, ' ');
}

void CodeGenerator::increaseIndent() {
    indentLevel++;
}

void CodeGenerator::decreaseIndent() {
    if (indentLevel > 0) {
        indentLevel--;
    }
}

std::string CodeGenerator::pascalToCType(const std::string& pascalType) {
    if (pascalType == "integer") {
        return "int";
    } else if (pascalType == "real") {
        return "double";
    } else if (pascalType == "boolean") {
        return "bool";
    } else if (pascalType == "string") {
        return "char*";
    } else if (pascalType == "char") {
        return "char";
    } else {
        // 未知类型，默认为void
        return "void";
    }
}

void CodeGenerator::generate(const ProgramNode& node) {
    // 生成程序头部
    codeStream << "/* Program " << node.getName() << " */\n\n";
    
    // 添加所有变量声明到头部
    codeStream << "// Global variable declarations\n";
    
    // 生成声明部分
    for (const auto& decl : node.getDeclarations()) {
        if (decl) {  // 确保声明节点不为空
            decl->generate(*this);
        }
    }
    
    codeStream << "\n";
    
    // 生成主函数
    codeStream << "int main() {\n";
    
    // 标记我们现在在函数体内
    isInFunctionBody = true;
    increaseIndent();
    
    // 生成语句
    for (const auto& stmt : node.getStatements()) {
        if (stmt) {  // 确保语句节点不为空
            codeStream << getIndent();
            stmt->generate(*this);
            codeStream << ";\n";
        }
    }
    
    // 生成返回语句
    codeStream << getIndent() << "return 0;\n";
    decreaseIndent();
    isInFunctionBody = false;
    codeStream << "}\n";
}

void CodeGenerator::generate(const VarDeclNode& node) {
    // 将Pascal类型转换为C类型
    std::string cType = pascalToCType(node.getType());
    
    // 生成变量声明
    for (const auto& var : node.getVars()) {
        if (isInFunctionBody) {
            codeStream << getIndent() << cType << " " << var << ";\n";
        } else {
            // 全局变量
            headerStream << cType << " " << var << ";\n";
        }
    }
}

void CodeGenerator::generate(const BinaryOpNode& node) {
    codeStream << "(";
    node.getLeft()->generate(*this);
    
    // 转换操作符
    switch (node.getOp()) {
        case BinaryOpNode::PLUS:
            codeStream << " + ";
            break;
        case BinaryOpNode::MINUS:
            codeStream << " - ";
            break;
        case BinaryOpNode::MULTIPLY:
            codeStream << " * ";
            break;
        case BinaryOpNode::DIVIDE:
            codeStream << " / ";
            break;
        case BinaryOpNode::EQUAL:
            codeStream << " == ";
            break;
        case BinaryOpNode::NOT_EQUAL:
            codeStream << " != ";
            break;
        case BinaryOpNode::LESS:
            codeStream << " < ";
            break;
        case BinaryOpNode::LESS_EQUAL:
            codeStream << " <= ";
            break;
        case BinaryOpNode::GREATER:
            codeStream << " > ";
            break;
        case BinaryOpNode::GREATER_EQUAL:
            codeStream << " >= ";
            break;
        case BinaryOpNode::AND:
            codeStream << " && ";
            break;
        case BinaryOpNode::OR:
            codeStream << " || ";
            break;
    }
    
    node.getRight()->generate(*this);
    codeStream << ")";
}

void CodeGenerator::generate(const IdentifierNode& node) {
    codeStream << node.getName();
}

void CodeGenerator::generate(const LiteralNode& node) {
    switch (node.getType()) {
        case LiteralNode::INTEGER:
        case LiteralNode::REAL:
            codeStream << node.getValue();
            break;
        case LiteralNode::STRING:
            codeStream << "\"" << node.getValue() << "\"";
            break;
        case LiteralNode::BOOLEAN:
            codeStream << node.getValue();
            break;
    }
}

void CodeGenerator::generate(const AssignNode& node) {
    codeStream << node.getVariable() << " = ";
    node.getExpression()->generate(*this);
}

void CodeGenerator::generate(const IfNode& node) {
    codeStream << "if (";
    node.getCondition()->generate(*this);
    codeStream << ") {\n";
    
    increaseIndent();
    for (const auto& stmt : node.getThenStatements()) {
        codeStream << getIndent();
        stmt->generate(*this);
        codeStream << ";\n";
    }
    decreaseIndent();
    
    codeStream << getIndent() << "}";
    
    // 如果有else部分
    if (!node.getElseStatements().empty()) {
        codeStream << " else {\n";
        
        increaseIndent();
        for (const auto& stmt : node.getElseStatements()) {
            codeStream << getIndent();
            stmt->generate(*this);
            codeStream << ";\n";
        }
        decreaseIndent();
        
        codeStream << getIndent() << "}";
    }
}

void CodeGenerator::generate(const WhileNode& node) {
    codeStream << "while (";
    node.getCondition()->generate(*this);
    codeStream << ") {\n";
    
    increaseIndent();
    for (const auto& stmt : node.getStatements()) {
        codeStream << getIndent();
        stmt->generate(*this);
        codeStream << ";\n";
    }
    decreaseIndent();
    
    codeStream << getIndent() << "}";
}

void CodeGenerator::generate(const ProcCallNode& node) {
    const std::string& name = node.getName();
    
    // 处理Pascal标准库函数
    if (name == "writeln") {
        codeStream << "printf(";
        
        // 处理参数
        const auto& args = node.getArguments();
        if (args.empty()) {
            // 无参数的writeln
            codeStream << "\"\\n\"";
        } else {
            // 第一个参数
            if (dynamic_cast<const LiteralNode*>(args[0].get()) && 
                dynamic_cast<const LiteralNode*>(args[0].get())->getType() == LiteralNode::STRING) {
                // 字符串字面量需要添加格式说明符
                codeStream << "\"";
                args[0]->generate(*this);
                
                // 对于额外的参数，添加格式说明符
                if (args.size() > 1) {
                    codeStream << " %d";
                }
                codeStream << "\\n\"";
                
                // 添加额外的参数
                for (size_t i = 1; i < args.size(); i++) {
                    codeStream << ", ";
                    args[i]->generate(*this);
                }
            } else {
                // 非字符串的第一个参数
                codeStream << "\"%d\\n\", ";
                args[0]->generate(*this);
            }
        }
        
        codeStream << ")";
    } else {
        // 其他函数调用
        codeStream << name << "(";
        
        // 处理参数列表
        const auto& args = node.getArguments();
        for (size_t i = 0; i < args.size(); i++) {
            if (i > 0) {
                codeStream << ", ";
            }
            args[i]->generate(*this);
        }
        
        codeStream << ")";
    }
}

void CodeGenerator::finalize() {
    // 将头文件和代码合并到输出文件
    outputFile << headerStream.str() << codeStream.str();
} 