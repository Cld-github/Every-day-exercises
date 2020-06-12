//÷ÿ–¥memcpy
#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
void *memcpy2(void* str1, void* str2,int n){
	if (str1 == NULL || str2 == NULL) return NULL;
	for (int i = 0; i < n; i++){
		*((char*)str1 + i) = *((char*)str2 + i);
	}
	return str1;
}
int main(){
	const char src[50] = "Cld is a pretty girl!";
	char dest[50];
	memcpy2(dest, src, strlen(src) + 1);
	printf("dest = %s\n", dest);
	system("pause");
	return 0;
}