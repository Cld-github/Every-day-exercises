#include<stdio.h>
#include <stdlib.h>
int count = 0;//�᳡��
void sort(int start[],int end[],int k){//ð������
	for (int i = 0; i < k - 1; i++){
		for (int j = 0; j < k - 1 - i; j++){
			if (end[j]>end[j + 1]){
				int swap = end[j];
				end[j] = end[j + 1];
				end[j + 1] = swap;
				swap = start[j];
				start[j] = start[j + 1];
				start[j + 1] = swap;
			}
		}
	}
}
int greedySelector(int start[], int end[],int k){//̰���㷨
	count++;//�᳡��+1
	int EndTime = 0;
	for (int i = 0; i < k; i++){//��ǰ������е�̰���㷨
		if (start[i] >= EndTime){
			EndTime = end[i];
			end[i] = 0;//���Ѿ����ŵĻ��ʼ��Ϊ0
			start[i] = 0;//���Ѿ����ŵĻ��ʼ��Ϊ0
		}
	}
	for (int i = 0; i < k; i++){//�ж��Ƿ�����л������
		if (end[i] != 0){//���ʣ�л
			return 1;//��������1
			break;
		}
	}
	return 0;//����˵���ȫ������  ����0
}
int main(){
	int k;//��������
	printf("�������ܹ��Ļ������");
	scanf("%d", &k);//��������
	int *start = (int*)malloc(k*sizeof(int));//������Ŀ�ʼʱ��
	int *end = (int*)malloc(k*sizeof(int));//������Ľ���ʱ��
	for (int i = 0; i < k; i++){
		printf("�������%d����Ŀ�ʼʱ��ͽ���ʱ�䣺",i+1);
		scanf("%d%d", &start[i], &end[i]);//���������Ŀ�ʼʱ��ͽ���ʱ��
	}
	sort(start,end,k);//����������
	while (greedySelector(start, end,k));//��while��ͣ��ѭ��̰���㷨���� ֱ����������0
	printf("һ����Ҫ%d���᳡", count);//����᳡��
	system("pause");
	return 0;
}