#include <stdio.h>
#include <omp.h>

int main(void){
	int n, sum = 0, i;
	printf("Enter n: ");
	scanf("%d", &n);
	#pragma omp parallel num_threads(3)
	{
		#pragma omp for ordered
		for(i = 0; i < n; i++){
			sum += i;
			#pragma omp ordered
			{
				printf("\n%d run by thread %d", i, omp_get_thread_num());
			}
		}
		printf("\n%d", sum);
	}
	return 0;
}
