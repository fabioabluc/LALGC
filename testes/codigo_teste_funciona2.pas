program ex2;

var x, y : integer;

procedure proc;
	var z: integer;
	begin
		z := x;
		x := x - 1;

		if x > 1 then
			x := z
		else
			y := 1;

		y := y * z;
	end;

begin
	read(x);
	proc;
	write(x,y);
end.
