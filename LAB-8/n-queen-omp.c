#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>

#include <omp.h>

#define MAX_N 4

int check_acceptable(int queen_rows[MAX_N], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if (queen_rows[i] == queen_rows[j]) return 0;
		}
	}

	return 1;
}

int main(int argc, char* argv[])
{
    int n;
    int max_iter = 1;

    double start_time, end_time;
    int number_solutions = 0;

	{
	    int num_workers;
        int i;

        n = (argc > 1) ? atoi(argv[1]) : 4;
        num_workers = (argc > 2) ? atoi(argv[2]) : 30;

        omp_set_num_threads(num_workers);

        for (i = 0; i < n; i++)
        {
            max_iter *= n;
        }
    }

    start_time = omp_get_wtime();

	int iter;
#pragma omp parallel for
	for (iter = 0; iter < max_iter; iter++)
	{
		int code = iter;
		int i;
	    int queen_rows[MAX_N];
		for (i = 0; i < n; i++)
		{
			queen_rows[i] = code % n;

			code /= n;
		}

		if (check_acceptable(queen_rows, n))
		{
#pragma omp atomic
		    number_solutions++;

		}
	}

    printf("Number of found solutions is %d\n", number_solutions);

	return 0;
}
