// Header:
// File Name: 
// Author:
// Date:
//

#define TYPE char
#define velue 36

data TYPE var_data;

idata TYPE var_idata;

xdata TYPE var_xdata;

pdata TYPE var_pdata;

code TYPE var_code = velue;


void main() {
	
		int a = 0;
		int b = 1;
		int c = 5;
		int d = 10;
	
    var_data = velue;
	
		a = b * c + d - var_data;

    var_xdata = velue;
	
		a = b + c / d * c - var_xdata;

    var_pdata = velue;
	
		c = b + d * a + d - var_xdata;
	
		var_idata = velue;
	
		a = b + c * d;
		
		var_data = var_code;

		a += var_data;

    //var_code = velue;

    while (1) {
        // Main loop
    }
}
