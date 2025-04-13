#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <map>
#include <vector>

// Symbol types
enum class SymbolType {
    VARIABLE,
    FUNCTION,
    PROCEDURE
};

// Symbol information
struct SymbolInfo {
    SymbolType type;
    std::string dataType;
    bool isParameter;
    
    // 默认构造函数
    SymbolInfo() : type(SymbolType::VARIABLE), dataType(""), isParameter(false) {}
    
    SymbolInfo(SymbolType type, const std::string& dataType, bool isParameter = false)
        : type(type), dataType(dataType), isParameter(isParameter) {}
};

// Scope for symbol table
class Scope {
private:
    std::map<std::string, SymbolInfo> symbols;
    
public:
    bool addSymbol(const std::string& name, const SymbolInfo& info);
    bool symbolExists(const std::string& name) const;
    SymbolInfo* getSymbolInfo(const std::string& name);
    std::vector<std::string> getAllSymbols() const;
};

// Symbol table with nested scopes
class SymbolTable {
private:
    std::vector<Scope> scopes;
    
public:
    SymbolTable();
    
    void enterScope();
    void exitScope();
    
    bool addSymbol(const std::string& name, const SymbolInfo& info);
    bool symbolExists(const std::string& name) const;
    SymbolInfo* getSymbolInfo(const std::string& name);
    
    int getCurrentScopeLevel() const;
};

#endif // SYMBOL_TABLE_H 