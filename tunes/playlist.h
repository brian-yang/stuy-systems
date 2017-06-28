#include "linkedlist.h"

song_node* add_song(song_node** table, char* artist, char* song);

void print_library(song_node** table);
void print_letter(song_node** table, char L );
void print_artist( song_node** table, char* s );

song_node* find_artist( song_node** table, char* s);
song_node* search_song(song_node** table, char* song, char* artist);

int num_linkedlists(song_node** table); // helper functon for shuffle_print
void shuffle_print(song_node** table);

int free_all(song_node** table);
song_node* remove_song( song_node** table, char* song, char* artist );
