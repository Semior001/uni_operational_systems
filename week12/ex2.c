#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    char buf[MAX_SIZE];
    int is_a = (argc > 1) && (strlen(argv[1]) >= 2) && (argv[1][0] == '-') && (argv[1][1] == 'a');
    int is_stdout = (argc == 1);
    const int file_count = (is_stdout) ? 1 : argc - is_a - 1;
    int *files = (int *) malloc(sizeof(int) * file_count ) ;

    if (is_stdout) {
        files[0] = STDOUT_FILENO;
    } else {
        for (int i = 0; i < argc - is_a - 1; ++i) {
            files[i] = is_a ?
                       open(argv[i + 2], O_CREAT | O_WRONLY | O_APPEND, S_IRWXU) :
                       open(argv[i + 1], O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
        }
    }

    int characters_read = read(STDIN_FILENO, buf, MAX_SIZE);
    while (characters_read) {
        for (int i = 0; i < file_count; ++i) {
            write(files[i], buf, characters_read);
        }
        characters_read = read(0, buf, MAX_SIZE);
    }


    for (int i = 0; i < argc - is_a - 1; ++i) {
        close(files[i]);
    }

}
