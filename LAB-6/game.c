#include<stdio.h>
#include<omp.h>

int main(void){
	int n = 9, i, j, count = 0;
	//printf("Enter value of n: ");
	//scanf("%d", &n);
	//int A[n][n];
	//for(i = 0; i < n; i++){
	//	for(j = 0; j < n; j++){
			//printf("\nEnter value of element (%d, %d): ", i, j);
		       	//scanf("%d", &A[i][j]);
	//	}
	//}
	int A[9][9] = {{0, 1, 1, 1, 0, 2, 1, 0, 0}, {0, 2, 1, 1, 0, 2, 1, 2, 2},
		{0, 1, 1, 0, 2, 2, 0, 1, 1}, {1, 1, 1, 0, 2, 1, 0, 0, 0},
		{1, 1, 2, 0, 0, 2, 2, 2, 1}, {1, 0, 0, 0, 2, 1, 2, 1, 1},
		{0, 1, 1, 1, 0, 1, 1, 1, 0}, {2, 1, 0, 0, 1, 1, 2, 1, 2},
		{1, 2, 2, 0, 1, 2, 0, 2, 1}};
	#pragma omp parallel
	{
	#pragma omp sections
	{
		#pragma omp parallel for
		for(i = 0; i < (n - 1); i++){
			for(j = 0; j < (n - 2); j++){
				if((A[i][j] == A[i][j+1]) && (A[i][j+1] == A[i][j+2])){
					count++;
					printf("%d, %d(l2r), T = %d\n", i, j, omp_get_thread_num()); 	
				}
			}
		}
	}
	#pragma omp sections
	{
		#pragma omp parallel for
		for(i = 0; i < (n - 2); i++){
                	for(j = 0; j < (n - 1); j++){
                        	if((A[i][j] == A[i+1][j]) && (A[i+1][j] == A[i+2][j])){
                                	count++;
                                	printf("%d, %d(t2b), T = %d\n", i, j, omp_get_thread_num());
                        	}
                	}
        	}
	}
	}
	printf("Total: %d\n", count);
	return 0;
}	

