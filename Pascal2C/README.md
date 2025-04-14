# Pascal2C

一个将Pascal代码转换为C语言的编译器，使用flex和bison实现。

A compiler that converts Pascal code to C, implemented using flex and bison.

## 成员分工 (Team Members)

- 成润东：词法分析 (Lexical Analysis)
- 吕志杰：语法分析 (Syntax Analysis)
- 唐梓楠：代码生成与测试 (Code Generation and Testing)
- 连琎宇：符号表 (Symbol Table)

## 项目结构 (Project Structure)

```
.
├── CMakeLists.txt        # 主CMake文件 (Main CMake file)
├── src/                  # 源代码目录 (Source code directory)
│   ├── CMakeLists.txt    # 源代码CMake文件 (Source CMake file)
│   ├── main.cpp          # 主程序入口 (Main program entry)
│   ├── ast.cpp           # 抽象语法树实现 (AST implementation)
│   ├── code_generator.cpp # 代码生成器实现 (Code generator implementation)
│   ├── symbol_table.cpp  # 符号表实现 (Symbol table implementation)
│   ├── pascal_lexer.l    # flex词法分析器定义 (Flex lexer definition)
│   └── pascal_parser.y   # bison语法分析器定义 (Bison parser definition)
├── include/              # 头文件目录 (Header files directory)
│   ├── ast.h             # 抽象语法树头文件 (AST header)
│   ├── code_generator.h  # 代码生成器头文件 (Code generator header)
│   └── symbol_table.h    # 符号表头文件 (Symbol table header)
├── examples/             # 示例Pascal代码 (Example Pascal code)
│   └── hello.pas         # 示例Hello World程序 (Example Hello World program)
└── tests/                # 测试目录 (Test directory)
```

## 技术实现 (Technical Implementation)

本项目基于以下编译原理实现步骤：

1. **词法分析 (Lexical Analysis)**: 使用Flex将Pascal源代码转换为标记流
2. **语法分析 (Syntax Analysis)**: 使用Bison构建抽象语法树(AST)
3. **语义分析 (Semantic Analysis)**: 通过符号表进行类型检查和变量声明验证
4. **代码生成 (Code Generation)**: 将AST转换为等价的C代码

## 依赖项 (Dependencies)

- C++17兼容的编译器（如GCC或Clang）(C++17 compatible compiler like GCC or Clang)
- flex (Fast Lexical Analyzer)
- bison (GNU Parser Generator)
- CMake 3.10或更高版本 (CMake 3.10 or higher)

## 编译方法 (Build Instructions)

1. 创建并进入构建目录 (Create and enter build directory):

```bash
mkdir build
cd build
```

2. 配置并编译项目 (Configure and build project):

```bash
cmake ..
make
```

3. 可选：运行测试（如果启用）(Optional: Run tests if enabled):

```bash
cmake -DBUILD_TESTS=ON ..
make
ctest
```

## 使用方法 (Usage)

```bash
./pascc -i <输入文件.pas>
```

输出文件将保存为当前目录下的同名.c文件。

例如 (Example):

```bash
./pascc -i ../examples/hello.pas
```

这将在当前目录生成 `hello.c` 文件。

## 支持的Pascal功能 (Supported Pascal Features)

- 基本数据类型（integer、real、boolean、string）(Basic data types)
- 变量声明和赋值 (Variable declarations and assignments)
- 算术、逻辑和关系运算 (Arithmetic, logical and relational operations)
- 控制结构（if-then-else、while-do）(Control structures)
- 简单过程调用 (Simple procedure calls)

## 限制 (Limitations)

当前版本有一些限制 (The current version has some limitations):

- 不支持函数定义 (No support for function definitions)
- 不支持复杂的数据结构（记录、数组等）(No support for complex data structures like records, arrays)
- 不支持完整的模块系统 (No support for complete module system)
- 不支持一些Pascal特定的语言特性 (No support for some Pascal-specific language features)

## 开发说明 (Development Notes)

- 词法分析器通过`pascal_lexer.l`定义，处理Pascal源码的标记化
- 语法分析器通过`pascal_parser.y`定义，构建语法树
- 符号表维护变量、类型信息，支持作用域管理
- 代码生成器将Pascal AST节点转换为等价的C代码表示

## 许可证 (License)

本项目用于编译原理课程设计，仅供学习和教育用途。

This project is for Compiler Principles course design, for educational purposes only.
