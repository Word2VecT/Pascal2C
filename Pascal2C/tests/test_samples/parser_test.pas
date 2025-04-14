program ParserTest;
{ 这是一个专门用于测试Pascal解析器的示例程序 }

const
  PI = 3.14159;
  MAX_SIZE = 100;
  GREETING = 'Hello, Parser!';
  IS_ACTIVE = true;

type
  TPoint = record
    x, y: integer;
  end;
  
  TIntArray = array[1..10] of integer;
  TDirection = (North, East, South, West);

var
  i, j, sum: integer;
  radius, area: real;
  message: string;
  isRunning: boolean;
  point: TPoint;
  numbers: TIntArray;
  direction: TDirection;

{ 函数定义 }
function Calculate(a, b: integer): integer;
var
  temp: integer;
begin
  temp := a * 2;
  Calculate := temp + b;
end;

{ 递归函数 }
function Factorial(n: integer): integer;
begin
  if n <= 1 then
    Factorial := 1
  else
    Factorial := n * Factorial(n - 1);
end;

{ 过程定义 }
procedure PrintInfo(msg: string; value: integer);
begin
  { 打印信息的代码 }
end;

{ 带嵌套块的过程 }
procedure ProcessData(a: integer);
var
  x: integer;
begin
  x := a * 2;
  
  { 嵌套块 }
  begin
    var y: integer;
    y := x + 10;
  end;
end;

begin
  { 主程序开始 }
  
  { 简单赋值语句 }
  i := 10;
  j := 20;
  sum := 0;
  message := GREETING;
  isRunning := IS_ACTIVE;
  
  { 复杂表达式 }
  sum := (i + j) * 2 - (j div 2);
  area := PI * radius * radius;
  
  { 条件语句 }
  if sum > 50 then
    PrintInfo('Sum is large', sum)
  else if sum > 30 then
    PrintInfo('Sum is medium', sum)
  else
    PrintInfo('Sum is small', sum);
  
  { 嵌套条件 }
  if isRunning then
  begin
    if sum > 0 then
      sum := sum * 2;
  end;
  
  { While循环 }
  i := 5;
  while i > 0 do
  begin
    sum := sum + i;
    i := i - 1;
  end;
  
  { For循环 }
  for i := 1 to MAX_SIZE do
  begin
    sum := sum + i;
    if sum > 1000 then
      break;
  end;
  
  { 向下的For循环 }
  for j := 10 downto 1 do
  begin
    sum := sum - j;
  end;
  
  { Repeat-Until循环 }
  i := 0;
  repeat
    i := i + 1;
    sum := sum + i;
  until i >= 10;
  
  { Case语句 }
  case i of
    1: sum := 100;
    2: sum := 200;
    3..5: sum := 300;
    6, 7, 8: sum := 400;
    else sum := 500;
  end;
  
  { 函数调用 }
  sum := Calculate(i, j);
  
  { 递归函数调用 }
  i := Factorial(5);
  
  { 带嵌套表达式的过程调用 }
  PrintInfo('Result', Calculate(i, j) + Factorial(3));
  
  { 记录类型操作 }
  point.x := 10;
  point.y := 20;
  
  { 数组操作 }
  for i := 1 to 10 do
    numbers[i] := i * i;
  
  { With语句 }
  with point do
  begin
    x := x + 5;
    y := y + 10;
  end;
end. 