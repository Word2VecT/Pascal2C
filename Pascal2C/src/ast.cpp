#include "../include/ast.h"
#include "../include/code_generator.h"

// ProgramNode implementation
void ProgramNode::generate(CodeGenerator& generator) const {
    generator.generate(*this);
}

// VarDeclNode implementation
void VarDeclNode::generate(CodeGenerator& generator) const {
    generator.generate(*this);
}

// BinaryOpNode implementation
void BinaryOpNode::generate(CodeGenerator& generator) const {
    generator.generate(*this);
}

// IdentifierNode implementation
void IdentifierNode::generate(CodeGenerator& generator) const {
    generator.generate(*this);
}

// LiteralNode implementation
void LiteralNode::generate(CodeGenerator& generator) const {
    generator.generate(*this);
}

// AssignNode implementation
void AssignNode::generate(CodeGenerator& generator) const {
    generator.generate(*this);
}

// IfNode implementation
void IfNode::generate(CodeGenerator& generator) const {
    generator.generate(*this);
}

// WhileNode implementation
void WhileNode::generate(CodeGenerator& generator) const {
    generator.generate(*this);
}

// ProcCallNode implementation
void ProcCallNode::generate(CodeGenerator& generator) const {
    generator.generate(*this);
} 