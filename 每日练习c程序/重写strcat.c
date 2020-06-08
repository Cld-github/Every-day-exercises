#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

void strcat2(char *a, char *b){
	char*c = a;
	while (*c!='\0') c++;
	while (*b != '\0'){
		*c = *b;
		c++;
		b++;
	}
}
int main(){
	char d[20] = "Golden";
	char s[20] = "View";
	char a[20] = { 'A', 'B','\0', 'C', 'D' };

	strcat2(s, a);
	printf("%s\n", s);
	return 0;
}
