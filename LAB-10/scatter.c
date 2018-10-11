#include<stdio.h>
#include<mpi.h>

int main(int argc, char* argv[]){
	MPI_Init(&argc, &argv);
	int rank, size;
	int data[6], i, local[2];
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank == 0){
		for(i = 0; i < 6; i++){
			printf("\nEnter any number: ");
			scanf("%d", &data[i]);
		}		
	}
	MPI_Scatter(data, 2, MPI_INT, local, 2, MPI_INT, 0,  MPI_COMM_WORLD);
	if(rank == 1){
		printf("Number recieved by process %d: %d, %d. Adding the numbers, Sum: %d\n", rank, local[0], local[1], local[0]+local[1]);
	}
	if(rank == 2){
		printf("Number recieved by process %d: %d, %d. Subtracting the numbers, Sub: %d\n", rank, local[0], local[1], local[0]-local[1]);
	}
	if(rank == 3){
                printf("Number recieved by process %d: %d, %d. Multiplying the numbers, Mul: %d\n", rank, local[0], local[1], local[0]*local[1]);
        }
	MPI_Finalize();
	return 0;
} 
