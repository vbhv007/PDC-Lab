#include <stdio.h>
#include <omp.h>

int main(void){
	int i, j, k, sum;
	int mat1[2][2] = {{1, 2}, {3, 4}};
	int mat2[2][2] = {{5, 6}, {7, 8}};
	int add[2][2];
	int sub[2][2];
	int mul[2][2];
	int trans1[2][2];
	int trans2[2][2];
	#pragma omp parallel
	{
		#pragma omp sections
		{
			for (i = 0; i < 2; i++){
				for (j = 0; j < 2; j++){
					add[i][j] = mat1[i][j] + mat2[i][j];
				}
			}
		}
		#pragma omp sections
                {
                        for (i = 0; i < 2; i++){
                                for (j = 0; j < 2; j++){
                                        sub[i][j] = mat1[i][j] - mat2[i][j];
                                }
                        }
                }
		#pragma omp sections
                {
                        for (i = 0; i < 2; i++){
                                for (j = 0; j < 2; j++){
					sum = sum + mat1[i]
                                }
                        }
                }
		#pragma omp sections
                {
                        for (i = 0; i < 2; i++){
                                for (j = 0; j < 2; j++){
                                        trans1[i][j] = mat1[j][i];
					trans2[i][j] = mat2[j][i];
				}
                        }
                }

	}
	printf("Original matrix 1:\n\n");
	for (i = 0; i < 2; i++){
                for (j = 0; j < 2; j++){
                        printf("%d\t", mat1[i][j]);
                }
                printf("\n");
        }
	printf("Original matrix 2:\n\n");
	for (i = 0; i < 2; i++){
                for (j = 0; j < 2; j++){
                        printf("%d\t", mat2[i][j]);
                }
                printf("\n");
        }
	printf("Addition:\n\n");
	for (i = 0; i < 2; i++){
		for (j = 0; j < 2; j++){
			printf("%d\t", add[i][j]);
		}
		printf("\n");
	}
	printf("Subtraction:\n\n");
	for (i = 0; i < 2; i++){
                for (j = 0; j < 2; j++){
                        printf("%d\t", sub[i][j]);
                }
                printf("\n");
        }
	printf("Multiplication:\n\n");
        for (i = 0; i < 2; i++){
                for (j = 0; j < 2; j++){
                        printf("%d\t", mul[i][j]);
                }
                printf("\n");
        }
	printf("Transpose of matrix 1:\n\n");
        for (i = 0; i < 2; i++){
                for (j = 0; j < 2; j++){
                        printf("%d\t", trans1[i][j]);
                }
                printf("\n");
        }
	  printf("Transpose of matrix 2\n\n");
        for (i = 0; i < 2; i++){
                for (j = 0; j < 2; j++){
                        printf("%d\t", trans2[i][j]);
                }
                printf("\n");
        }
	return 0;
}
