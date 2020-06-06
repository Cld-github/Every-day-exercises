//由键盘输入一个自然数Ｎ（1≤N≤9），要求程序在屏幕上输出如下图形。
//Ｎ＝１时：　　　　　　　　Ｎ＝３时：　　　　　　　Ｎ＝４时：
//　　１　　　　　　　　　　　　１１１１１　　　　　　　１１１１１１１
//　　　　　　　　　　　　　　　１２２２１　　　　　　　１２２２２２１
//　　　　　　　　　　　　　　　１２３２１　　　　　　　１２３３３２１
//　　　　　　　　　　　　　　　１２２２１　　　　　　　１２３４３２１
//　　　　　　　　　　　　　　　１１１１１　　　　　　　１２３３３２１
//　　　　　　　　　　　　　　　　　　　　　　　　　　　１２２２２２１
//　　　　　　　　　　　　　　　　　　　　　　　　　　　１１１１１１１
//　　注：应保证Ｎ在图形中只出现一次，且在中心。
//

#include<stdio.h>

int main(){
	int N;
	printf("请输入一个自然数N：");
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= i; j++){
			printf("%2d", j);
		}
		for (int j = 1; j <= 2 * N - 2 * i ; j++)
			printf("%2d", i);
		for (int j = i-1; j >= 1; j--){
			printf("%2d", j);
		}
		printf("\n");
	}
	for (int i = N-1; i >= 1; i--){
		for (int j = 1; j <= i; j++){
			printf("%2d", j);
		}
		for (int j = 1; j <= 2 * N - 2 * i; j++)
			printf("%2d", i);
		for (int j = i - 1; j >= 1; j--){
			printf("%2d", j);
		}
		printf("\n");
	}
	return 0;
}