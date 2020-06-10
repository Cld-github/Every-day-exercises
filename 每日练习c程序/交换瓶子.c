//第三题:交换瓶子
//	有N个瓶子，编号1 ~N, 放在架子上。
//比如有5个瓶子 :
//	2 1 3 5 4
//		要求每次拿起2个瓶子，交换它们的位置。
//	经过若干次后，使得瓶子的序号为 :
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