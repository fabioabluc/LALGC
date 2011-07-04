program ex2;

var x, y : integer;

 procedure p;     
	var a : integer;  
	begin             
		a := x;       
		x := x - 1;   
                     
		if x > 1 then 
			x := a    
		else          
			y := 1;   
                     
		y := y * a;   
	end;              

begin
	read(x);
	p;
	write(x,y);
end.
