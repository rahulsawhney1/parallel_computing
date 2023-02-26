/* Author: Mark Ebersole � NVIDIA Corporation  */
/* Source: https://developer.nvidia.com/cuda-education  */

#include <stdio.h>
#include <cuda.h>


__global__ printing(){
 __shared__ int x = 7;
 if(blockIdx.x > 0)
 printf("%d", blockIdx.x);
 else
 printf("x");
 __synchthreads();
 printf("%d", threadIdx.x);
} 
int main(void)
{
	
	printing<<<3,2>>>();
	cudaDeviceSynchronize();

	return 0;
}