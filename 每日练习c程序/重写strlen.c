#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
int strlen2(char *a){
	int i = 0;
	while (*a != '\0'){
		i++;
		a++;
	}
	return i;
}
int main(){
	char arr1[20];
	char arr2[20] = { 'W', 'o','\0', 'r', 'l', 'd', '\0' };
	printf("%d\n", strlen2(arr2));
	printf("%s\n", arr2);
	system("pause");
	return 0;
}