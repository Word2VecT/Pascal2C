program GeneratorTest;
{ 这是一个专门用于测试代码生成器的示例程序 }

{ 常量定义 }
const
  PI = 3.14159;
  MAX_COUNT = 100;
  GREETING = 'Hello, C code!';
  IS_DEBUG = true;

{ 类型定义 }
type
  TRangeType = 1..10;
  TDayOfWeek = (Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday);
  TRealArray = array[1..5] of real;
  TPersonRec = record
    name: string;
    age: integer;
    salary: real;
  end;

{ 变量声明 }
var
  counter, sum, index: integer;
  ratio, average: real;
  message: string;
  isActive: boolean;
  days: TDayOfWeek;
  scores: TRealArray;
  person: TPersonRec;

{ 函数: 计算两个整数的和 }
function Add(x, y: integer): integer;
begin
  Add := x + y;
end;

{ 函数: 计算圆的面积 }
function CalculateArea(radius: real): real;
begin
  CalculateArea := PI * radius * radius;
end;

{ 过程: 打印信息 }
procedure PrintMessage(msg: string);
begin
  { 这里只是占位，实际中会调用C的printf }
end;

{ 过程: 交换两个整数 }
procedure Swap(var a, b: integer);
var
  temp: integer;
begin
  temp := a;
  a := b;
  b := temp;
end;

{ 主程序 }
begin
  { 变量初始化和赋值 }
  counter := 0;
  sum := 0;
  ratio := 0.0;
  message := GREETING;
  isActive := IS_DEBUG;

  { 顺序执行的语句 }
  counter := 1;
  ratio := 1.5;
  sum := Add(5, 10);
  
  { 条件语句 }
  if counter < 10 then
    counter := counter + 1
  else
    counter := 0;
  
  { 嵌套的条件语句 }
  if isActive then
  begin
    if sum > 0 then
      PrintMessage('Sum is positive')
    else
      PrintMessage('Sum is not positive');
  end;
  
  { While循环 }
  counter := 1;
  while counter <= 5 do
  begin
    sum := sum + counter;
    counter := counter + 1;
  end;
  
  { For循环 }
  sum := 0;
  for index := 1 to 10 do
    sum := sum + index;
  
  { 嵌套循环 }
  for index := 1 to 3 do
  begin
    counter := 1;
    while counter <= 3 do
    begin
      sum := sum + (index * counter);
      counter := counter + 1;
    end;
  end;
  
  { Case语句 }
  case counter of
    1: sum := 100;
    2: sum := 200;
    3, 4, 5: sum := 300;
    else sum := 0;
  end;
  
  { 复合表达式 }
  average := sum / counter;
  isActive := (sum > 100) and (average < 50) or not isActive;
  
  { 数组操作 }
  scores[1] := 95.5;
  scores[2] := 87.0;
  scores[3] := 76.5;
  scores[4] := 88.0;
  scores[5] := 92.5;
  
  { 记录操作 }
  person.name := 'John Doe';
  person.age := 30;
  person.salary := 5000.0;
  
  { 函数调用 }
  ratio := CalculateArea(5.0);
  
  { 最终输出 }
  PrintMessage('Program completed.');
end. 