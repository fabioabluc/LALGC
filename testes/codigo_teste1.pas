program teste;

{ comentario valido }
{ teste 1
teste 2 }

var b: integer;
var a, a1: real;

begin
	{ erros lexicos }
	@teste
	25.2.3;
	25.2a3;
	1abcd3
	a@_afsdkj}

	{ sem erros lexicos }
	a := 25.2;
	b := 10;
	a1 := a + b;
	while a1 < a do
	begin
		write(a1);
		a1 := a1 - 1;
	end;
	if a <> b then write(a);
end.
