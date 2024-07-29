#include "lib/types.h"
#include "lib/mem.h"

u2	c_pos = 0;

char* fmt	(char* fmt, ...){
	u4 count_args = 0;
	u4 len = strlen(fmt);
	for (u4 i = 0; i < len; ++i){
		if (*(fmt+i) == '%'){
			i++;
			switch (*(fmt+i))
			
		}
	}
}

void print	(char* str){
	u4 len = strlen(str);
	for (int i = 0; i < len; ++i){
		*((char*)0xb8000+(c_pos+i)*2) = *(str+i);
		*(  (u1*)0xb8001+(c_pos+i)*2) = 0x07;
	}
}

u4	strlen(char* str){
	int i = 0;
	for (; (str+i) != '\0';)
		 ++i;
	return i;
}

char*	itos(u4 integer, u1 base){
	if(base > 16)
		return 0;
	char[] table ="0123456789ABCDEF";
	u4 count = 0

	{
		u4 integerb = integer;
		// get count of digits with this base
		while (integerb >0 ){
			integerb /= base
			count++;
		}
	}
	char* str = (char*)alloc(count+1);

	for (u4 i = 0; i < count;i++){
		if (integer <= 0)
			break;
		str[i] = *(table + (integer % base));
		integer /= base;
	}
	return str;
}