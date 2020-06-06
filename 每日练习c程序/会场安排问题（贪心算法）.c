#include<stdio.h>
#include <stdlib.h>
int count = 0;//会场数
void sort(int start[],int end[],int k){//冒泡排序
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
int greedySelector(int start[], int end[],int k){//贪心算法
	count++;//会场数+1
	int EndTime = 0;
	for (int i = 0; i < k; i++){//求当前几个活动中的贪心算法
		if (start[i] >= EndTime){
			EndTime = end[i];
			end[i] = 0;//把已经安排的活动初始化为0
			start[i] = 0;//把已经安排的活动初始化为0
		}
	}
	for (int i = 0; i < k; i++){//判断是否把所有活动都安排
		if (end[i] != 0){//如果剩有活动
			return 1;//函数返回1
			break;
		}
	}
	return 0;//否则说明活动全都安排  返回0
}
int main(){
	int k;//保存活动数量
	printf("请输入总共的活动数量：");
	scanf("%d", &k);//输入活动数量
	int *start = (int*)malloc(k*sizeof(int));//各个活动的开始时间
	int *end = (int*)malloc(k*sizeof(int));//各个活动的结束时间
	for (int i = 0; i < k; i++){
		printf("请输入第%d个活动的开始时间和结束时间：",i+1);
		scanf("%d%d", &start[i], &end[i]);//输入各个活动的开始时间和结束时间
	}
	sort(start,end,k);//调用排序函数
	while (greedySelector(start, end,k));//用while不停的循环贪心算法函数 直到函数返回0
	printf("一共需要%d个会场", count);//输出会场数
	system("pause");
	return 0;
}