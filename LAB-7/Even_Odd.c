#include<stdio.h>
#include<omp.h>
void main()
{
	int n,i,even=0,odd=1;
	printf("Enter N:");
	scanf("%d",&n);

	printf("Even Numbers are :\n");
	#pragma omp parallel for ordered num_threads(4)
	for(i=0;i<n;i++)
	{
		#pragma omp ordered
		printf("Number: %d  Thread: %d\n",even,omp_get_thread_num());
		even+=2;
	}
	
	printf("\nOdd numbers are : \n");
	#pragma omp parallel for ordered num_threads(4)
	for(i=0;i<n;i++)
	{
		#pragma omp ordered
		printf("Number: %d  Thread: %d\n",odd,omp_get_thread_num());
		odd+=2;
	}
}
