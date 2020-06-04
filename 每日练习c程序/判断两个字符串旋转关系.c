//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串
//例如 : 给定s1 = AABCD和s2 = BCDAA, 返回1
//	 给定s1 = abcd和s2 = ACBD，返回0.
//	 AABCD左旋一个字符得到ABCDA
//	 AABCD左旋两个字符得到BCDAA
//	 AABCD右旋一个字符得到DAABC
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
	printf("请输入字符串s1：");
	gets(s1);
	printf("请输入字符串s2：");
	gets(s2);
	printf("%d", spin(s1, s2));
	return 0;
}