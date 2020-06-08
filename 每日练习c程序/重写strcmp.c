#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

int strcmp2(char *a, char *b){
	while (*a != '\0'&&*b != '\0'){
		if (*a > *b) return 1;
		if (*a < *b) return -1;
		a++;
		b++;
	}
	if (*b != '\0') return -1;
	else if (*a != '\0')return 1;
	else return 0;
}
int main(){
	char a[20] = "compaperab";
	char b[20] = "compapera";
	printf("%s %s %d\n", a,b,strcmp2(a,b));
	return 0;
}
