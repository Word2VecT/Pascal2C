#ifndef AST_H
#define AST_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Forward declarations
class CodeGenerator;

// AST Node base class
class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual void generate(CodeGenerator& generator) const = 0;
};

// Program node (root of the AST)
class ProgramNode : public ASTNode {
private:
    std::string name;
    std::vector<std::unique_ptr<ASTNode>> declarations;
    std::vector<std::unique_ptr<ASTNode>> statements;

public:
    ProgramNode(const std::string& name) : name(name) {}
    
    void addDeclaration(std::unique_ptr<ASTNode> decl) {
        declarations.push_back(std::move(decl));
    }
    
    void addStatement(std::unique_ptr<ASTNode> stmt) {
        statements.push_back(std::move(stmt));
    }
    
    const std::string& getName() const { return name; }
    const std::vector<std::unique_ptr<ASTNode>>& getDeclarations() const { return declarations; }
    const std::vector<std::unique_ptr<ASTNode>>& getStatements() const { return statements; }
    
    void generate(CodeGenerator& generator) const override;
};

// Variable declaration node
class VarDeclNode : public ASTNode {
private:
    std::string type;
    std::vector<std::string> vars;

public:
    VarDeclNode(const std::string& type, const std::vector<std::string>& vars)
        : type(type), vars(vars) {}
        
    const std::string& getType() const { return type; }
    const std::vector<std::string>& getVars() const { return vars; }
    
    void generate(CodeGenerator& generator) const override;
};

// Binary operation node
class BinaryOpNode : public ASTNode {
public:
    enum Op { 
        PLUS, MINUS, MULTIPLY, DIVIDE, EQUAL, NOT_EQUAL, 
        LESS, LESS_EQUAL, GREATER, GREATER_EQUAL, AND, OR 
    };
    
private:
    Op op;
    std::unique_ptr<ASTNode> left;
    std::unique_ptr<ASTNode> right;
    
public:
    BinaryOpNode(Op op, std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right)
        : op(op), left(std::move(left)), right(std::move(right)) {}
        
    Op getOp() const { return op; }
    const ASTNode* getLeft() const { return left.get(); }
    const ASTNode* getRight() const { return right.get(); }
    
    void generate(CodeGenerator& generator) const override;
};

// Identifier node
class IdentifierNode : public ASTNode {
private:
    std::string name;
    
public:
    IdentifierNode(const std::string& name) : name(name) {}
    
    const std::string& getName() const { return name; }
    
    void generate(CodeGenerator& generator) const override;
};

// Literal value node
class LiteralNode : public ASTNode {
public:
    enum Type { INTEGER, REAL, STRING, BOOLEAN };
    
private:
    Type type;
    std::string value;
    
public:
    LiteralNode(Type type, const std::string& value) : type(type), value(value) {}
    
    Type getType() const { return type; }
    const std::string& getValue() const { return value; }
    
    void generate(CodeGenerator& generator) const override;
};

// Assignment statement node
class AssignNode : public ASTNode {
private:
    std::string variable;
    std::unique_ptr<ASTNode> expression;
    
public:
    AssignNode(const std::string& variable, std::unique_ptr<ASTNode> expression)
        : variable(variable), expression(std::move(expression)) {}
        
    const std::string& getVariable() const { return variable; }
    const ASTNode* getExpression() const { return expression.get(); }
    
    void generate(CodeGenerator& generator) const override;
};

// If statement node
class IfNode : public ASTNode {
private:
    std::unique_ptr<ASTNode> condition;
    std::vector<std::unique_ptr<ASTNode>> thenStmts;
    std::vector<std::unique_ptr<ASTNode>> elseStmts;
    
public:
    IfNode(std::unique_ptr<ASTNode> condition) : condition(std::move(condition)) {}
    
    void addThenStatement(std::unique_ptr<ASTNode> stmt) {
        thenStmts.push_back(std::move(stmt));
    }
    
    void addElseStatement(std::unique_ptr<ASTNode> stmt) {
        elseStmts.push_back(std::move(stmt));
    }
    
    const ASTNode* getCondition() const { return condition.get(); }
    const std::vector<std::unique_ptr<ASTNode>>& getThenStatements() const { return thenStmts; }
    const std::vector<std::unique_ptr<ASTNode>>& getElseStatements() const { return elseStmts; }
    
    void generate(CodeGenerator& generator) const override;
};

// While statement node
class WhileNode : public ASTNode {
private:
    std::unique_ptr<ASTNode> condition;
    std::vector<std::unique_ptr<ASTNode>> statements;
    
public:
    WhileNode(std::unique_ptr<ASTNode> condition) : condition(std::move(condition)) {}
    
    void addStatement(std::unique_ptr<ASTNode> stmt) {
        statements.push_back(std::move(stmt));
    }
    
    const ASTNode* getCondition() const { return condition.get(); }
    const std::vector<std::unique_ptr<ASTNode>>& getStatements() const { return statements; }
    
    void generate(CodeGenerator& generator) const override;
};

// Procedure call node
class ProcCallNode : public ASTNode {
private:
    std::string name;
    std::vector<std::unique_ptr<ASTNode>> args;
    
public:
    ProcCallNode(const std::string& name) : name(name) {}
    
    void addArgument(std::unique_ptr<ASTNode> arg) {
        args.push_back(std::move(arg));
    }
    
    const std::string& getName() const { return name; }
    const std::vector<std::unique_ptr<ASTNode>>& getArguments() const { return args; }
    
    void generate(CodeGenerator& generator) const override;
};

#endif // AST_H 