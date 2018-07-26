#include <stdio.h>
#include <omp.h>

int main(void){
	printf("Using Schedule");
	int i, j, k;
	int mat1[2][2] = {{1, 2}, {3, 4}};
	int mat2[2][2] = {{5, 6}, {7, 8}};
	int ans[2][2];
	#pragma omp parallel
	{
		#pragma omp parallel for schedule(dynamic, 10)
		for (i = 0; i < 2; i++){
			for (j = 0; j < 2; j++){
				ans[i][j] = mat1[i][j] + mat2[i][j];
			}
		}
	}
	for (i = 0; i < 2; i++){
		for (j = 0; j < 2; j++){
			printf("%d\t", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
