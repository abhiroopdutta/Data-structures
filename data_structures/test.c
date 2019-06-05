#include<stdio.h>
#include<stdlib.h>


 
//if we use malloc with char*, its not a pointer to a constant
//char* initialized with a string literal is pointer to a const
int main()
{
    
    // char **strings = malloc(2*sizeof(char *));
    //  strings[0] = "hello";
   const char **s;
   s[0] = "string";
   
    printf("%s",s[0]);
 
    return 0;
}