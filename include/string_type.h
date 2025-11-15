#ifndef STRING_TYPE_H
#define STRING_TYPE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct string
{
    char* value;
    int size;
    int len;
};

struct string* new_string(char* text);
void append_string(struct string* ptr_to_string,char* text);
void free_string(struct string* ptr_to_string);











#endif