//Reference : https://www.codeproject.com/Articles/108830/Inheritance-and-Polymorphism-in-C#:~:text=In%20C%2C%20inheritance%20can%20be,base%20data%20members%20and%20functions.
#include<stdio.h>

typedef struct  _Person Person;

typedef void (*fptrDisplayInfo)(Person*);
typedef void (*fptrWriteToFile)(Person* , const char*);
typedef void (*fptrDelete) (Person*);

typedef struct _Person
{
    char* pFName;
    char* pLName;
    fptrDisplayInfo  Display;
    fptrWriteToFile  WriteToFile;
    fptrDelete  Delete;
}Person;

Person* new_person(const char* const pFirstName, const char* const pLastName);
void Person_Delete(Person* const pPersonObj);
void Person_DisplaInfo(Person* const pPersonObj);
void Person_WriteToFile(Person* const pPersonObj, const char* pFileName);


Person* new_Person(const char* const pFirstName, const char* const pLastName)
{
    Person* pObj = NULL;
    //allocating memory
    pObj = (Person*)malloc(sizeof(Person));
    if (pObj == NULL)
    {
        return NULL;
    }
    //pointing to itself as we are creating base class object
    pObj->pDerivedObj = pObj;
    pObj->pFirstName = malloc(sizeof(char)*(strlen(pFirstName)+1));
    if (pObj->pFirstName == NULL)
    {
        return NULL;
    }
    strcpy(pObj->pFirstName, pFirstName);

    pObj->pLastName = malloc(sizeof(char)*(strlen(pLastName)+1));
    if (pObj->pLastName == NULL)
    {
        return NULL;
    }
    strcpy(pObj->pLastName, pLastName);

    //Initializing interface for access to functions
    //destructor pointing to destrutor of itself
    pObj->Delete = Person_Delete;
    pObj->Display = Person_DisplayInfo;
    pObj->WriteToFile = Person_WriteToFile;

    return pObj;
}


int main()
{
    Person* ptr = new_Person("Gajanan", "Kulkarni");
    ptr->Display(ptr);
    ptr->WriteToFile(ptr, "C:\\Test.txt");
}