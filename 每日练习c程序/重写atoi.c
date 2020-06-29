//÷ÿ–¥atoi
#include<stdio.h>
int atoi2(char* d){
	char *c = d;
	if (*d = '-')c++;
	if (*c <= '0' || *c >= '9') return 0;
	int a=(*c-'0');
	c++;
	while (*c != '\0'){
		if (*c >= '0'&&*c <= '9'){
			a *= 10;
			a += (*c - '0');
			c++;
		}
		else {
			if (*d = '-')return -a;
			else return a;
		}
	}
	if (*d = '-')return -a;
	else return a;
}
void main(){
	char c[] = "-123";
	printf("atoi:%d\n", atoi(c));
	printf("∏ƒ–¥atoi£∫%d", atoi2(c));
	getchar();
}