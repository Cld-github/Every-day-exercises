//������:����ƿ��
//	��N��ƿ�ӣ����1 ~N, ���ڼ����ϡ�
//������5��ƿ�� :
//	2 1 3 5 4
//		Ҫ��ÿ������2��ƿ�ӣ��������ǵ�λ�á�
//	�������ɴκ�ʹ��ƿ�ӵ����Ϊ :
//	1 2 3 4 5
#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

int main(){
	int N;
	int count = 0;
	scanf("%d", &N);
	int *a = (int*)malloc(N*sizeof(int));
	for (int i = 0; i < N; i++){
		scanf("%d", a + i);
	}
	for (int i = 0; i < N; i++){
		int min1=i, min2=*(a+i);
		for (int j = i; j < N; j++){
			if (*(a + j) < min2){
				min2 = *(a + j);
				min1 = j;
			}
		}
		if (min2 < *(a + i)){
			int change = *(a + i);
			*(a + i) = *(a + min1);
			*(a + min1) = change;
			count++;
		}
	}
	printf("%d", count);
	system("pause");
	return 0;
}