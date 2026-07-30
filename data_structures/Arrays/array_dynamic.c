/*
 * This is a simple implementation of a dynamic array.
 *
 * So, what is a dynamic array?
 * Unlike a static array, a dynamic array allows us
 * to manage the amount of stored data more flexibly.
 *
 * In this example, the array can store a variable number
 * of elements. When the array reaches its capacity,
 * its allocated memory can be resized to accommodate
 * more data.
 *
 * This implementation demonstrates:
 * - Initializing a dynamic array
 * - Adding data
 * - Searching data
 * - Displaying data
 * - Deleting data
 * - Resizing the allocated memory
 * - Freeing allocated memory
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
  char title[100];
  char author[50];
  int year;
  int page;
} Books; // elements of dynamic array

typedef struct{
  Books *data;
  size_t size;
  size_t capacity;
} DynamicArr;

void init_array(DynamicArr *arr, size_t capacity){

  if (capacity == 0){
    capacity = 1;
  }

  arr->data = malloc(capacity * sizeof(Books));


  if (arr->data == 0){
    fprintf(stderr, "memory allocation failed!\n");
    exit(EXIT_FAILURE);
  }

  arr->capacity = capacity;
  arr->size = 0;
}

Books create_book(char title[], char author[], int year, int page){

  Books book;

  strncpy(book.title, title, sizeof(book.title));
  book.title[sizeof(book.title) - 1] = '\0';

  strncpy(book.author, author, sizeof(book.author));
  book.author[sizeof(book.author) - 1] = '\0';

  book.year = year;
  book.page = page;

  return book;
}

void add_book(DynamicArr *arr, Books book){

  if (arr->size >= arr->capacity){
    
    arr->capacity *= 2;
    Books *temp = realloc(arr->data, arr->capacity * sizeof(Books));

    if (temp == NULL){
      fprintf(stderr, "reallocation memory failed!\n");
      exit(EXIT_FAILURE);
    }
    arr->data = temp;
  }

  arr->data[arr->size] = book;
  arr->size++;
  printf("add book succesfully!\n");
}

void show_book_list(const DynamicArr *arr){

  if (arr->data == NULL || arr->data == 0){
    fprintf(stderr, "book list is empty\n");
    return;
  }

  for (size_t i = 0; i < arr->size; i++){
    printf("%zu->title: %s||author: %s||year: %d||pages: %d\n",i + 1, arr->data[i].title, arr->data[i].author, arr->data[i].year, arr->data[i].page);
  }
}

bool search_book(const DynamicArr *arr, char title[]){
  
  for (size_t i = 0; i < arr->size; i++){

    if (strncmp(arr->data[i].title, title, sizeof(arr->data[i].title)) == 0){

      printf("book info:\n");
      printf("author: %s||year: %d||pages: %d\n", arr->data[i].author, arr->data[i].year, arr->data[i].page);

      return true;
    }
  }

  fprintf(stderr, "book not found!\n");
  return false;
}

void delete_books(DynamicArr *arr, char title[]){

  for (size_t i = 0; i < arr->size; i++){
    
    if (strncmp(arr->data[i].title, title, sizeof(arr->data[i].title)) == 0){

      printf("\ndelete book [%s] succesfully!\n", arr->data[i].title);

      for (size_t j = i; j < arr->size - 1; j++){
        arr->data[j] = arr->data[j + 1];
      }
      arr->size--;

      return;
    }
  }
  fprintf(stderr, "\nbook not found, nothing deleted\n");
}

void free_mem(DynamicArr *arr){

  free(arr->data);
  arr->data = NULL;
  arr->size = 0;
  arr->capacity = 0;

  printf("\nmemory has been freed!\n");
}

int main(void){

  DynamicArr arr;
  init_array(&arr, 2);

  Books b1 = create_book("buku komik", "vyan", 1999, 101);
  Books b2 = create_book("buku novel", "jajang", 2022, 102);
  Books b3 = create_book("buku sejarah", "davy", 1980, 354);

  add_book(&arr, b1);
  add_book(&arr, b2);
  add_book(&arr, b3);

  printf("\n======book list=======\n");
  show_book_list(&arr);

  delete_books(&arr, "buku novel");
  show_book_list(&arr);

  printf("===search_book===\n");
  search_book(&arr, "buku komik");
  free_mem(&arr);
  show_book_list(&arr); // if you call function show_book_list here, it will display
                        // 'book list is empty' because the memory previously used
                        // by the dynamic array has been freed. the array no longer
                        // contains any active book data
  return 0;
}
