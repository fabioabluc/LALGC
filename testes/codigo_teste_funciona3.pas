program teste;

{ teste1 teste2 }

var b: integer;
var a, a1: real;

procedure proc (a : integer; b : integer);
var aux:real;
begin
	a := b;
	a := b;
	a := b;
	if a <> b then
		begin
			write(aux);
			aux := a + b;
		end
	else
		begin
			write(aux);
			aux := a - b;
		end;
end;

begin
	a := 25.2;
	b := 10;
	a1 := a + b;
	proc(b; b);
	while a1 > a do
	begin
		write(a1);
		a1 := a1 - 1;
	end;
end.

