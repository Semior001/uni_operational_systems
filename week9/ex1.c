#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define FILENAME_SIZE 40

typedef struct page_frame {
    int page;
    unsigned int referenced;
} page_frame;

const unsigned int first_bit_set = 1u << (8 * sizeof(unsigned int) - 1);

// http://www.martinbroadhurst.com/trim-a-string-in-c.html
void *rtrim(char *str, const char *seps)
{
    int i;
    if (seps == NULL) {
        seps = "\t\n\v\f\r ";
    }
    i = strlen(str) - 1;
    while (i >= 0 && strchr(seps, str[i]) != NULL) {
        str[i] = '\0';
        i--;
    }
}

int main() {
    char filename[FILENAME_SIZE] = "";
    int page_frame_count;
    FILE *data;

    if (strcmp(filename, "") == 0) {
        puts("Enter the input file's filename: ");
        fgets(filename, FILENAME_SIZE, stdin);
    }

    rtrim(filename, NULL);
//    puts(filename);

    data = fopen(filename, "r");
    if (!data){
        puts("Error opening the file");
        return -1;
    }

    puts("Enter the number of page frames");
    scanf("%d", &page_frame_count);

    page_frame *pageFrame = calloc(page_frame_count, sizeof(page_frame));
    for (int j = 0; j < page_frame_count; ++j) {
        pageFrame[j].page = -1; // indicating free page
    }

    int hits = 0, all = 0, newly_allocated = 0;
    int asked_page = 0;
    char c = getc(data);

    while (c != EOF) {
        if (c != ' ') { //read a number char by char
            asked_page *= 10;
            asked_page += (int) (c - '0');
        } else { // a number read
            int replace_index = 0, hit = 0, new=0;
            unsigned int max_age = 0;

            for (int i = 0; i < page_frame_count; ++i) {
                if (pageFrame[i].page == -1) {
                    // free page frame found
                    max_age = UINT_MAX;
                    replace_index = i;
                    new = 1;
                } else {
                    pageFrame[i].referenced >>= 1U;

                    if (pageFrame[i].page == asked_page) {
                        //required page found
                        hit = 1;
                        // set the first bit
                        pageFrame[i].referenced |= first_bit_set;
                    } else {
                        // find a candidate to replace with
                        if (pageFrame[i].referenced > max_age) {
                            max_age = pageFrame[i].referenced;
                            replace_index = i;
                        }
                    }
                }
            }

            if (!hit) {
                newly_allocated += new;
                pageFrame[replace_index].page = asked_page;
                pageFrame[replace_index].referenced = first_bit_set;
            }

            hits += hit;
            ++all;
            asked_page = 0;
        }
        c = getc(data);
    }

    fclose(data);
    printf("Hits %d, all %d, newly_allocated %d\n", hits, all, newly_allocated);
    printf("Hit/Miss ratio = %f, hit ratio = %f, miss ratio = %f\n",
           ((double)hits/ (double)(all - hits)),
           ((double)hits/ (double)(all)),
           (1 - (double)hits/ (double)(all)));

    return 0;
}