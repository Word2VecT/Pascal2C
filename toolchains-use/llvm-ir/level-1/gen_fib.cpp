#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>

#include <iostream>
#include <map>
#include <memory>
#include <vector>

using namespace llvm;

int main() {
    // 创建LLVM上下文和模块
    LLVMContext context;
    IRBuilder<> builder(context);
    std::unique_ptr<Module> module(new Module("fib_module", context));

    // 为fib函数创建函数类型：int fib(int)
    Type *intType = Type::getInt32Ty(context);
    Type *floatType = Type::getFloatTy(context);
    std::vector<Type *> fibParams(1, intType);
    FunctionType *fibFuncType = FunctionType::get(intType, fibParams, false);
    
    // 创建fib函数
    Function *fibFunc = Function::Create(fibFuncType, Function::ExternalLinkage, "fib", module.get());
    
    // 给fib函数的参数命名
    Function::arg_iterator argIt = fibFunc->arg_begin();
    Argument *n = &*argIt;
    n->setName("n");
    
    // 创建fib函数的基本块
    BasicBlock *entryBB = BasicBlock::Create(context, "entry", fibFunc);
    BasicBlock *case0BB = BasicBlock::Create(context, "case0", fibFunc);
    BasicBlock *case1BB = BasicBlock::Create(context, "case1", fibFunc);
    BasicBlock *recursiveBB = BasicBlock::Create(context, "recursive", fibFunc);
    BasicBlock *resultBB = BasicBlock::Create(context, "result", fibFunc);
    
    // 设置entry块
    builder.SetInsertPoint(entryBB);
    // 声明r变量
    AllocaInst *r = builder.CreateAlloca(intType, nullptr, "r");
    
    // 比较n是否等于0
    Value *cmp0 = builder.CreateICmpEQ(n, ConstantInt::get(intType, 0), "cmp0");
    builder.CreateCondBr(cmp0, case0BB, case1BB);
    
    // 如果n == 0，r = 0
    builder.SetInsertPoint(case0BB);
    builder.CreateStore(ConstantInt::get(intType, 0), r);
    builder.CreateBr(resultBB);
    
    // 如果n == 1，r = 1，否则进入递归计算
    builder.SetInsertPoint(case1BB);
    Value *cmp1 = builder.CreateICmpEQ(n, ConstantInt::get(intType, 1), "cmp1");
    Value *r1 = ConstantInt::get(intType, 1);
    builder.CreateStore(r1, r);
    builder.CreateCondBr(cmp1, resultBB, recursiveBB);
    
    // 递归计算 r = fib(n-1) + fib(n-2)
    builder.SetInsertPoint(recursiveBB);
    
    // 计算n-1
    Value *nMinus1 = builder.CreateSub(n, ConstantInt::get(intType, 1), "n-1");
    // 调用fib(n-1)
    Value *fibNMinus1 = builder.CreateCall(fibFunc, {nMinus1}, "fib.n-1");
    
    // 计算n-2
    Value *nMinus2 = builder.CreateSub(n, ConstantInt::get(intType, 2), "n-2");
    // 调用fib(n-2)
    Value *fibNMinus2 = builder.CreateCall(fibFunc, {nMinus2}, "fib.n-2");
    
    // 计算fib(n-1) + fib(n-2)
    Value *sum = builder.CreateAdd(fibNMinus1, fibNMinus2, "sum");
    builder.CreateStore(sum, r);
    builder.CreateBr(resultBB);
    
    // 设置最终返回块
    builder.SetInsertPoint(resultBB);
    // 加载r变量并返回
    Value *result = builder.CreateLoad(intType, r, "result");
    builder.CreateRet(result);
    
    // 创建main函数
    FunctionType *mainFuncType = FunctionType::get(intType, {}, false);
    Function *mainFunc = Function::Create(mainFuncType, Function::ExternalLinkage, "main", module.get());
    
    // 创建main函数的基本块
    BasicBlock *mainEntryBB = BasicBlock::Create(context, "entry", mainFunc);
    BasicBlock *loopCondBB = BasicBlock::Create(context, "loopCond", mainFunc);
    BasicBlock *loopBodyBB = BasicBlock::Create(context, "loopBody", mainFunc);
    BasicBlock *afterLoopBB = BasicBlock::Create(context, "afterLoop", mainFunc);
    
    // 设置main函数入口块
    builder.SetInsertPoint(mainEntryBB);
    
    // int x = 0;
    AllocaInst *x = builder.CreateAlloca(intType, nullptr, "x");
    builder.CreateStore(ConstantInt::get(intType, 0), x);
    
    // float n = 8;
    AllocaInst *nVar = builder.CreateAlloca(floatType, nullptr, "n");
    builder.CreateStore(ConstantFP::get(floatType, 8.0), nVar);
    
    // int i = 1;
    AllocaInst *i = builder.CreateAlloca(intType, nullptr, "i");
    builder.CreateStore(ConstantInt::get(intType, 1), i);
    
    builder.CreateBr(loopCondBB);
    
    // 循环条件
    builder.SetInsertPoint(loopCondBB);
    
    // 加载i值
    Value *iVal = builder.CreateLoad(intType, i, "i.val");
    
    // 加载n值并转换为int: (int)n
    Value *nVal = builder.CreateLoad(floatType, nVar, "n.val");
    Value *nIntVal = builder.CreateFPToSI(nVal, intType, "n.int");
    
    // 比较i < (int)n
    Value *icmp = builder.CreateICmpSLT(iVal, nIntVal, "i.cmp");
    
    builder.CreateCondBr(icmp, loopBodyBB, afterLoopBB);
    
    // 循环体
    builder.SetInsertPoint(loopBodyBB);
    
    // x += fib(i);
    Value *fibCall = builder.CreateCall(fibFunc, {iVal}, "fib.call");
    Value *xVal = builder.CreateLoad(intType, x, "x.val");
    Value *newX = builder.CreateAdd(xVal, fibCall, "x.new");
    builder.CreateStore(newX, x);
    
    // i++
    Value *iNext = builder.CreateAdd(iVal, ConstantInt::get(intType, 1), "i.next");
    builder.CreateStore(iNext, i);
    builder.CreateBr(loopCondBB);
    
    // 循环结束
    builder.SetInsertPoint(afterLoopBB);
    
    // 返回x值
    Value *retVal = builder.CreateLoad(intType, x, "ret");
    builder.CreateRet(retVal);
    
    // 验证模块
    verifyModule(*module, &errs());
    
    // 打印生成的LLVM IR
    module->print(outs(), nullptr);
    
    return 0;
}