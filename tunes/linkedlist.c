#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "node.h"

void print_list(song_node* linkedList) {
  song_node* current = linkedList;
  printf("[");
  if (current) {
    while (current->next) {
      printf("%s by %s, ", current->name, current->artist);
      current = current->next;
    }
    printf("%s by %s", current->name, current->artist);
  }
  printf("]\n");
}

// Helper function for get_random
int get_size(song_node* linkedList) {
  int size = 0;
  while (linkedList) {
    size++;
    linkedList = linkedList->next;
  }
  return size;
}

song_node* get_random(song_node* linkedList) {
  if (linkedList) {
    // calculate a random element
    int size = get_size(linkedList);
    srand(time(NULL));
    int randIndex = rand() % size;
    // find the random element
    int index = 0;
    while (index != randIndex) {
      linkedList = linkedList->next;
      index++;
    }
  }
  return linkedList;
}

song_node* get_song(song_node* linkedList, char* song) {
  if (!linkedList) {
    return NULL;
  }
  song_node* current = linkedList;
  while (strcmp(song, current->name) != 0) {
    if (!current->next) {
      return NULL;
    } else {
      current = current->next;
    }
  }
  return current;
}

song_node* get_song_matching_artist(song_node* linkedList, char* song, char* artist) {
  if (!linkedList) {
    return NULL;
  }
  song_node* current = linkedList;
  int found = (strcmp(song, current->name) == 0) && (strcmp(artist, current->artist) == 0);
  while (!found) {
    if (!current->next) {
      return NULL;
    } else {
      current = current->next;
    }
    found = (strcmp(song, current->name) == 0) && (strcmp(artist, current->artist) == 0);
  }
  return current;
}

char* stringToLower(char* copy, int length) {
  int i = 0;
  char* tmp = copy;
  while (i < length) {
    *copy = tolower(*copy);
    copy++;
    i++;
  }
  return tmp;
}

song_node* insert_in_order(song_node* linkedList, char* artist, char* song) {
  song_node* ordered = (song_node*) malloc(sizeof(song_node));
  strncpy(ordered->artist, artist, sizeof(linkedList->artist));
  strncpy(ordered->name, song, sizeof(linkedList->name));

  if (!linkedList) {
    ordered->next = NULL;
    return ordered;
  }

  song_node* beginning = linkedList;
  song_node* tmp = linkedList;

  char copy[256];
  strncpy(copy, artist, 256);
  strncpy(copy, stringToLower(copy, strlen(copy)), strlen(copy));
  char copy2[256];
  strncpy(copy2, linkedList->artist, 256);
  strncpy(copy2, stringToLower(copy2, strlen(copy2)), strlen(copy2));

  while (strcmp(copy, copy2) >= 0) {
    if (strcmp(copy, copy2) == 0) {
      strncpy(copy, song, 256);
      strncpy(copy, stringToLower(copy, strlen(copy)), strlen(copy));

      strncpy(copy2, linkedList->name, 256);
      strncpy(copy2, stringToLower(copy2, strlen(copy2)), strlen(copy2));
      if (strcmp(copy, copy2) < 0) {
	if (linkedList != beginning) {
	  ordered->next = linkedList;
	  tmp->next = ordered;
	} else {
	  ordered->next = linkedList;
	  return ordered;
	}
	return beginning;
      }
      strncpy(copy, artist, 256);
      strncpy(copy, stringToLower(copy, strlen(copy)), strlen(copy));
    }
    if (linkedList->next) {
      tmp = linkedList;
      linkedList = linkedList->next;
    } else {
      linkedList->next = ordered;
      ordered->next = NULL;
      return beginning;
    }
    strncpy(copy2, linkedList->artist, 256);
    strncpy(copy2, stringToLower(copy2, strlen(copy2)), strlen(copy2));
  }

  if (linkedList != beginning) {
    ordered->next = linkedList;
    tmp->next = ordered;
  } else {
    ordered->next = linkedList;
    return ordered;
  }

  return beginning;
}

song_node* insert_front(song_node* previous, char* artist, char* song) {
  song_node* front = (song_node*) malloc(sizeof(song_node));
  strncpy(front->artist, artist, sizeof(front->artist));
  strncpy(front->name, song, sizeof(front->name));
  front->next = previous;
  return front;
}

song_node* free_list(song_node* linkedList) {
  if (!linkedList) {
    return NULL;
  }
  song_node* current = linkedList;
  song_node* tmp = current;
  while (current) {
    if (current->next) {
      tmp = current->next;
      free(current);
      current = tmp;
    } else {
      free(current);
      current = NULL;
    }
  }
  return NULL;
}

song_node* get_firstsong( song_node * linkedList, char * string ) {
  song_node* current = linkedList;

  while( current ) {
    if (strcmp( string, current->artist ) == 0) {
      return current;
    }
    current = current->next;
  }

  return NULL;
}

song_node* remove_node( song_node *linkedList, char * song ) {
  if (!linkedList) {
    return NULL;
  }

  song_node* beginning = linkedList;
  song_node* previous = NULL;

  while (strcmp(linkedList->name, song) != 0) {
    if (linkedList->next) {
      previous = linkedList;
      linkedList = linkedList->next;
    } else {
      return beginning;
    }
  }

  if (linkedList == beginning) {
    beginning = linkedList->next;
    free(linkedList);
  } else {
    previous->next = linkedList->next;
    free(linkedList);
  }
  return beginning;
}
