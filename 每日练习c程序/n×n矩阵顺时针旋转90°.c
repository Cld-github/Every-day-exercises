//编写函数void rotate(int(*t)[N], int n)。
//函数功能是将t指向的数组中存储的n×n.矩阵最外圈全部元素做顺时钟旋转90°变换。
//例如：若n = 3有如下矩阵：
//1    2    3
//4    5    6
//7    8    9
//将矩阵最外圈全部元素做顺时钟旋转90°变换后应为：
//7    4    1
//8    5    2
//9    6    3
#include<stdio.h>
#define N 3
void rotate(int(*t)[N], int n){
	int *a = (int*)malloc((n - 1)*sizeof(int));
	for (int i = 0; i < n - 1; i++){
		a[i] = t[i][0];
		t[i][0] = t[n - 1][i];
		t[n - 1][i] = t[n - 1 - i][n - 1];
		t[n - 1 - i][n - 1] = t[0][n - 1 - i];
		t[0][n - 1 - i] = a[i];
	}
}
int main(){
	int t[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	rotate(t, 3);
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			printf("%d", t[i][j]);
		}
		printf("\n");
	}
	return 0;
}