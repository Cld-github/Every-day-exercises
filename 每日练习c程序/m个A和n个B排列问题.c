//����m��A��n��B������ϳɶ��ٸ���ͬ���е����⡣
//�������3��A��2��B������ɶ��������У�
//���磺AAABB, AABBA��������������
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
	printf("����m��A��n��B������ϳɶ��ٸ���ͬ����\n������m��n��");
	scanf("%d%d", &m, &n);
	printf("��ϳ�%d����ͬ����\n", s(m+n,n));
}