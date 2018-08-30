#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]){
	int x;
	x = 0;
	omp_set_num_threads(8);
	#pragma omp parallel shared(x)
	{
		#pragma omp critical
		{
			#pragma omp atomic
			x = x + 1;
			printf("%d  %d\n", x, omp_get_thread_num());
		}
	}
	//printf("%d\n", x);
}
