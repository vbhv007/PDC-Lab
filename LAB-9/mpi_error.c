#include<stdio.h>
#include<mpi.h>

int main(int argc, char *argv[]){
	const int tag = 42;
	int id, ntask, source_id, dest_id, err, i;
	MPI_Status status;
	int msg[2];

	err = MPI_Init(&argc, &argv);
	if (err != MPI_SUCCESS){
		printf("MPI initialization failed!\n");
		exit(1);
	}
	MPI_Comm_size(MPI_COMM_WORLD, &ntask);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);

	if (ntask < 2){
		printf("You have to use at least 2 processors to run this program\n");
		MPI_Finalize();
		exit(0);
	}
}
