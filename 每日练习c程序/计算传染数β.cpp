//计算某地区某时间段内每天的传染数β
#include<stdio.h>
#include<Windows.h>
#include<math.h>
#pragma comment(lib,"Winmm.lib")
#pragma warning(disable:4996)

int main(){
	double N = 67900000;
	int I0 = 27;
	int quezhen[41] = {27,32,43,77,79,154,196,253,299,298,432,568,0,0,1318,1471,1860,2457,3060,3741,4720,5337,6250,7590,8999,10938,13670,16140,18143,20562,23502,27321,31047,34872,37944,43264,46006,49454,53291,57514,65043};
	double It;
	

	for (int i = 2; i <= 41; i++){
		if (i != 13 && i != 14){
			It = N - quezhen[i - 1];
			double β = log(((N / It) - 1) / ((N / I0) - 1)) / (i-1);
			printf("3月%d日的β值为%f\n", i, β);
		}
	}
	system("pause");
	return 0;
}