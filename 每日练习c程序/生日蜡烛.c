//  ��������
//	ĳ����ĳ�꿪ʼÿ�궼�ٰ�һ������party, ����ÿ�ζ�Ҫ��Ϩ��������ͬ������������������������һ����Ϩ��236���������ʣ����Ӷ�����
//	��ʼ������party�� ?
//	����д����ʼ������party����������
//ע�� : ���ύ��Ӧ����һ����������Ҫ��д�κζ�������ݻ�˵�������֡�
#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

int main(){
	for (int i = 1; i < 236; i++){
		int sum = 0;
		for (int j = i; sum < 236; j++){
			sum += j;
		}
		if (sum == 236) printf("%d", i);
	}
	system("pause");
	return 0;
}