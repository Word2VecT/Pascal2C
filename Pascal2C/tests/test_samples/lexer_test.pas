program LexerTest;
{ 这是一个注释 }

(* 这是另一种注释风格 *)

const
  PI = 3.14159;
  MAX_SIZE = 100;
  GREETING = 'Hello, World!';
  IS_ACTIVE = true;

type
  TPoint = record
    x, y: integer;
  end;
  
  TNumbers = array[1..10] of integer;

var
  i, j, sum: integer;
  radius, area: real;
  name: string;
  isRunning: boolean;
  point: TPoint;
  numbers: TNumbers;

function Add(a, b: integer): integer;
begin
  Add := a + b;
end;

procedure PrintMessage(msg: string);
begin
  { 打印消息的代码会在这里 }
end;

begin
  { 主程序开始 }
  i := 10;
  j := 20;
  sum := i + j;
  
  radius := 5.0;
  area := PI * radius * radius;
  
  name := 'Pascal Lexer Test';
  isRunning := true;
  
  if isRunning then
    PrintMessage(name)
  else
    PrintMessage('Not running');
  
  while i > 0 do
  begin
    i := i - 1;
  end;
  
  for i := 1 to 10 do
  begin
    sum := sum + i;
  end;
  
  case i of
    1: sum := 1;
    2: sum := 2;
    3..5: sum := 3;
  end;
  
  { 测试运算符 }
  sum := (i + j) * 2 div 3 mod 4;
  isRunning := (i < j) and (sum > 0) or not false;
  
  { 测试引号转义 }
  name := 'Pascal''s Test';
end. 