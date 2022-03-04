#include <stdio.h>
#include <malloc.h>

typedef struct 
{
    float bilFloat;
}container;

typedef struct 
{
    container bil;
    int next;
}element;

typedef struct 
{
    element data[50];
    int first;
}list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(float bil, list *L);
void addAfter(int prev, float bil, list *L);
void addLast(float bil, list *L);
void delFirst(list *L);
void delAfter(int prev, list *L);
void delLast(list *L);
void delAll(list *L);
void printElement(list L);

int n;