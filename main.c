#include<stdio.h>


const char* C_VERSION = "0.0.1";
int main(int argc,char* argv[]){
    if(argc == 1){
        printf("c %s\n",C_VERSION);
        printf("A build tool for c (like cargo for rust).\n\n");
        printf("For more info:\n");
        printf(" c help\n");
    }else if (argc == 2)
    {
        if (argv[1] == "version" || argv[1] == "-v")
        {
            printf("c %s\n",C_VERSION);
        }else if (argv[1] == "init")
        {
            printf("init...\n");
        }
    }
    
    return 0;
}