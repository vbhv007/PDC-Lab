#include <stdio.h>
#include <omp.h>

int main(void){
	int i, j, k, a = 5, b = 5, c = 5, sum = 0;
	int mat1[a][b], mat2[a][b];
	for (i = 0; i < a; i++){
                for (j = 0; j < b; j++){
                        mat1[i][j] = i + j;
			mat2[i][j] = i - j;
                }
        }
	int add[a][b];
	int sub[a][b];
	int mul[a][b];
	int trans1[a][b];
	int trans2[a][b];
	int add_thread[a][b];
	int sub_thread[a][b];
	int mul_thread[a][b];
	int t_thread[a][b];
	#pragma omp parallel
	{
		#pragma omp sections
		{
			for (i = 0; i < a; i++){
				for (j = 0; j < b; j++){
					add[i][j] = mat1[i][j] + mat2[i][j];
					add_thread[i][j] = omp_get_thread_num();
				}
			}
		}
		#pragma omp sections
                {
                        for (i = 0; i < a; i++){
                                for (j = 0; j < b; j++){
                                        sub[i][j] = mat1[i][j] - mat2[i][j];
					sub_thread[i][j] = omp_get_thread_num();
                                }
                        }
                }
		#pragma omp sections
                {
                        for (i = 0; i < a; i++){
                                for (j = 0; j < b; j++){
					for (k = 0; k < c; k++){
						sum += mat1[i][k] * mat2[k][j];
					}
					mul[i][j] = sum;
					mul_thread[i][j] = omp_get_thread_num();
					sum = 0;
                                }
                        }
                }
		#pragma omp sections
                {
                        for (i = 0; i < a; i++){
                                for (j = 0; j < b; j++){
                                        trans1[i][j] = mat1[j][i];
					trans2[i][j] = mat2[j][i];
					t_thread[i][j] = omp_get_thread_num();
				}
                        }
                }

	}
	printf("Original matrix 1:\n");
	for (i = 0; i < a; i++){
                for (j = 0; j < b; j++){
                        printf("%d\t", mat1[i][j]);
                }
                printf("\n");
        }
	printf("\nOriginal matrix 2:\n");
	for (i = 0; i < a; i++){
                for (j = 0; j < b; j++){
                        printf("%d\t", mat2[i][j]);
                }
                printf("\n");
        }
	printf("\nAddition:\n");
	for (i = 0; i < a; i++){
		for (j = 0; j < b; j++){
			printf("%d(%d)\t", add[i][j], add_thread[i][j]);
		}
		printf("\n");
	}
	printf("\nSubtraction:\n");
	for (i = 0; i < a; i++){
                for (j = 0; j < b; j++){
                        printf("%d(%d)\t", sub[i][j], sub_thread[i][j]);
                }
                printf("\n");
        }
	printf("\nMultiplication:\n");
        for (i = 0; i < a; i++){
                for (j = 0; j < b; j++){
                        printf("%d(%d)\t", mul[i][j], mul_thread[i][j]);
                }
                printf("\n");
        }
	printf("\nTranspose of matrix 1:\n");
        for (i = 0; i < a; i++){
                for (j = 0; j < b; j++){
                        printf("%d(%d)\t", trans1[i][j], t_thread[i][j]);
                }
                printf("\n");
        }
	printf("\nTranspose of matrix 2\n");
        for (i = 0; i < a; i++){
                for (j = 0; j < b; j++){
                        printf("%d(%d)\t", trans2[i][j], t_thread[i][j]);
                }
                printf("\n");
        }
	return 0;
}
