#include "csm-c/string_type.h"


#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<stdbool.h>
#include<unistd.h>
#include<sys/types.h>
#include<limits.h>
#include<stdlib.h>


char* get_cwd_name();

void run(int argc, char* argv[]){
            //current working directory name
            char* cwd_name = get_cwd_name();

            //build the project
            struct string* build_command = new_string("gcc -Wall -Wextra -Iinclude $(find src -name '*.c') $(find lib -type f -path '*/src/*.c') $(find lib -type d -path '*/include' -printf '-I %p ') -o build/");
            append_string(build_command,cwd_name);
            if(system(build_command->value) != 0)
            {
                printf("Error while building the project!\n");
                exit(1);
            }

            //run the project
            struct string* run_command = new_string("./build/");
            append_string(run_command,cwd_name);
            int x = 2;
            while(x < argc){
                append_string(run_command," ");
                append_string(run_command,argv[x]);
                x+=1;
            }
           
            if(system(run_command->value) != 0)
            {
                printf("Error while running the project!\n");
                exit(1);
                
                
            }
            free_string(run_command);
}

char* get_cwd_name()
{
    static char cwd[PATH_MAX];
    if(getcwd(cwd,sizeof(cwd))==NULL)
    {
        return NULL;
    }

    //extract the folder name (after the last '/')
    char *base = strrchr(cwd,'/');
    if(base)
        base++;
    else
        base = cwd;

    return base;    

}