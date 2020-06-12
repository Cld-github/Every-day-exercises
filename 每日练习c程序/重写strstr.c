//ÖØĞ´strstr
#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
char *strstr2(char* str1, char* str2){
	for (int i = 0; i < strlen(str1); i++){
		if (*(str1 + i) == *str2){
			int j = 0;
			for (; j < strlen(str2); j++){
				if (*(str1 + i + j) != *(str2 + j)) break;
			}
			if (j == strlen(str2)){
				return str1 + i;
			}
		}
	}
	return NULL;
}
int main(){
	char *s = "GoldenGlobalView";
	char *l = "lob";
	char *p = strstr2(s, l);
	if (p)
		printf("%s", p);
	else
		printf("NotFound!");
	system("pause");
	return 0;
}