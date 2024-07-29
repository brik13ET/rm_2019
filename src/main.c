#include "lib/fmt.h"	// char*	fmt	(char*,	args...)
#include "lib/ivt.h"	// char*	read	(u4)
#include "lib/calc.h"	// u8 		calc	(char*)

void	kmain(void);

void	kmain(){
	char* input;
	while (input != "off\0"){
		input = read_str(80);
		print(fmt("Result: %d\n", calc(input)));
	}
}
