//实现一个函数，可以左旋字符串中的k个字符。
//例如 :
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
#include<stdio.h>
char* spin(char c[],int k){
	char *p = (char*)malloc((k + strlen(c))*sizeof(char));
	strcpy(p, c);
	strncat(p, c, k);
	return p + k;
}
int main(){
	char c[100];
	int k;
	printf("请输入一个字符串：");
	gets(c);
	printf("请输入字符串左旋的字符数：");
	scanf("%d", &k);
	printf("%s", spin(c, k));
	return 0;
}