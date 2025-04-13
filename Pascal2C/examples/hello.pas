program HelloWorld;
var
    i, sum: integer;
    greeting: string;
    isRunning: boolean;

begin
    greeting := 'Hello, World!';
    writeln(greeting);
    
    sum := 0;
    isRunning := true;
    
    i := 1;
    while i <= 10 do
    begin
        sum := sum + i;
        i := i + 1;
    end;
    
    writeln('Sum of numbers from 1 to 10: ', sum);
    
    if sum > 50 then
        writeln('Sum is greater than 50')
    else
        writeln('Sum is less than or equal to 50');
    
    isRunning := false;
end. 