//implements a linked list data structure that can be used to store data in array-like manner 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define linked list structure
struct LinkedList{
    int data;
    int index; 
    struct LinkedList * next; 
};

//initialize the linked list
struct LinkedList* init_array(){
    struct LinkedList * head = NULL;
    return head;
}

//function to add an element to linked list
struct LinkedList get_array(int item, int index, struct LinkedList** array)
{
    struct LinkedList * temp = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    temp->data = item;
    temp->index = index;
    temp->next = NULL;

    if ((*array) == NULL){
        (*array) = temp;
        return **array;
    }
    else{
        struct LinkedList * temp2; 
        temp2 = (*array);
        while(temp2 != NULL){
            if (temp2->next == NULL){
                temp2->next = temp;
                return *temp2;
            }
            temp2 = temp2->next;
        }
    }
    return **array;
}

//prints elements of linked list
void print_array(struct LinkedList ** array)
{
    struct LinkedList * temp = *array;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        printf("->");
        temp = temp->next;
    }

}





