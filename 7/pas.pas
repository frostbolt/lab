program pas;
var x: integer;
begin
	write('Введите x: ');
	readln(x);
	if (x>=10) and (x<=100) then
		writeln('Двузначное число')
	else writeln('Не двузначное число')    
end.
