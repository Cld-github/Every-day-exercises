//层次分析法
#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
#define N 12//准则数
#define M 4//方案数
int main(){
	double A[N][N] = {
			{ 1.0, 1.0 / 2.0, 1.0 / 3.0, 1.0 / 2.0, 1.0, 1.0 / 2.0, 1.0 / 2.0, 1.0, 1.0 / 2.0, 1.0 / 2.0, 1.0 / 2.0, 1.0 / 3.0 },
			{ 2.0, 1.0, 2.0 / 3.0, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 2.0 / 3.0 },
			{ 3.0, 3.0 / 2.0, 1.0, 3.0 / 2.0, 3.0, 3.0 / 2.0, 3.0 / 2.0, 3.0, 3.0 / 2.0, 3.0 / 2.0, 3.0 / 2.0, 1.0 },
			{ 2.0, 1.0, 2.0 / 3.0, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 2.0 / 3.0 },
			{ 1, 1.0 / 2.0, 1.0 / 3.0, 1.0 / 2.0, 1, 1.0 / 2.0, 1.0 / 2.0, 1, 1.0 / 2.0, 1.0 / 2.0, 1.0 / 2.0, 1.0 / 3.0 },
			{ 2, 1, 2.0 / 3.0, 1, 2, 1, 1, 2, 1, 1, 1, 2.0 / 3.0 },
			{ 2, 1, 2.0 / 3.0, 1, 2, 1, 1, 2, 1, 1, 1, 2.0 / 3.0 },
			{ 1, 1.0 / 2.0, 1.0 / 3.0, 1.0 / 2.0, 1, 1.0 / 2.0, 1.0 / 2.0, 1, 1.0 / 2.0, 1.0 / 2.0, 1.0 / 2.0, 1.0 / 3.0 },
			{ 2, 1, 2.0 / 3.0, 1, 2, 1, 1, 2, 1, 1, 1, 2.0 / 3.0 },
			{ 2, 1, 2.0 / 3.0, 1, 2, 1, 1, 2, 1, 1, 1, 2.0 / 3.0 },
			{ 2, 1, 2.0 / 3.0, 1, 2, 1, 1, 2, 1, 1, 1, 2.0 / 3.0 },
			{ 3, 3.0 / 2.0, 1, 3.0 / 2.0, 3, 3.0 / 2.0, 3.0 / 2.0, 3, 3.0 / 2.0, 3.0 / 2.0, 3.0 / 2.0, 1 }

	};
	/*{
			{ 1.0, 1.0 / 2.0, 4.0, 3.0, 3.0 },
			{ 2.0, 1.0, 7.0, 5.0, 5.0 },
			{ 1.0 / 4.0, 1.0 / 7.0, 1.0, 1.0 / 2.0, 1.0 / 3.0 },
			{ 1.0 / 3.0, 1.0 / 5.0, 2.0, 1.0, 1.0 },
			{ 1.0 / 3.0, 1.0 / 5.0, 3.0, 1.0, 1.0 }

	};*/
	double A2[N][N];
	double w[N], Aw[N], RI[11] = { 0, 0, 0, 0.58, 0.90, 1.12, 1.24, 1.32, 1.41, 1.45, 1.49 };
	double λ = 0.0, CI, CR;
	double B[N][M][M] = {
			{
				{ 1.0, 2.0, 5.0 },
				{ 1.0 / 2.0, 1.0, 2.0 },
				{ 1.0 / 5.0, 1.0 / 2.0, 1.0 }
			},
			{
				{ 1.0, 1.0 / 3.0, 1.0 / 8.0 },
				{ 3.0, 1.0, 1.0 / 3.0 },
				{ 8.0, 3.0, 1.0 }
			},
			{
				{ 1.0, 1.0, 3.0 },
				{ 1.0, 1.0, 3.0 },
				{ 1.0 / 3.0, 1.0 / 3.0, 1 }
			},
			{
				{ 1, 3, 4 },
				{ 1.0 / 3.0, 1, 1 },
				{ 1.0 / 4.0, 1, 1 }
			},
			{
				{ 1.0, 1.0, 1.0 / 4.0 },
				{ 1.0, 1.0, 1.0 / 4.0 },
				{ 4.0, 4.0, 1.0 }
			}
	};
	double B2[N][M][M];
	double wb[N][M], Awb[N][M];
	double λb[N],CIb[N];
	//printf("输入准则对目标的成对比较阵：\n");
	//for (int i = 0; i < N; i++){
	//	printf("输入第%d行，中间用空格隔开:", i + 1);
	//	for (int j = 0; j < N; j++){
	//		scanf("%f", &A[i][j]);
	//	}
	//}
	//printf("输入方案对准则的成对比较阵：\n");
	//for (int i = 0; i < N; i++){
	//	printf("输入第%d个成对比较阵:\n", i + 1);
	//	for (int j = 0; j < M; j++){
	//		printf("输入第%d行", j + 1);
	//		for (int k = 0; k < M;k++)
	//			scanf("%f", &B[i][j][k]);
	//	}
	//}
	for (int i = 0; i < N; i++){
		double sum = 0.0;
		for (int j = 0; j < N; j++){
			sum += A[j][i];
		}
		for (int j = 0; j < N; j++){
			A2[j][i] = A[j][i] / sum;
		}
	}
	printf("列向量归一化：\n");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%8.5f", A2[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < N; i++){
		double sum = 0.0;
		for (int j = 0; j < N; j++){
			sum += A2[i][j];
		}
		w[i] = sum / N;
	}
	printf("特征向量w：\n");
	for (int i = 0; i < N; i++){
		printf("%8.5f\n", w[i]);
	}
	for (int i = 0; i < N; i++){
		double sum = 0.0;
		for (int j = 0; j < N; j++){
			sum += A[i][j] * w[j];
		}
		Aw[i] = sum;
	}
	printf("Aw:\n");
	for (int i = 0; i < N; i++){
		printf("%8.5f\n", Aw[i]);
	}
	for (int i = 0; i < N; i++){
		λ += (Aw[i] / w[i]);
	}
	λ = λ / N;
	printf("λ=%8.5f\n", λ);
	CI = (λ - N) / (N - 1);
	printf("CI=%8.5f\n", CI);
	CR = (CI / RI[N]);
	printf("CR=%8.5f\n", CR);
	////////////////////////////////////
	for (int k = 0; k < N; k++){
		for (int i = 0; i < M; i++){
			double sum = 0.0;
			for (int j = 0; j < M; j++){
				sum += B[k][j][i];
			}
			for (int j = 0; j < M; j++){
				B2[k][j][i] = B[k][j][i] / sum;
			}
		}
		for (int i = 0; i < M; i++){
			double sum = 0.0;
			for (int j = 0; j < M; j++){
				sum += B2[k][i][j];
			}
			wb[k][i] = sum / M;
		}
		for (int i = 0; i < M; i++){
			double sum = 0.0;
			for (int j = 0; j < M; j++){
				sum += B[k][i][j] * wb[k][j];
			}
			Awb[k][i] = sum;
		}
		λb[k] = 0.0;
		for (int i = 0; i < M; i++){
			λb[k] += (Awb[k][i] / wb[k][i]);
		}
		λb[k] = λb[k] / M;
		CIb[k] = (λb[k] - M) / (M - 1);
	}
	printf("特征向量:\n");
	for (int i = 0; i < N; i++){
		printf("%8d", i + 1);
	}
	printf("\n");
	for (int k = 0; k < M; k++){
		for (int i = 0; i < N; i++)
			printf("%8.5f", wb[i][k]);
		printf("\n");
	}
	printf("λ:\n");
	for (int i = 0; i < N; i++){
		printf("%8d", i + 1);
	}
	printf("\n");
	for (int i = 0; i < N; i++)
		printf("%8.5f", λb[i]);
	printf("\n");
	printf("CI:\n");
	for (int i = 0; i < N; i++){
		printf("%8d", i + 1);
	}
	printf("\n");
	for (int i = 0; i < N; i++)
		printf("%8.5f", CIb[i]);
	printf("\n");
	system("pause");
	return 0;
}