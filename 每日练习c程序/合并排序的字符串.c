//输入两个已经按从小到大顺序排列好的字符串，编写一个合并两个字符串的函数，使合并后的字符串，仍然是从小到大排列。
//输入：两个已经排好顺序（升序）的两个字符串
//输出：一个合并在一起的有序（升序）的字符串
//要求：
//设计一个效率尽量高的算法，对每个字符串只扫描一遍就可以了。
//如果采用先进行串连接，然后再进行排序的算法，则效率太低了。
//输入：
//abcdef
//bcefghi
//输出：abbccdeeffghi

#include<stdio.h>
void main(){
	char c1[100];
	char c2[100];
	char c3[200];
	gets(c1);
	gets(c2);
	int i = 0, j = 0, k = 0;
	for (; i < strlen(c1) && j < strlen(c2); k++){
		if (c1[i] < c2[j]){
			c3[k] = c1[i];
			i++;
		}
		else{
			c3[k] = c2[j];
			j++;
		}
	}
	if (i = strlen(c1)){
		while (j<strlen(c2)){
			c3[k] = c2[j];
			j++;
			k++;
		}
	}
	else{
		while (i < strlen(c2)){
			c3[k] = c1[i];
			i++;
			k++;
		}
	}
	c3[k] = '\0';
	printf("%s", c3);
}