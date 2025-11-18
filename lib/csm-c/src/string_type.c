#include"csm-c/string_type.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// struct string
// {
//     char* value;
//     int size;
//     int len;
// };


 struct string* new_string(char* text){
    struct string* ptr_to_string = malloc(sizeof(struct string));
    ptr_to_string->value = (char*)calloc(strlen(text)+1,sizeof(char));
    
    
    size_t text_len = strlen(text)+1;
    for (size_t i = 0; i < text_len; i++)
    {
        ptr_to_string->value[i]=text[i];
    }
    ptr_to_string->size = (strlen(text)+1)*sizeof(char);
    ptr_to_string->len = strlen(text)+1;

    return ptr_to_string;
}

void append_string(struct string* ptr_to_string,char* text){
    int new_size = (ptr_to_string->size+strlen(text))*sizeof(char);
    int new_len = ptr_to_string->len+strlen(text);
    ptr_to_string->value = (char*)realloc(ptr_to_string->value,new_size);
    

    int x = 0;
    int y = ptr_to_string->len-1;
    int text_len = strlen(text)+1; 
    while(x < text_len){
        ptr_to_string->value[y] = text[x]; 
        x +=1;
        y+=1;
    }

    ptr_to_string->size = new_size;
    ptr_to_string->len = new_len;
}

void free_string(struct string* ptr_to_string){
    free(ptr_to_string->value);
    ptr_to_string->size = 0;
    ptr_to_string->len = 0;

    free(ptr_to_string);
}

// int main(){
//     struct string* name = new_string("rahul");

//     printf("name: %s\nlen: %d\nsize:%d\n",name->value,name->len,name->size);

//     append_string(name,"!!!!");
//     printf("name: %s\nlen: %d\nsize:%d\n",name->value,name->len,name->size);
    
    
//     free(name);

// }