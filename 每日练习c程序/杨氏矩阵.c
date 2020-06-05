//杨氏矩阵
//有一个数字矩阵, 矩阵的每行从左到右是递增的，矩阵从上到下是递增的, 请编写
//程序在这样的矩阵中查找某个数字否存在。
//要求 : 时间复杂度小于O(N);
#include<stdio.h>
#define size(a) sizeof(a)/sizeof(*a)
int Find(int s[][6],int weight,int hight,int k){
	for (int i = 0; i < (weight<hight ? weight:hight) ; i++){
		for (int j = 0; j < (weight > hight ? weight : hight); j++){
			if (j < weight){
				if (s[i][j] > k){
					weight = j;
				}
				else if (s[i][j] == k){
					printf("%d在第%d行第%d列",k, i+1, j+1);
					return 1;
				}
			}
			if (j < hight){
				if (s[j][i] > k){
					hight = j;
				}
				else if (s[j][i] == k){
					printf("%d在第%d行第%d列", k, j+1, i+1);
					return 1;
				}
			}
		}
	}
	return 0;
}
int main(){
	int s[4][6] = { { 1, 3, 5, 7, 8, 11 }, { 2, 6, 9, 14, 15, 19 }, { 4, 10, 21, 23, 33, 57 }, { 34, 37, 45, 55, 56, 60 } };
	int k;
	for (int i = 0; i < size(s); i++){
		for (int j = 0; j < size(s[0]); j++)
			printf("%3d ", s[i][j]);
		printf("\n");
	}
	printf("请输入要查找的数：");
	scanf("%d", &k);
	if (Find(s, size(s[0]), size(s), k)==0){
		printf("找不到，/(ㄒoㄒ)/~~");
	}
	system("pause");
	return 0;
}