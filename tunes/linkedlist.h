#include "node.h"

void print_list(song_node* linkedList);

int get_size(song_node* linkedList); // helper function for get_random
song_node* get_random(song_node* linkedList);

song_node* get_song(song_node* linkedList, char* song);
song_node* get_song_matching_artist(song_node* linkedList, char* song, char* artist);

char* stringToLower(char* copy, int length); // helper function for stringToLower
song_node* insert_in_order(song_node* linkedList, char* artist, char* song);
song_node* insert_front(song_node* previous, char* artist, char* song);

song_node* free_list(song_node* linkedList);
song_node* remove_node( song_node *linkedList, char * song );

song_node* get_firstsong( song_node * linkedList, char * string );
