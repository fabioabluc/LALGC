program ex3;

var a, b: integer;

procedure proc (x, y: integer);
	var l: integer;
	begin
		l := x + y;
		x := l;
	end;

begin
	read (a, b);
	proc (a; b);
end.
