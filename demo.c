#include <stdio.h> 

void a(void)
{
    printf("in a()\n"); 
}

void (*ptr[1])(void) = {a}; 

int main(void) 
{
    ptr[0](); 

    return (0); 
}