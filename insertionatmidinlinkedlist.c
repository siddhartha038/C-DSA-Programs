#include <stdio.h>

// Represent a node of the singly linked list
struct node
{
    int data;
    struct node *next;
};

int size;
// Represent the head and tail of the singly linked list
struct node *head, *tail = NULL;

// addNode() will add a new node to the list
void addNode(int data)
{
    // Create a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    // Checks if the list is empty
    if (head == NULL)
    {
        // If list is empty, both head and tail will point to new node
        head = newNode;
        tail = newNode;
    }
    else
    {
        // newNode will be added after tail such that tail's next will point to newNode
        tail->next = newNode;
        // newNode will become new tail of the list
        tail = newNode;
    }
    // Size will count the number of nodes present in the list
    size++;
}

// This function will add the new node at the middle of the list.
void addInMid(int data)
{
    // Create a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    // Checks if the list is empty
    if (head == NULL)
    {
        // If list is empty, both head and tail would point to new node
        head = newNode;
        tail = newNode;
    }
    else
    {
        struct node *temp, *current;
        // Store the mid position of the list
        int count = (size % 2 == 0) ? (size / 2) : ((size + 1) / 2);
        // Node temp will point to head
        temp = head;
        current = NULL;

        // Traverse through the list till the middle of the list is reached
        for (int i = 0; i < count; i++)
        {
            // Node current will point to temp
            current = temp;
            // Node temp will point to node next to it.
            temp = temp->next;
        }

        // current will point to new node
        current->next = newNode;
        // new node will point to temp
        newNode->next = temp;
    }
    size++;
}

// display() will display all the nodes present in the list
void display()
{
    // Node current will point to head
    struct node *current = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (current != NULL)
    {
        // Prints each node by incrementing pointer
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    // Adds data to the list
    addNode(1);
    addNode(2);

    printf("Original list: \n");
    display();

    // Inserting node '3' in the middle
    addInMid(3);
    printf("Updated List: \n");
    display();

    // Inserting node '4' in the middle
    addInMid(4);
    printf("Updated List: \n");
    display();

    return 0;
}