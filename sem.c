#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

void main(int argc, char *argv[]){
  int id = 0;
  if (argv[1] == "-c"){
    id = semget(12345, 1, IPC_CREAT | IPC_EXCL);
    semctl(id, 0, SETVAL, argv[2]);
    if (id == -1){
      printf("semaphore already exists\n");
    }
    else{
      printf("semaphore created: %d\n", id);
    }
  }
  if (argv[1] == "-v"){
  }
}
