//ʵ��һ�����������������ַ����е�k���ַ���
//���� :
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
#include<stdio.h>
char* spin(char c[],int k){
	char *p = (char*)malloc((k + strlen(c))*sizeof(char));
	strcpy(p, c);
	strncat(p, c, k);
	return p + k;
}
int main(){
	char c[100];
	int k;
	printf("������һ���ַ�����");
	gets(c);
	printf("�������ַ����������ַ�����");
	scanf("%d", &k);
	printf("%s", spin(c, k));
	return 0;
}