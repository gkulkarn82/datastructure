#include<bits/stdc++.h>
using namespace std;

int main()
{
    int *pi = (int*) malloc(sizeof(int));
    *pi = 5;
    printf("*pi: %d\n", *pi);
    free(pi);

    /*
        One more way
    */

   int *pi1;
   *pi1 = (int *)malloc(sizeof(int));
   //here this is wrong as we are assigning the address returned from malloc to address it is pointing to
   //here the pointer *pi1 is invalid as it is not initialised yet

   /*
    correct apporach is
   */

    pi1 = (int*) malloc(sizeof(int));

    //memory leak
    char *chunk;
    while (1) 
    {
        chunk = (char*) malloc(1000000);
        printf("Allocating\n");
    }

    //losing address
    int *p1 = (int*) malloc(sizeof(int));
    *p1= 5;

    p1 = (int*) malloc(sizeof(int));
    //earlier memory is not released and the pointer is initialised with new one


    char* name = (char*)malloc(strlen("susan") + 1);
    strcpy(name,"susan");

    while(*name != 0)
    {
        printf("%c", name);
        name++;
    }

    /*
        In above program the issues is
        However, it increments name by one with each loop iteration. At the end, name is left
        pointing to the string’s NUL termination character, as illustrated in Figure 2-4. The
        allocated memory’s starting address has been lost.

        Memory leaks can also occur when freeing structures created using the struct keyword.
        If the structure contains pointers to dynamically allocated memory, then these pointers
    
    */

    //we need to cast the outcome from the malloc function for that we need to include  malloc header
    //if we fail to include the malloc header the cimpiler consider default return type as int 
    // and if the malloc is not included then it will raise warning that trying to assgin int to type pointer

    //static variable
    static int *pi = malloc(sizeof(int));
    // this will generate compiler warning to fix it we need to seperate the initialisation and declaration

    static int *pi1;
    pi1 = (int *)malloc(sizeof(int))


    //calloc function
    void *calloc(size_t numElements, size_t elementSize);
    /*
        If either numElements or elementSize is zero, then a null pointer may be returned. If
        calloc is unable to allocate memory, a null pointer is returned and the global variable,
        errno, is set to ENOMEM (out of memory). This is a POSIX error code and may not be
        available on all systems.

    */
    int *pi = calloc(5,sizeof(int));

    /*
        Instead of using calloc, the malloc function along with the memset function can be
        used to achieve the same results, as shown below:
    */
    int *pi = malloc(5 * sizeof(int));
    memset(pi, 0, 5* sizeof(int));

    /*
        Use calloc when memory needs to be zeroed out. However, the execution of calloc
        may take longer than using malloc.
    */


     //realloc function
     /*
        Periodically, it may be necessary to increase or decrease the amount of memory allocated
        to a pointer     
     */

    void *realloc(void *ptr, size_t size)

    char *string1;
    char *string2;
    string1 = (char*) malloc(16);
    strcpy(string1, "0123456789AB");

    string2 =  realloc(string1, 8);
    printf("string1 Value: %p [%s]\n", string1, string1);
    printf("string2 Value: %p [%s]\n", string2, string2);


    string1 = (char*) malloc(16);
    strcpy(string1, "0123456789AB");
    string2 = realloc(string1, 64);
    printf("string1 Value: %p [%s]\n", string1, string1);
    printf("string2 Value: %p [%s]\n", string2, string2);

    //Free function
    int num;
    int *pi = &num;
    free(pi); // Undefined behavior

    //double free runtime exception
    p1 = (int*) malloc(sizeof(int));
    int *p2 = p1;
    free(p1);
    ...
     free(p2);

     /*
        The Heap and System Memory
        The heap typically uses operating system functions to manage its memory. The heap’s
        size may be fixed when the program is created, or it may be allowed to grow. However,
        the heap manager does not necessarily return memory to the operating system when
        the free function is called. The deallocated memory is simply made available for sub‐
        sequent use by the application. Thus, when a program allocates and then frees up mem‐
        ory, the deallocation of memory is not normally reflected in the application’s memory
        usage as seen from the operating system perspective.
     
     */


     //Dangling Pointer
    /*  
        A more insidious example occurs when more than one pointer references the same area
        of memory and one of them is freed. As shown below, p1 and p2 both refer to the same
        area of memory, which is called pointer aliasing. However, p1 is freed:
    */
    int *p1 = (int*) malloc(sizeof(int));
    *p1 = 5;
    ...
    int *p2;
    p2 = p1;
    ...
    free(p1);
    ...
    *p2 = 10; // Dangling pointer

    /*
        A subtle problem can occur when using block statements, as shown below. Here pi is
        assigned the address of tmp. The variable pi may be a global variable or a local variable.
        However, when tmp’s enclosing block is popped off of the program stack, the address is
        no longer valid:
    
    */

    int *pi;
    ...
    {
    int tmp = 5;
    pi = &tmp;
    }
    // pi is now a dangling pointer
    foo();




}