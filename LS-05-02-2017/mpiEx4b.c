#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	long sum, sumTotal, upToVal;
	int start, end, size, rank;
	MPI_Status Stat;

	upToVal = 100000;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int cs = upToVal / size;

	// Defina aqui el segmento que debe procesar una tarea
	// El inicio del segmento en la variable 'start', el fin del segmento
	// la variable 'end'
    sum = 0;
    for(int i=cs*rank+1; i<= cs*(rank+1); i++){
    	sum = sum + i;
    }
	printf("El proceso %d calcule el valor %li - %li, Suma parcial: %li\n", rank, (long)cs*rank+1, (long)cs*(rank + 1), sum);
	fflush(stdout);
	MPI_Reduce(&sum, &sumTotal, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD);
	if(rank == 0){
		printf("Total con reduce: %li\n", sumTotal);
	}


	MPI_Finalize();
	
	return 0;
}



