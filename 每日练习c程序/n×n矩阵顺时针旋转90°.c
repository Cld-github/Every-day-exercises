//��д����void rotate(int(*t)[N], int n)��
//���������ǽ�tָ��������д洢��n��n.��������Ȧȫ��Ԫ����˳ʱ����ת90��任��
//���磺��n = 3�����¾���
//1    2    3
//4    5    6
//7    8    9
//����������Ȧȫ��Ԫ����˳ʱ����ת90��任��ӦΪ��
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