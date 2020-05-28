//计算m个A，n个B可以组合成多少个不同排列的问题。
//例如计算3个A，2个B可以组成多少种排列？
//（如：AAABB, AABBA………………）
#include<stdio.h>
int s(int m,int n){
	int sum = 1;
	for (int i = 0; i < n; i++){
		sum *= (m - i);
	}
	for (int i = 1; i <= n; i++){
		sum /= i;
	}
	return sum;
}
void main(){
	int m, n;
	printf("计算m个A，n个B可以组合成多少个不同排列\n请输入m、n：");
	scanf("%d%d", &m, &n);
	printf("组合成%d个不同排列\n", s(m+n,n));
}