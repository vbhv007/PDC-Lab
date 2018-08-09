#include<stdio.h>
#include<omp.h>

int main(void){
	long i, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
	int thread[4];
	#pragma omp parallel
	{
		#pragma omp sections
		{
			for(i = 20000; i < 22500; i++){
				sum1 += i;
				thread[0] = omp_get_thread_num();
			}
		}
		#pragma omp sections
		{
                        for(i = 22500; i < 25000; i++){
                                sum2 += i;
                                thread[1] = omp_get_thread_num();
                        }
                }
		#pragma omp sections
		{
                        for(i = 25000; i < 27500; i++){
                                sum3 += i;
                                thread[2] = omp_get_thread_num();
                        }
                }
		#pragma omp sections
		{
                        for(i = 27500; i < 30000; i++){
                                sum4 += i;
                                thread[3] = omp_get_thread_num();
                        }
                }
	}
	printf("Sum from 20000 to 22500 = %ld with T = %d\n", sum1, thread[0]);
	printf("Sum from 22500 to 25000 = %ld with T = %d\n", sum2, thread[1]);
	printf("Sum from 25000 to 27500 = %ld with T = %d\n", sum3, thread[2]);
	printf("Sum from 27500 to 30000 = %ld with T = %d\n", sum4, thread[3]);
	return 1;
}
