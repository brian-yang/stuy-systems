#include <stdlib.h>
#include <stdio.h>
#include "node.h"

#define LL_SIZE 20

void print_list(struct node* linkedList);
struct node* insert_front(struct node* previous, int value);
struct node* free_list(struct node* start);

int main()
{
  // Create first element in list
  struct node* first = (struct node*) malloc(sizeof(struct node*));
  first->i = 5;
  first->next = NULL;
  //struct node* first = NULL;

  // Insert random elements into the list
  int i;
  srand(time(NULL));
  for (i = 0; i < LL_SIZE; i++) {
    first = insert_front(first, rand() % 100);
  }

  // Test functions
  print_list(first);
  printf("\nFreeing memory allocated to list...\n");
  first = free_list(first);
  printf("Done freeing memory.\n");
  printf("Start Address: %p\n\n", first);
  print_list(first);

  return 0;
}

void print_list(struct node* linkedList) {
  int index = 0;
  while (linkedList != NULL) {
    printf("Element #%d: %d\n", index, linkedList->i);
    linkedList = linkedList->next;
    index++;
  }
}

struct node* insert_front(struct node* previous, int value) {
  struct node* front;
  front = (struct node*) malloc(sizeof(struct node));
  front->i = value;
  front->next = previous;
  return front;
}

struct node* free_list(struct node* start) {
  if (start != NULL) {
    struct node* current = start;
    while (current != NULL) {
      // printf("Current Address: %p\n", current);
      free(current);
      current = current->next;
    }
    // start = NULL;
  }
  return start;
}
