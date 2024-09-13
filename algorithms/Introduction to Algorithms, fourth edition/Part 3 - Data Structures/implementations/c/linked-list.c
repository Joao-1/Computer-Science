// ! Linked list

#include <stdio.h>

struct LinkedList
{   
    struct Node *head;
    int *array;
};

struct Node 
{
    int value;
    struct Node *next;
    struct Node *prev;
};

int main() {
    struct LinkedList list;
    list.head = NULL;

    struct Node node1;
    node1.value = 1;
    Prepend(&list, &node1);

}

struct Node *Search(struct LinkedList *list, struct Int *number) {
    struct Node *x = list->head;
    while (x != NULL && x->value != number) {
        x = x->next;
    }

    return x;
}

int Prepend(struct LinkedList *list, struct Node *node) {
    node->next = list->head;
    node->prev = NULL;
    if (list->head != NULL) {
        list->head->prev = node;
    }
    list->head = node;
}

int Insert(struct Node *nodeX, struct Node *nodeY) {
    nodeX->next = nodeY->next;
    nodeX->prev = nodeY;
    if (nodeY->next != NULL) {
        nodeY->next->prev = nodeX;
    }
    nodeY->next = nodeX;
}

int Delete(struct LinkedList *list, struct Node *node) {
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
}

