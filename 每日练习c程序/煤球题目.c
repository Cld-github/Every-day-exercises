//第一题:煤球数目
//有一堆煤球，堆成三角棱锥形。具体 : 
//				   第一层放1个，
//				   第二层3个(排列成三角形),
//				   第三层6个(排列成三角形),
//				   第四层10个(排列成三角形),
//                 ……
//				   如果一共有100层， 共有多少个煤球 ?
//				   请填表示煤球总数目的数字。
//			   注意 : 你提交的应该是 - 个整数，不要填写任何多余的内容或说明性文字。
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