#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/* this function is run by the second thread */
void *foo(void *h)
{
  int i, n = 100;
  int *list = malloc(n * sizeof(int));
  
  for (i = 0; i < n; i++){
  *(list+i*sizeof(int)) = i*i;
	
  }
  printf("This is thread %d finishing 100 perfect squares", i);
  free(list);
  pthread_exit(NULL);
  return NULL;

}

int main()
{

int i;
pthread_t **threads = malloc(sizeof(pthread_t*)*10);
 
for (i=0; i<10; i++){

	if(pthread_create(&threads[i], NULL, foo, NULL)) {

		fprintf(stderr, "Error creating thread\n");
		return 1;

	}
	
}

for (i=0; i<10; i++){

	pthread_join(&threads[i], NULL);
	
}

free(*threads);



return 0;

}
