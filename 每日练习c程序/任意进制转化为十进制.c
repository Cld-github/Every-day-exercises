#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
int getint(char c){
	if (c >= '0'&&c <= '9'){
		return c - '0';
	}
	else if(c>='a'&&c<='z'){
		return c - 'a' + 10;
	}
	else if (c >= 'A'&&c <= 'Z'){
		return c - 'A' + 10;
	}
	else return 0;
}
int change(int n, char *c){
	int a=0,b=1;
	for (int i = strlen(c)-1; i >= 0; i--){
		a += b*getint(*(c + i));
		b *= n;
	}
	return a;
}
int main(){
	int n;
	char c[20];
	printf("请输入进制位：");
	scanf("%d", &n);
	printf("请输入%d进制数：", n);
	scanf("%s", c);
	printf("该数转化为十进制为：%d\n",change(n,c));
	system("pause");
	return 0;
}