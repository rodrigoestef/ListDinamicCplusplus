#include <stdio.h>
#include <List.h>
int main()
{
    List *list = new List();
    list->set((void *)"obj1"); //0
    list->set((void *)"obj2"); //1
    list->set((void *)"obj3"); //2
    list->set((void *)"obj4"); //3
    list->set((void *)"obj5"); //4
    list->set((void *)"obj6"); //5
    list->set((void *)"obj7"); //6

    int i;
    for (i = 0; i < list->getSize(); i++)
    {
        printf("objs: %s\n", (char *)list->getByIndex(i));
    }
    printf("remove teste\n\n\n");
    list->removeByIndex(3);
    list->removeByIndex(0);
    list->removeByIndex(list->getSize() - 1);
    for (i = 0; i < list->getSize(); i++)
    {
        printf("objs: %s\n", (char *)list->getByIndex(i));
    }
}