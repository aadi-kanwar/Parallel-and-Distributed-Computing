#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100
#define THREADS 4
int main()
{
  int arr[N];
  long long sum = 0;
  // Initialize the array
  for (int i = 0; i < N; i++)
  {
    arr[i] = i;
  }
  omp_set_num_threads(THREADS);
  double start_time = omp_get_wtime();
  
  #pragama omp parallel
  {
	  int thread_id = omp_get_thread_num();
	  long long local_sum = 0;
	  
	  int chunk_size = N / THREADS;
	  
	  int start = thread_id * chunk_size;
	  
	  int end = (thread_id == THREADS -1)? N : start + chunk_size;
	  
	  for(int i = start; i < end; i++)
	  {
	    local_sum +=array[i];
	  }
	  sum += local_sum;
  }
}
