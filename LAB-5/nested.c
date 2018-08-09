#include<stdio.h>
#include<omp.h>

int main(void){
	int i, j;
	int A[5][5], B[5][5], add_thread[5][5], sub_thread[5][5], Add[5][5], Sub[5][5];
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			A[i][j] = i + j;
			B[i][j] = i - j;
			add_thread[i][j] = 0;
			sub_thread[i][j] = 0;
			Add[i][j] = 0;
			Sub[i][j] = 0;
		}
	}
	omp_set_nested(1);
	omp_set_num_threads(2);
	#pragma omp parallel
	{
		omp_set_num_threads(2);
		#pragma omp sections
		{
			for(i = 0; i < 5; i++){
				for(j = 0; j < 5; j++){
					Add[i][j] = A[i][j] + B[i][j];
					add_thread[i][j] = omp_get_thread_num();
				}
			}
		}
		#pragma omp sections
		{
			for(i = 0; i < 5; i++){
                                for(j = 0; j < 5; j++){
					Sub[i][j] = A[i][j] - B[i][j];
					sub_thread[i][j] = omp_get_thread_num();
                                }       
                        }
		}
	}
	printf("Addition\n");
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			printf("%d(%d)\t", Add[i][j], add_thread[i][j]);
		}
		printf("\n");
	}
	printf("\nSubtraction\n");
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			printf("%d(%d)\t", Sub[i][j], sub_thread[i][j]);
		}
		printf("\n");
	}
	return 1;
}	
