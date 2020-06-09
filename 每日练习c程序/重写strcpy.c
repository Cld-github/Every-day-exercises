#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
char * strcpy2(char *a, char *b){
	char *p = a;
	while (*b != '\0'){
		*(p++) = *(b++);
	}
	return a;
}
int main(){
	char arr1[20];
	char arr2[20] = "world";
	printf("%s\n", strcpy2(arr1, arr2));
	printf("%s\n", arr1);
	system("pause");
	return 0;
}