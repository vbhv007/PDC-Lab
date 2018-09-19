#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]){
	int x;
	x = 0;
	#pragma omp parallel shared(x)
	{
		#pragma omp critical
		x = x + 1;
		printf("X = %d, T = %d\n", x, omp_get_thread_num());
	}
	printf("%d\n", x);
}
