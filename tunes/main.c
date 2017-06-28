#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "playlist.h"

#define PLAYLIST_SIZE 16

int main() {
  // printf("%lu\n", sizeof(song_node)); size should be 520 (256 * 2 + 8)

  // NOTE: Be sure to free all initialized pointers, either with free_list() or free()
  // Otherwise there'll be a segfault

  // VERY IMPORTANT NOTE: When using malloc to allocate memory for the nodes,
  // please be sure to set node->next to NULL.

  /* ======================
     LINKED LIST FUNCTIONS|
     ====================== */
  song_node *n = (song_node *) malloc(sizeof(song_node));
  strcpy(n->name, "Let It Go");
  strcpy(n->artist, "Idina Menzel");

  printf( "\n---------Testing Functions in linkedlist.c---------\n");

  // Print list
  printf( "Testing: print_list:\n" );
  print_list(n);

  // Test insert_front
  printf("\nTesting: insert_front\n");
  printf("Inserting Beatles song\n");
  n = insert_front(n, "Beatles", "Don't Let Me Down");

  // Add nodes
  printf( "\nAdding nodes:\n" );
  printf( "Adding: Flo Rida - Right Round\n" );
  n = insert_in_order( n, "Flo Rida", "Right Round" );
  printf( "Adding: G.R.L - Ugly Heart\n" );
  n = insert_in_order( n, "G.R.L.", "Ugly Heart" );
  printf( "Adding: Krewella - Alive\n" );
  n = insert_in_order( n, "Krewella", "Alive" );
  printf( "Adding: Adele - Hello\n" );
  n = insert_in_order( n, "Adele", "Hello" );

  // Print list again
  printf( "Testing: print_list (again):\n" );
  print_list(n);

  // Test other functions
  printf("\nLinked list size: %d\n", get_size(n));
  printf("Random song: %s\n", get_random(n)->name);
  printf("Getting artist for Let It Go: %s\n", get_song(n, "Let It Go")->artist);

  // Free list
  printf("\nFreeing the list...\n");
  n = free_list(n);

  if (n != NULL) {
    printf("Ok! n is not null!\n");
  }
  if (n == NULL) {
    printf("Ok! n is null!\n");
  }

  // Print list again
  printf("Testing: print_list (yet again):\n");
  print_list(n);

  song_node* m = (song_node*) malloc(sizeof(song_node));
  strcpy(m->name, "Legend");
  strcpy(m->artist, "Legend");
  m->next = NULL; // must be explicitly set
  //song_node* m = NULL;

  printf( "\nTesting 2: insert_in_order:\n");
  printf( "Adding: Idina Menzel - Let It Go\n" );
  m = insert_in_order( m, "Idina Menzel", "Let It Go" );
  printf( "Adding: Flo Rida - Right Round\n" );
  m = insert_in_order( m, "Flo Rida", "Right Round" );
  printf( "Adding: Krewella - Alive\n" );
  m = insert_in_order( m, "Krewella", "Alive" );
  printf( "Adding: Adele - Hello\n" );
  m = insert_in_order( m, "Adele", "Hello" );

  // Print list again
  printf("\nTesting: print_list (yet again 2):\n");
  print_list(m);

  printf( "\nTesting: get_firstsong:\n" );
  printf( "Getting: Adele\n" );
  printf( "Song: %s\n", get_firstsong( m, "Adele" )->name );

  printf( "\nTesting: remove_node:\n" );
  printf( "Removing: Hello\n" );
  m = remove_node( m, "Hello" );
  printf( "Removing: Alive\n" );
  m = remove_node( m, "Alive" );

  // Print list again
  printf("\nTesting: print_list (yet again 3):\n");
  print_list(m);

  free_list(m);

  /* ===================
     PLAYLIST FUNCTIONS|
     =================== */
  song_node* table[26] = { NULL };
  printf( "\n---------Testing Functions in playlist.c---------\n");

  printf("\nTesting add_song:\n");
  add_song(table, "Simon & Garfunkel", "Bridge over Troubled Water");
  add_song(table, "Justin Timberlake", "Can't Stop The Feeling!" );
  add_song(table, "G.R.L.", "Ugly Heart" );
  add_song(table, "Krewella", "Alive" );
  add_song(table, "Adele", "Hello" );
  add_song(table, "Eminem", "Rap God" );
  add_song(table, "Eminem", "Monster" );
  add_song(table, "Eminem", "Love The Way You Lie" );
  add_song(table, "Halsey", "Colors");
  add_song(table, "Krewella", "Legacy");
  add_song(table, "Believe", "Legend");
  add_song(table, "Elle", "Nay");
  add_song(table, "Adele", "Rolling in the Deep");
  add_song(table, "Baltimore", "Reaching for the Stars");
  printf("Songs added: %d", 14);

  printf("\nTesting print_library...\n");
  print_library(table);

  printf("\nTesting print_letter:\n");
  printf( "Letter: a\n" );
  print_letter(table, 'a');
  printf( "Letter: b\n" );
  print_letter(table, 'b');

  printf("\nTesting search_song:\n");
  printf("Artist of Colors: %s\n", search_song(table, "Colors", "Halsey")->artist);
  printf("Artist of Hello: %s\n", search_song(table, "Hello", "Adele")->artist);

  printf( "\nTesting print_artist:\n" );
  printf( "Songs by Krewella:\n" );
  print_artist( table, "Krewella" );
  printf( "Songs by Eminem:\n" );
  print_artist( table, "Eminem" );

  printf( "\nTesting find_artist:\n" );
  printf( "Finding: Krewella\n" );
  print_list( find_artist( table, "Krewella" ) );
  printf( "Finding: Eminem\n" );
  print_list( find_artist( table, "Eminem" ) );

  printf("\nTesting shuffle_print:\n");
  shuffle_print(table);

  printf( "\nTesting remove_song:\n" );
  printf( "Removing: Monster by Eminem\n" );
  remove_song( table, "Monster", "Eminem" );
  printf( "Removing: Love The Way You Lie by Eminem\n" );
  remove_song( table, "Love The Way You Lie", "Eminem" );
  printf( "Removing: Legend by Believe\n" );
  remove_song( table, "Legend", "Believe" );
  printf("\nTesting print_library after remove_song:\n");
  print_library(table);

  free_all(table);

  printf("\nTesting print_library after free_all:\n");
  print_library(table);

  return 0;
}
