//猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不过瘾，
//又多吃了一个。第二天早上又将第一天剩下的桃子吃掉一半，又多吃了一个。
//以后每天早上都吃了前一天剩下的一半零一个。
//到第10天早上想再吃时，发现只剩下一个桃子了。
//编写程序求猴子第一天共摘了多少个桃子。

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
