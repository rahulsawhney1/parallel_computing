#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


int main(int argc, char *argv[]){
  
    unsigned int x, A, B;
    unsigned int i; //loop index

    A = 2;
    B = 10;
    x = 3;
    for (i = A; i <=B; i++) {
        if (i / x == 0) {
            printf("%d\n", i);
        }
    }
    return 0;
}
