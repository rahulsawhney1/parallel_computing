#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <omp.h>


int main(int argc, char *argv[]){

    int b, t;
    double range;


    if(argc != 4){

        printf("usage:  ./histogram  b t filename\n");
        printf("b: number of bins\n");
        printf("t: number of threads\n");
        printf("filename: name of file containing numbers\n");
        exit(1);
    }  

    b = (int) atoi(argv[1]);
    t = (int) atoi(argv[2]);

    //check if bins/threads in acceptable range
    if ((b <= 0) || (b > 50)) {
        printf("invalid number of bins");
        exit(1);
    }
    if ((t <= 0) || (b > 100)) {
        printf("invalid number of threads");
        exit(1);
    }

    range = (double) 100/b;
    char filename[100]="";
    strcpy(filename, argv[3]);
    
    FILE *fp;
    fp = fopen(filename, "r");
    double myvar;
    int count;

    //read first value to get count
    fscanf(fp,"%d",&count);
    double* numbers = (double*) malloc(count * sizeof(double));
    int* counts = (int*) malloc(b * sizeof(int));

    //despite using malloc, was getting strange values in the array, so manually set them. 
    for (int a = 0; a < b; a++) {
        counts[a] = 0;
    }
    
    for (int j = 0; j < count; j++) {
        fscanf(fp, "%lf", &myvar); 
        numbers[j] = myvar;
    }

    fclose(fp);

    double t0 = omp_get_wtime();
    double t1;
    int bin_number;
    for (int k = 0; k < count; k++) {
        bin_number = numbers[k] / range;
        counts[bin_number]++; 
    }

    t1 = omp_get_wtime();
    

    for (int c = 0; c < b; c++){
        printf("Bin[%d]=%d\n", c, counts[c]);
    }

    printf("CPU time used: %f sec\n", t1-t0);
    
}