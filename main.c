#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>

int main() {
  DIR * ds = opendir(".");

  if (ds < 0) {
    printf("Erorr: %s \n", strerror(errno));
    return 0;
  }
  struct dirent * entry = readdir(ds);
  

    while (entry) {
    printf("Name: %s\n", entry->d_name);
    if (entry->d_type == 4){
      printf(" is a Directory \n");
    }


    entry = readdir(ds);
  }
  closedir(ds);

  return 0;

  struct stat *b = malloc(sizeof(struct stat));

  // printf("README.md file information \n");

  if (stat("./README.md", b) != 0) {
    printf("Error %s: ", strerror(errno));
    return 0;
  }

  printf("File size: %ld\n", b->st_size);

}
