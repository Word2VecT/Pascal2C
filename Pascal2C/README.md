# Pascal2C

一个将Pascal代码转换为C语言的编译器，使用flex和bison实现。

## 项目结构

```
.
├── CMakeLists.txt        # 主CMake文件
├── src/                  # 源代码目录
│   ├── CMakeLists.txt    # 源代码CMake文件
│   ├── main.cpp          # 主程序入口
│   ├── ast.cpp           # 抽象语法树实现
│   ├── code_generator.cpp # 代码生成器实现
│   ├── symbol_table.cpp  # 符号表实现
│   ├── pascal_lexer.l    # flex词法分析器定义
│   └── pascal_parser.y   # bison语法分析器定义
├── include/              # 头文件目录
│   ├── ast.h             # 抽象语法树头文件
│   ├── code_generator.h  # 代码生成器头文件
│   └── symbol_table.h    # 符号表头文件
├── examples/             # 示例Pascal代码
│   └── hello.pas         # 示例Hello World程序
└── tests/                # 测试目录
```

## 依赖项

- C++17兼容的编译器（如GCC或Clang）
- flex (Fast Lexical Analyzer)
- bison (GNU Parser Generator)
- CMake 3.10或更高版本

## 编译方法

1. 创建并进入构建目录：

```bash
mkdir build
cd build
```

2. 配置并编译项目：

```bash
cmake ..
make
```

3. 可选：运行测试（如果启用）：

```bash
cmake -DBUILD_TESTS=ON ..
make
```

## 使用方法

```bash
./pascal2c <输入文件> <输出文件>
```

例如：

```bash
./pascal2c ../examples/hello.pas hello.c
```

## 支持的Pascal功能

- 基本数据类型（integer、real、boolean、string）
- 变量声明和赋值
- 算术、逻辑和关系运算
- 控制结构（if-then-else、while-do）
- 简单过程调用

## 限制

当前版本有一些限制：

- 不支持函数定义
- 不支持复杂的数据结构（记录、数组等）
- 不支持完整的模块系统
- 不支持一些Pascal特定的语言特性

updateing...
