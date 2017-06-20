#include <pthread.h>
#include <stdio.h>


int shared_var = 0;

void *worker_function1(void* arg)
{
  int acc1 = 0;
  for (int i=0; i<1000; i++)
    acc1 += i;
  
  shared_var += acc1;
  
  return 0;
}

void *worker_function2(void *arg)
{
  int acc2 = 0;
  for (int i=0; i<950; i++)
    acc2 += 1;
  
  shared_var += acc2;
  
  return 0;
}

int main(int argc, char **argv)
{
  pthread_t thread1, thread2;
  void *status;
  
  worker_function1(NULL);
  worker_function2(NULL);
  
  fprintf (stderr, "shared_var is %d\n", shared_var);

  return 0;
  
}
