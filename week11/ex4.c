#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define FILE_READ "ex1.txt"
#define FILE_WRITE "ex1.memcpy.txt"

int main() {
  int fRead = open(FILE_READ, O_RDWR);
  int fWrite = open(FILE_WRITE, O_RDWR);

  struct stat buf;
  fstat(fRead, &buf);
  int sz = buf.st_size;

  ftruncate(fWrite, sz);
  char * mapping_read = mmap(NULL, sz, PROT_READ, MAP_SHARED, fRead, 0);
  char * mapping_write = mmap(NULL, sz, PROT_WRITE, MAP_SHARED, fWrite, 0);

  memcpy(mapping_write, mapping_read, sz);

  close(fRead);
  close(fWrite);
  munmap(mapping_read, sz);
  munmap(mapping_write, sz);
  return 0;
}