#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int size;
struct node *head, *tail = NULL;

void addNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void addInMid(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        struct node *temp, *current;
        int count = (size % 2 == 0) ? (size / 2) : ((size + 1) / 2);
        temp = head;
        current = NULL;

        for (int i = 0; i < count; i++)
        {
            current = temp;
            temp = temp->next;
        }

        current->next = newNode;
        newNode->next = temp;
    }
    size++;
}

void display()
{
    struct node *current = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    addNode(1);
    addNode(2);

    printf("Original list: \n");
    display();

    addInMid(3);
    printf("Updated List: \n");
    display();

    addInMid(4);
    printf("Updated List: \n");
    display();

    return 0;
}