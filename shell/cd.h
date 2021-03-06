/*
   @params: takes a char* dir which is the name of the directory to cd into
   @return: returns nothing
   @purpose: implements the cd terminal command for our custom shell
 */
int cd(char* dir);
void chdir_with_tilde(char* dir);
void pwd(char* cur_dir);
