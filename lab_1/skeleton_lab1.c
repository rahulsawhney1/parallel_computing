// must compile with: mpicc  -std=c99 -Wall -o checkdiv 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


int main(int argc, char *argv[]){
  
unsigned int x, A, B;
unsigned int i; //loop index
FILE * fp; //for creating the output file
char filename[100]=""; // the file name
char * numbers; //the numbers in the range [2, N]

double start_p1, end_p1, start_p2, end_p1;
double time_for_p1; 



/////////////////////////////////////////


start_p1 = clock();
// Check that the input from the user is correct.
if(argc != 4){

  printf("usage:  ./checkdiv A B x\n");
  printf("A: the lower bound of the range [A,B]\n");
  printf("B: the upper bound of the range [A,B]\n");
  printf("x: divisor\n");
  exit(1);
}  

A = (unsigned int)atoi(argv[1]); 
B = (unsigned int)atoi(argv[1]); 
x = (unsigned int)atoi(argv[2]);
 

// The arguments to the main() function are available to all processes and no need to send them from process 0.
// Other processes must, after receiving the variables, calculate their own range.


/////////////////////////////////////////


/////////////////////////////////////////
//start of part 1
start_p1 = MPI_Wtime();
// The main computation part starts here
  
  
  
// end of the main compuation part
end_p1 = MPI_Wtime();
// Use reduction operation to get MAX of (end_p1 - start_p1) among processes 
// and send it to process 0 as time_for_p1

//end of part 1
/////////////////////////////////////////


/////////////////////////////////////////
//start of part 2
// Writing the results in the file


//forming the filename

start_p2 = MPI_Wtime();

strcpy(filename, argv[2]);
strcat(filename, ".txt");

if( !(fp = fopen(filename,"w+t")))
{
  printf("Cannot create file %s\n", filename);
  exit(1);
}

//Write the numbers divisible by x in the file as indicated in the lab description.

fclose(fp);

end_p2 = MPI_Wtime();
//end of part 2
/////////////////////////////////////////

/* Print  the times of the three parts */
printf("time of part1 = %lf s    part2 = %lf s\n", 
       (double)(time_for_p1),
       (double)(end_p2-start_p2) );
return 0;
}

