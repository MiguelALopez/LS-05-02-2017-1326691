#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	int i, sum, sumTotal, upToVal, tag=1;
	int start, end, size, rank;
	int inmsg = 0;
	MPI_Status Stat;

	upToVal = 10000;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int cs = upToVal / size;

	// Defina aqui el segmento que debe procesar una tarea
	// El inicio del segmento en la variable 'start', el fin del segmento
	// la variable 'end'
    	sum = 0;
    	for(i=cs*rank+1; i<= cs*(rank+1); i++){
    		sum = sum + i;
    	}
	printf("El proceso %d calcule el valor %d - %d, Suma parcial: %d\n", rank, cs*rank+1, cs*(rank + 1), sum);
	fflush(stdout);
	if(rank == 0){
		for(int i = 1; i <size; i++){
			MPI_Recv(&inmsg, 1, MPI_INT, i, tag, MPI_COMM_WORLD, &Stat);
			sum += inmsg;
		}
		sumTotal = sum;
		printf ("\nTotal: %d\n",sumTotal);
	}else{
		MPI_Send(&sum, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
	}
	// Utilice la funcion 'MPI_Reduce' para guardar en la variable 
	// 'sumTotal' la suma parcial de todos las tareas 

	MPI_Finalize();
	
	return 0;
}



