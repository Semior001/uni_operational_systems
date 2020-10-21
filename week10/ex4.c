#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main() {
  DIR *dirp = opendir("tmp");
  struct dirent *dp;

  int size = 0;
  while ((dp = readdir(dirp)) != NULL){
		size++;
	}

  closedir(dirp);

  int* inodes = calloc(size, sizeof(int));
	char** fnames = calloc(size * size, 256);

  dirp = opendir("tmp");
  size = 0;
  while ((dp = readdir(dirp)) != NULL){
	  inodes[size] = dp -> d_ino;
    fnames[size] = dp -> d_name;
    size++;
	}

  (void) closedir(dirp);

  int i, j;
  for (i = 0; i < size; i++) {
    if (inodes[i] == -1)
      continue;

    int count = 0;
    int* ids = calloc(size, sizeof(int));
    for (j = 0; j < size; j++) {
      if (inodes[i] == inodes[j]) {
        ids[count] = j;
        count++;
      }
    }

    if (count > 1) {
      inodes[i] = -1;

      int k;
      for (k = 0; k < count; k++)
        printf("%s ", fnames[ids[k]]);
      printf("\n");
    }
  }
  return 0;
}