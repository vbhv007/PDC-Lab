#include <stdio.h>
#include <omp.h>

int main(void){
	int n, estart = 0, ostart = 1, i;
	printf("Enter n: ");
	scanf("%d", &n);
	#pragma omp parallel sections
	{
		#pragma omp section
		{
			#pragma omp parallel for
			for(i = 0; i < n; i++){
				printf("%d(%d)\t", estart + 2, omp_get_thread_num());
				estart += 2;
			}
			printf("\n");
		}
		#pragma omp section
		{
			#pragma omp parallel for
			for(i = 0; i < n; i++){
				printf("%d(%d)\t", ostart + 2, omp_get_thread_num());
				ostart += 2;
			}
			printf("\n");
		}
	}
	return 0;
}
