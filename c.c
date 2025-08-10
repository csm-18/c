#include <stdio.h>
#include <string.h>


//version
const char* VERSION = "c 0.1.0";

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        puts(VERSION);
    }else if (argc == 2)
    {
        char* filename = argv[1];
        size_t len = strlen(filename);

        if (!(len > 2 && filename[len-2] == '.' && filename[len-1] == 'c'))
        {
            puts("Error: File must have .c extension");
            return 1;
        }
    }   
}