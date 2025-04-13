#include "symbol_table.h"

// Scope implementation
bool Scope::addSymbol(const std::string& name, const SymbolInfo& info) {
    // 如果符号已存在，返回false
    if (symbolExists(name)) {
        return false;
    }
    
    // 添加新符号
    symbols[name] = info;
    return true;
}

bool Scope::symbolExists(const std::string& name) const {
    return symbols.find(name) != symbols.end();
}

SymbolInfo* Scope::getSymbolInfo(const std::string& name) {
    if (!symbolExists(name)) {
        return nullptr;
    }
    
    return &symbols[name];
}

std::vector<std::string> Scope::getAllSymbols() const {
    std::vector<std::string> symbolNames;
    for (const auto& pair : symbols) {
        symbolNames.push_back(pair.first);
    }
    return symbolNames;
}

// SymbolTable implementation
SymbolTable::SymbolTable() {
    // 初始化一个全局作用域
    enterScope();
}

void SymbolTable::enterScope() {
    scopes.push_back(Scope());
}

void SymbolTable::exitScope() {
    if (scopes.size() > 1) {
        scopes.pop_back();
    }
}

bool SymbolTable::addSymbol(const std::string& name, const SymbolInfo& info) {
    // 添加到当前作用域
    return scopes.back().addSymbol(name, info);
}

bool SymbolTable::symbolExists(const std::string& name) const {
    // 从当前作用域开始，向上查找符号
    for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
        if (it->symbolExists(name)) {
            return true;
        }
    }
    
    return false;
}

SymbolInfo* SymbolTable::getSymbolInfo(const std::string& name) {
    // 从当前作用域开始，向上查找符号
    for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
        SymbolInfo* info = it->getSymbolInfo(name);
        if (info) {
            return info;
        }
    }
    
    return nullptr;
}

int SymbolTable::getCurrentScopeLevel() const {
    return scopes.size() - 1;
} 