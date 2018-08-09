#include<omp.h>

int main(void){
	int x = 9;
	int i;
	//There are three methods -----> private, lastprivate, firstprivate
	#pragma omp parallel for firstprivate(x)
	for(i = 0; i < 5; i++){
		x = i;
		printf("X value inside parallel %d\n", x);
	}
	printf("X value %d\n", x);
	return 1;
}
