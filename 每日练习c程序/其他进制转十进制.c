//其他进制转十进制

#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
#define SIZE 20
int GetInt(int a, int b[], char c[]){
	int i = 0;
	for (; c[i]!=0; i++){
		if (c[i] >= '0' && c[i] <= '9'){
			b[i] = c[i] - '0';
		}
		else if (c[i] >= 'a'&&c[i] <= 'z'){
			b[i] = c[i] - 'a'+10;
		}
		else return 0;
		if (b[i] >= a) return 0;
	}
	b[i] = -1;
	return 1;
}
int Change(int a,int b[]){
	int s = b[0];
	for (int i = 1; b[i]!=-1; i++){
		s *= a;
		s += b[i];
	}
	return s;
}
int main(){
	char c[SIZE];
	int a, b[SIZE];
	printf("请输入进制数：");
	scanf("%d", &a);
	printf("请输入该进制的数字：");
	scanf("%s", c);
	if (GetInt(a, b, c) == 0){
		printf("数字错误!");
	}
	else {
		printf("进制转换后的数是：%d", Change(a, b));
	}
	system("pause");
	return 0;
}
