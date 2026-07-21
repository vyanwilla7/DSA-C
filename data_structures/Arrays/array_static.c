/*
 * This is a simple implementation example of a static array.
 *
 * So, what is a static array?
 * A static array is an array whose size is determined and remains fixed throughout the program's execution.
 *
 * In this example, the array can store a maximum of 36 Students.
 * The `count` variable tracks the number of elements currently in use.
 *
 * This implementation demonstrates:
 * - Adding data
 * - Searching data
 * - Displaying data
 * - Deleting data
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <strings.h>

#define MAX 36

typedef struct{
  int id;
  char name[100];
  char class[4];
  int age;
} Students;

void add_member(Students st[], int *count, char name[], char cls[], int age, int id){
  if (*count >= MAX){
    fprintf(stderr,"The number of students exceeds the limit!\n");
    return;
  }

  st[*count].age = age;
  st[*count].id = id;

  strncpy(st[*count].name, name, 100 - 1);
  st[*count].name[100 - 1] = '\0';

  strncpy(st[*count].class, cls, 4 - 1);
  st[*count].class[4 - 1] = '\0';

  printf("data successfully added!\n");
  printf("------------------------\n");

  (*count)++;
}

bool find_data(const Students st[], int count, int id){

  for (int i = 0; i < count; i++){

    if (id == st[i].id){
      printf("found data!\n");
      printf("Name: %s|| Age: %d|| Class: %s\n", st[i].name, st[i].age, st[i].class);

      return true;
    }
  }

  fprintf(stderr, "data not found!\n");
  return false;
}

void show_data(const Students st[], int count){

  if (count <= 0){
    fprintf(stderr, "data is empety\n");
    return;
  }

  for (int i = 0; i < count; i++){
    printf("no: %d||Name: %s||age: %d||id: %d||class: %s\n", i + 1, st[i].name, st[i].age, st[i].id, st[i].class);
  }

}

void delete_data(Students st[], int *count, int id){

  for (int i = 0; i < *count; i++){

    if (id == st[i].id){

      for (int j = i; j < *count - 1; j++){
        // shift the deleted value to the left
        st[j] = st[j + 1];
      }
        // reduce the number of elements
      (*count)--;

      printf("delete successfully!\n");
      return;
    }
  }
  fprintf(stderr, "data not found, nothing deleted\n");
}

int main(void){

  Students st[MAX];
  int index = 0;

  add_member(st, &index, "vyann", "XII", 17, 2026123);
  add_member(st, &index, "ahmad", "XII", 17, 2026124);
  show_data(st, index);

  find_data(st, index,2026123);
  delete_data(st, &index, 2026124);
  show_data(st, index);

  return 0;
}
