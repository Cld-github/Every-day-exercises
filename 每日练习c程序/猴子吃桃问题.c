//���ӳ������⣺���ӵ�һ��ժ�����ɸ����ӣ���������һ�룬������񫣬
//�ֶ����һ�����ڶ��������ֽ���һ��ʣ�µ����ӳԵ�һ�룬�ֶ����һ����
//�Ժ�ÿ�����϶�����ǰһ��ʣ�µ�һ����һ����
//����10���������ٳ�ʱ������ֻʣ��һ�������ˡ�
//��д��������ӵ�һ�칲ժ�˶��ٸ����ӡ�

#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int peach(int day,int n){
	if (day == 1)return n;
	else return peach(day - 1, 2*n + 2);
}
int main(){
	printf("%d\n",peach(10,1));
	system("pause");
	return 0;
}
