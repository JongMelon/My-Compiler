# 一个简单的 SysY 编译器
中国人民大学 2024 年春季学期《编译原理》课程大作业

## 文件说明

- `./src/lex.l`：词法分析器
- `./src/syntax.y`：语法分析器
- `./src/AST.h AST.cpp`：抽象语法树
- `./src/ASM.h ASM.cpp`：汇编代码生成
- `./src/tests/`：测试用例
- `./src/run_tests.sh`：自动测试脚本
- `./doc/report.pdf`：实验报告

## 使用说明

### 编译

```bash
cd src
g++ -o sysc AST.cpp ASM.cpp lex.yy.c syntax.tab.c
```

生成 `sysc` 可执行文件。

### 运行

```bash
./sysc output.s input.c
```

将 `input.c` 编译为 `output.s` 汇编代码。
同时生成 `AST.dot` 文件，以使用 `Graphviz` 工具可视化抽象语法树。

### 测试

```bash
./run_tests.sh
```

将 `./src/tests/` 目录下的测试用例编译为汇编代码，并使用 `g++` 编译成可执行文件，将程序输出与标准输出进行比较。
测试结果将输出到 `test_result` 文件。