#define TYPE char
#define value 10

data TYPE var_data;

idata TYPE var_idata;

xdata TYPE var_xdata;

pdata TYPE var_pdata;

code TYPE var_code = value;

void main(){
	
	int a = 10;
	int b = 20l;
	int c = 23;
	
	//var_data = value;
	
//	a = a + b * c;
//	
//	var_idata = value;
//	
//	a = a + b * c - a - var_idata;
//	
//	var_xdata = value;
//	
//	c = a + b * a;
//	
//	var_pdata = value;
//	
//	a = b * c + a;
//	
//	var_data = var_code;
//	
//	a += var_data;
//	
//	b = a + c;

	TYPE read = 200;
	
	read = var_data;
	
	a = a + b * c * a;
	
	read = var_idata;
	
	a = a + b * c * c;
	
	read = var_xdata;
	
	a = a + b * c * b;
	
	read = var_pdata;
	
	a = a + b * c + a;

	
	
	while(1){}
		
}