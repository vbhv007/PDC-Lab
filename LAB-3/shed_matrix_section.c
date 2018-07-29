#include <stdio.h>
#include <omp.h>

int main(void){
	int i, j, k, sum = 0;
	int mat1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int mat2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
	int add[3][3];
	int sub[3][3];
	int mul[3][3];
	int trans1[3][3];
	int trans2[3][3];
	int add_thread[3][3];
	int sub_thread[3][3];
	int mul_thread[3][3];
	int t_thread[3][3];
	#pragma omp parallel
	{
		#pragma omp sections
		{
			for (i = 0; i < 3; i++){
				for (j = 0; j < 3; j++){
					add[i][j] = mat1[i][j] + mat2[i][j];
					add_thread[i][j] = omp_get_thread_num();
				}
			}
		}
		#pragma omp sections
                {
                        for (i = 0; i < 3; i++){
                                for (j = 0; j < 3; j++){
                                        sub[i][j] = mat1[i][j] - mat2[i][j];
					sub_thread[i][j] = omp_get_thread_num();
                                }
                        }
                }
		#pragma omp sections
                {
                        for (i = 0; i < 3; i++){
                                for (j = 0; j < 3; j++){
					for (k = 0; k < 3; k++){
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
                        for (i = 0; i < 3; i++){
                                for (j = 0; j < 3; j++){
                                        trans1[i][j] = mat1[j][i];
					trans2[i][j] = mat2[j][i];
					t_thread[i][j] = omp_get_thread_num();
				}
                        }
                }

	}
	printf("Original matrix 1:\n");
	for (i = 0; i < 3; i++){
                for (j = 0; j < 3; j++){
                        printf("%d\t", mat1[i][j]);
                }
                printf("\n");
        }
	printf("\nOriginal matrix 2:\n");
	for (i = 0; i < 3; i++){
                for (j = 0; j < 3; j++){
                        printf("%d\t", mat2[i][j]);
                }
                printf("\n");
        }
	printf("\nAddition:\n");
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			printf("%d(%d)\t", add[i][j], add_thread[i][j]);
		}
		printf("\n");
	}
	printf("\nSubtraction:\n");
	for (i = 0; i < 3; i++){
                for (j = 0; j < 3; j++){
                        printf("%d(%d)\t", sub[i][j], sub_thread[i][j]);
                }
                printf("\n");
        }
	printf("\nMultiplication:\n");
        for (i = 0; i < 3; i++){
                for (j = 0; j < 3; j++){
                        printf("%d(%d)\t", mul[i][j], mul_thread[i][j]);
                }
                printf("\n");
        }
	printf("\nTranspose of matrix 1:\n");
        for (i = 0; i < 3; i++){
                for (j = 0; j < 3; j++){
                        printf("%d(%d)\t", trans1[i][j], t_thread[i][j]);
                }
                printf("\n");
        }
	printf("\nTranspose of matrix 2\n");
        for (i = 0; i < 3; i++){
                for (j = 0; j < 3; j++){
                        printf("%d(%d)\t", trans2[i][j], t_thread[i][j]);
                }
                printf("\n");
        }
	return 0;
}
