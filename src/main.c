#include "csm-c/string_type.h"
#include "run-command.h"


#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<stdbool.h>
#include<unistd.h>
#include<sys/types.h>
#include<limits.h>
#include<stdlib.h>



const char* hello_world_c_program = "#include<stdio.h>\n\n"
                                    "int main(){\n"
                                    "   printf(\"hello world!\\n\");\n"
                                    "   return 0;\n"
                                    "}\n";


bool folder_exists(char* folder_name);
bool create_file_with_text(char* filename, const char* text);


const char* C_VERSION = "0.0.3";
int main(int argc,char* argv[])
{
    if(argc == 1)
    {
        printf("c %s\n",C_VERSION);
        printf("A build tool for c (like cargo for rust).\n\n");
        printf("For more info:\n");
        printf(" c help\n");
    }else if (argc >= 2)
    {
        if ((argc == 2 && strcmp(argv[1], "version") == 0) || strcmp(argv[1], "-v") == 0)
        {
            printf("c %s\n",C_VERSION);
        }else if (argc == 2 && strcmp(argv[1], "init") == 0)
        {
            printf("Initializing project...\n\n");

            //check if files and folders already exist!
            if(folder_exists("./include"))
            {
                printf("Error: 'include/' folder already exists!\n");
                return 1;
            }else if(folder_exists("./src"))
            {
                printf("Error: 'src/' folder already exists!\n");
                return 1;
            }else if(folder_exists("./build"))
            {
                printf("Error: 'build/' folder already exists!\n");
                return 1;
            }else if (access(".gitignore",F_OK) == 0)
            {
                printf("Error: '.gitignore' file already exists!\n");
                return 1;
            }


            //create project structure
            if(mkdir("include",0755) == 0)
            {
                printf("created  include/\n");
            }else
            {
                printf("Error while creating 'include/' folder!\n");
                return 1;
            }

            if(mkdir("lib",0755) == 0)
            {
                printf("created  lib/\n");
                if(system("git clone https://github.com/csm-c/csm-c ./lib/csm-c > /dev/null 2>&1") != 0 && system("find lib -type d -name .git -exec rm -rf {} +") != 0)
                {
                    printf("Error while setting up csm-c library!\n");
                    exit(1);
                }
                printf("added    csm-c library to lib/\n");
            }else
            {
                printf("Error while creating 'lib/' folder!\n");
                return 1;
            }

            if(mkdir("src",0755) == 0)
            {
                if(create_file_with_text("src/main.c",hello_world_c_program))
                {
                    printf("created  src/main.c\n");
                }else
                {
                    printf("Error while creating 'src/main.c'!\n");
                    return 1;
                }
            }else
            {
                printf("Error while creating 'src/' folder!\n");
                return 1;
            }
            

            if(mkdir("build",0755) == 0)
            {
                printf("created  build/\n");
            }else
            {
                printf("Error while creating 'build/' folder!\n");
                return 1;
            }

            if(create_file_with_text(".gitignore","build/\n\nlib/**/.git/\n"))
            {
                printf("created  .gitignore\n");
            }else
            {
                printf("Error while creating '.gitignore'!\n");
                return 1;
            }
            
        }else if(strcmp(argv[1],"run") == 0)
        {
            run(argc,argv);

        }
    }
    
    return 0;
}

bool folder_exists(char* folder_name){
    struct stat st;

    if(stat(folder_name,&st) == 0 && S_ISDIR(st.st_mode)){
        return true;
    }else{
        return false;
    }
}

bool create_file_with_text(char* filename, const char* text){
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        return false;
    }

    fputs(text,file);
    fclose(file);

    return true;
}

