//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ���
//���� : ����s1 = AABCD��s2 = BCDAA, ����1
//	 ����s1 = abcd��s2 = ACBD������0.
//	 AABCD����һ���ַ��õ�ABCDA
//	 AABCD���������ַ��õ�BCDAA
//	 AABCD����һ���ַ��õ�DAABC
#include<stdio.h>
int spin(char s1[],char s2[]){
	if (strlen(s1) != strlen(s2)) return 0;
	char*p = (char*)malloc((strlen(s1) * 2)*sizeof(char));
	strcpy(p, s1);
	strcat(p, s1);
	for (int i = 0; i < strlen(s1) * 2; i++){
		if (*(p + i) == *s2){
			if (strncmp(p + i, s2, strlen(s1)) == 0)return 1;
		}
	}
	return 0;
}
int main(){
	char s1[100],s2[100];
	printf("�������ַ���s1��");
	gets(s1);
	printf("�������ַ���s2��");
	gets(s2);
	printf("%d", spin(s1, s2));
	return 0;
}