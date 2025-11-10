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
const char* get_cwd_name();

const char* C_VERSION = "0.0.1";
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
        if (argc == 2 && strcmp(argv[1], "version") == 0 || strcmp(argv[1], "-v") == 0)
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

            if(create_file_with_text(".gitignore","build/\n"))
            {
                printf("created  .gitignore\n");
            }else
            {
                printf("Error while creating '.gitignore'!\n");
                return 1;
            }
            
        }else if(strcmp(argv[1],"run") == 0)
        {
            //current working directory name
            const char* cwd_name = get_cwd_name();
            printf("running in %s\n",cwd_name);

            //build the project and run
            char build_command[200];
            sprintf(build_command,"gcc -Wall -Wextra -Iinclude $(find src -name '*.c') -o build/%s",cwd_name);
            system(build_command);

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

const char* get_cwd_name()
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