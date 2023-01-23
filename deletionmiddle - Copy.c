#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};
int count_nodes(struct Node *head)
{
    int n_count = 0;
    while (head != NULL)
    {
        head = head->next;
        n_count++;
    }
    return n_count;
}
struct Node *delete_middle(struct Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    struct Node *Head_copy = head;
    int count = count_nodes(head);
    int mid = count / 2;
    while (mid-- > 1)
    {
        head = head->next;
    }
    head->next = head->next->next;
    return Head_copy;
}
void display_List(struct Node *x)
{
    while (x != NULL)
    {
        printf("%d ->", x->val);
        x = x->next;
    }
    printf("NULL\n");
}
struct Node *newNode(int value)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->val = value;
    t->next = NULL;
    return t;
}
int main()
{
    struct Node *head = newNode(5);
    head->next = newNode(10);
    head->next->next = newNode(15);
    head->next->next->next = newNode(20);
    head->next->next->next->next = newNode(25);
    printf("Original List\n");
    display_List(head);
    head = delete_middle(head);
    printf("List after deleting the middle element\n");
    display_List(head);
    return 0;
}