#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "linkedlist.h"

song_node* add_song(song_node** table, char* artist, char* song) {
  int i = tolower(*artist) - 97;
  if (table[i] == NULL) {
    table[i] = (song_node*) malloc(sizeof(song_node));
    strncpy((table[i])->name, song, sizeof((table[i])->name));
    strncpy((table[i])->artist, artist, sizeof((table[i])->artist));
    (table[i])->next = NULL;
    return table[i];
  }
  table[i] = insert_in_order(table[i], artist, song);
  return table[i];
}

song_node* search_song(song_node** table, char* song, char* artist) {
  int i = tolower( artist[0] ) - 97;
    song_node* discovery = get_song_matching_artist(table[i], song, artist);
    if (discovery) {
      return discovery;
    }
  return NULL;
}

void print_library(song_node** table) {
  int i;
  for (i = 0; i < 25; i++) {
    printf("%c: ", i + 97);
    print_list(*table);
    table++;
  }
  printf("%c: ", i + 97);
  print_list(*table);
}

void print_letter(song_node** table, char L ) {
  char l = tolower(L);
  int i = (l - 97);
  table = table + i;
  print_list(*table);
}

void print_artist( song_node** table, char* s ) {
  int i = tolower( s[0] ) - 97;
  song_node* temp = table[i];

  printf( "[" );

  if( temp ) {
    while( temp->next ) {
      if( strcmp(temp->artist, s) == 0 ) {
	printf( "%s by %s, ", temp->name, temp->artist);
      }
      temp = temp -> next;
    }

    if( strcmp(temp->artist, s) == 0 ) {
      printf( "%s by %s", temp->name, temp->artist);
    }
  }

  printf("]\n");
}


song_node* find_artist( song_node** table, char* s) {
  int i = tolower( s[0] ) - 97;
  song_node* temp = table[i];
  song_node* songsByartist = NULL;

  if( temp ) {
    while( temp->next ) {
      if( strcmp(temp->artist, s) == 0 ) {
	songsByartist = insert_in_order(songsByartist, s, temp->name);
      }

      temp = temp -> next;
    }

    if( strcmp(temp->artist, s) == 0 ) {
      songsByartist = insert_in_order(songsByartist, s, temp->name);
    }
  }

  return songsByartist;
}

int num_linkedlists(song_node** table) {
  int i;
  int num_lists = 0;
  for (i = 0; i < 26; i++) {
    if (*table) {
      num_lists++;
    }
    table++;
  }
  return num_lists;
}

void shuffle_print(song_node** table) {
  int num_lists = num_linkedlists(table);
  srand(time(NULL));
  int rand_lists = rand() % num_lists;

  printf("Number of lists to select random songs from: %d\n", rand_lists);

  int num_songs;
  int i;
  song_node* list;

  while (rand_lists > 0) {
    if (*table) {
      list = *table;
      num_songs = (rand() % get_size(list)) + 1;
      //printf("Number of random songs chosen: %d\n", num_songs);

      for (i = 0; i < num_songs; i++) {
	printf("Shuffled song: %s by %s \n", list->name, list->artist);
	if (list->next) {
	  list = list->next;
	}
      }

      rand_lists--;
    }
    table++;
  }
}

song_node* remove_song( song_node** table, char* song, char* artist ) {
  int i = tolower( artist[0] ) - 97;
  table[i] = remove_node( table[i], song);
  return table[i];
}

int free_all(song_node** table) {
  int i;
  for (i = 0; i < 26; i++) {
    if (*table) {
      *table = free_list(*table);
    }
    table++;
  }
  return 0;
}
