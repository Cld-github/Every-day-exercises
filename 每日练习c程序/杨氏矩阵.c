//���Ͼ���
//��һ�����־���, �����ÿ�д������ǵ����ģ�������ϵ����ǵ�����, ���д
//�����������ľ����в���ĳ�����ַ���ڡ�
//Ҫ�� : ʱ�临�Ӷ�С��O(N);
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
					printf("%d�ڵ�%d�е�%d��",k, i+1, j+1);
					return 1;
				}
			}
			if (j < hight){
				if (s[j][i] > k){
					hight = j;
				}
				else if (s[j][i] == k){
					printf("%d�ڵ�%d�е�%d��", k, j+1, i+1);
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
	printf("������Ҫ���ҵ�����");
	scanf("%d", &k);
	if (Find(s, size(s[0]), size(s), k)==0){
		printf("�Ҳ�����/(��o��)/~~");
	}
	system("pause");
	return 0;
}