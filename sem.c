#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#define KEY 12345

int main(int argc, char *argv[]){
  int id = 0;
  int semval = 0;
  if (argc < 2){
    printf("need command pls\n");
    return 0;
  }
  if (strcmp(argv[1], "-c") == 0){
    if (argc < 3){
      printf("The semaphore needs a value!\n");
      return 0;
    }
    semval = atoi(argv[2]);
    if (semval < 0){
      printf("The value has to be be 0 or positive!\n");
      return 0;
    }
    id = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0644);
    if (id == -1){
      printf("semaphore already exists\n");
      return 0;
    }
    else{
      semctl(id, 0, SETVAL, semval);
      printf("semaphore created: %d\n", KEY);
      printf("value set: %d\n", semval);
      return 0;
    }
  }
  if (strcmp(argv[1], "-v") == 0){
    id = semget(KEY, 1, 0644);
    semval = semctl(id, 0, GETVAL);
    if (semval == -1){
      printf("No semaphore created yet! No value to show!\n");
      return 0;
    }
    printf("semaphore value: %d\n", semval);
    return 0;
  }
  if (strcmp(argv[1], "-r") == 0){
    id = semget(KEY, 1, 0644);
    semval = semctl(id, 0, IPC_RMID);
    if (semval == -1){
      printf("No semaphore created yet! Nothing to remove!\n");
      return 0;
    }
    printf("semaphore removed: %d\n", semval);
    return 0;
  }
  printf("Oops, the command has to be either -c, -v, or -r!\n");
  return 0;
}
