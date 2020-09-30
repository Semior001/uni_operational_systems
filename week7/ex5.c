#include <stdio.h>

int main() {
    char **s = malloc(sizeof(char*)); // before filling the string, we have to allocate the memory for its characters
    char foo[] = "Hello World";
    *s = foo;
    printf("s is %s\n",*s); // since s is a pointer to string (string is a pointer to first character in it) we have to dereference it 
    s[0] = foo;
    printf("s[0] is %s\n",s[0]);
    return(0);
}