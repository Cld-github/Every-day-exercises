//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//
//��дһ�������ҳ�������ֻ����һ�ε����֡�
#include<stdio.h>
//#include<string.h>
////char *strtok(char *str, const char *delim){
////
////}
//
int main() {
	int a[] = { 1, 4, 6, 8, 0, 6, 3, 1, 4, 3, 5, 7, 8, 7, 5, 9 };
	for (int i = 0; i < (sizeof(a) / sizeof(a[0])-1); i++){
		if (a[i]!=-1)
			for (int j = i+1; j < sizeof(a) / sizeof(a[0]); j++){
				if (a[j] == a[i]){
					a[j] = -1;
					a[i] = -1;
					break;
				}
			}
	}
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++){
		if (a[i] != -1){
			printf("%d ", a[i]);
		}
	}
	return(0);
}