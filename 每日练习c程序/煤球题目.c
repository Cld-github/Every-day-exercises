//��һ��:ú����Ŀ
//��һ��ú�򣬶ѳ�������׶�Ρ����� : 
//				   ��һ���1����
//				   �ڶ���3��(���г�������),
//				   ������6��(���г�������),
//				   ���Ĳ�10��(���г�������),
//                 ����
//				   ���һ����100�㣬 ���ж��ٸ�ú�� ?
//				   �����ʾú������Ŀ�����֡�
//			   ע�� : ���ύ��Ӧ���� - ����������Ҫ��д�κζ�������ݻ�˵�������֡�
#include<stdio.h>
#include<Windows.h>

#pragma warning(disable:4996)
int getint(int i){
	i = i*(i + 1) / 2;
}
int getsum(int i){
	if (i == 1)return getint(i);
	else return getint(i) + getsum(i - 1);
}
int main(){
	printf("%d", getsum(100));
	system("pause");
	return 0;
}