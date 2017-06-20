#include <pthread.h>
#include <stdio.h>


int shared_var = 0;
pthread_mutex_t mutex_shared_var;


void *worker_function1(void* arg)
{
  int acc1 = 0;
  for (int i=0; i<1000; i++)
    acc1 += i;
  
  pthread_mutex_lock(&mutex_shared_var);
  shared_var += acc1;
  pthread_mutex_unlock(&mutex_shared_var);

  pthread_exit((void *)0);
  
}

void *worker_function2(void *arg)
{
  int acc2 = 0;
  for (int i=0; i<950; i++)
    acc2 += 1;
  
  pthread_mutex_lock(&mutex_shared_var);
  shared_var += acc2;
  pthread_mutex_unlock(&mutex_shared_var);

  pthread_exit((void *)0);
  
}

int main(int argc, char **argv)
{
  pthread_t thread1, thread2;
  void *status;
  
  pthread_mutex_init(&mutex_shared_var, NULL);

  pthread_create(&thread1, NULL, worker_function1, NULL);
  pthread_create(&thread2, NULL, worker_function2, NULL);
  pthread_join(thread1, &status);
  pthread_join(thread2, &status);

  fprintf (stderr, "shared_var is %d\n", shared_var);

  return 0;
  
}
