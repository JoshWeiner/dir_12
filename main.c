#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[]) {

  char * buf = malloc(100);
  printf("Enter directory name: ");
  fgets(buf, 100, stdin);

  while(buf[0] == '\n'){
    printf("Enter directory name: ");
    fgets(buf, 100, stdin);
 }

  buf[strlen(buf)-1] = '\0';
  DIR * ds = opendir(buf);
  if(errno){
    printf("Error: %s\n", strerror(errno));
    return 0;
  }

  if (ds < 0) {
    printf("Erorr: %s \n", strerror(errno));
    return 0;
  }
  struct dirent * entry = readdir(ds);
  struct stat * info = malloc(sizeof(struct stat));
  size_t tot_size = 0;

  while (entry) {
    printf("Name: %s\n", entry->d_name);
    stat(entry->d_name, info);
    tot_size += info->st_size;
    printf("Size: %lld \n", info->st_size);
    if (entry->d_type == 4){
      printf(" is a Directory \n");
    }
    entry = readdir(ds);
  }
  closedir(ds);

  printf("Total size (bytes): %lu \n", tot_size);
  printf("Total size (kb): %lu \n", tot_size / 1000);
  printf("Total size (mb): %lu \n", tot_size / (1000 * 1000));
  printf("Total size (gb): %lu \n", tot_size / (1000 * 1000 * 1000));

  return 0;

  struct stat *b = malloc(sizeof(struct stat));

  // printf("README.md file information \n");
  //
  // if (stat("./README.md", b) != 0) {
  //   printf("Error %s: ", strerror(errno));
  //   return 0;
  // }
  //
  // printf("File size: %lld\n", b->st_size);

}
