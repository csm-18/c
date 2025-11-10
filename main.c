#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<stdbool.h>
#include<unistd.h>


bool folder_exists(char* folder_name);


const char* C_VERSION = "0.0.1";
int main(int argc,char* argv[]){
    if(argc == 1){
        printf("c %s\n",C_VERSION);
        printf("A build tool for c (like cargo for rust).\n\n");
        printf("For more info:\n");
        printf(" c help\n");
    }else if (argc == 2)
    {
        if (strcmp(argv[1], "version") == 0 || strcmp(argv[1], "-v") == 0)
        {
            printf("c %s\n",C_VERSION);
        }else if (strcmp(argv[1], "init") == 0)
        {
            printf("Initializing project...\n\n");

            if(folder_exists("./include")){
                printf("Error: 'include/' folder already exists!\n");
                return 1;
            }else if(folder_exists("./src")){
                printf("Error: 'src/' folder already exists!\n");
                return 1;
            }else if(folder_exists("./build")){
                printf("Error: 'build/' folder already exists!\n");
                return 1;
            }else if (access(".gitignore",F_OK) == 0)
            {
                printf("Error: '.gitignore' file already exists!\n");
                return 1;
            }
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