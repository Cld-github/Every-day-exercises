//�����ķֻ����⡣
//�磬����������n = 6�����Էֻ�Ϊ��
//6
//5 + 1
//4 + 2, 4 + 1 + 1
//3 + 3, 3 + 2 + 1, 3 + 1 + 1 + 1
//2 + 2 + 2, 2 + 2 + 1 + 1, 2 + 1 + 1 + 1 + 1
//1 + 1 + 1 + 1 + 1 + 1 + 1
//���ڵ������ǣ����ڸ�����������n, ��д�㷨��ӡ���л��֡�
//�û��Ӽ������� n ����Χ1~10��
//������������������л��֡�

#include <stdio.h> 
void print(int a[],int n){
	printf(" %d", a[0]);
	int sum = a[0];
	for (int i = 1; sum < n; i++){
		sum += a[i];
		printf("+%d", a[i]);
	}
	printf("\n");
}
void resolve(int a[],int b,int c,int n){
	if (b >= 0){
		a[b] = c;
		int sum = 0;
		for (int i = 0; i <= b; ++i){
			sum += a[i];
		}
		if (sum < n){
			resolve(a, b + 1, c, n);
		}
		else if (sum == n){
			if (a[b] == 1){
				print(a, n);
				while (a[b] == 1)
					b--;
				resolve(a, b, a[b] - 1, n);
			}
			else{
				print(a, n);
				resolve(a, b, c - 1, n);
			}
		}
		else if (sum > n){
			sum -= c;
			resolve(a, b, c - 1, n);
		}
	}
}
int main() {
	int n;
	printf("������һ����:");
	scanf_s("%d", &n);
	int *a = (int*)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++)
		a[i] = 0;
	resolve(a, 0, n, n);
	system("pause");
	return 0;
}