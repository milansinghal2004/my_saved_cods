
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//Author: Rajdeep Singh Sidhu
//Date: 16-10-2023
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
void insert_at_beg(struct node *new);
void insert_at_end(struct node *new);
void del_beg();
void del_end();
void print();
int main()
{
    int choise;
    struct node *ptr;
    int x = 1;
    while (x == 1)
    {
        printf("press 1 for insertion in the beg;\t press 2 for insertion at the end;\n press 3 for delition from the end;\tpress 4 to delition at the beg;\npress 5 to print all the entries \n Enter: ");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            ptr = (struct node *)malloc(sizeof(struct node));
            printf("Enter the value: ");
            scanf("%d", &ptr->data);
            ptr->next = head;
            insert_at_beg(ptr);
            break;
        case 2:
            ptr = (struct node *)malloc(sizeof(struct node));
            printf("Enter the value: ");
            scanf("%d", &ptr->data);
            ptr->next = head;
            insert_at_end(ptr);
        case 3:
            del_end();
            break;
        case 4:
            del_beg();
            break;
        case 5:
            print();
            break;
        case 6:
            printf("This is the end of Linked list\n");
            x = 0;
            break;
        default:
            printf("Invalid input");
        }
    }
}
void insert_at_beg(struct node *new)
{
    if (head == NULL)
    {
        head = new;
        head->next = head;
    }
    else
    {
        struct node *temp = head;
        head->next = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new;
        head = new;
    }
}
void insert_at_end(struct node *new)
{
    if (head == NULL)
    {
        head = new;
        head->next = head;
    }

    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = head;
    }
}
void del_beg()
{
    struct node *temp = head;
    struct node *temp1 = head;
    if (head = NULL)
    {
        printf("Under Flow\n");
    }
    else if (head->next == head)
    {
        head = NULL;
    }

    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }

        head = head->next;
        temp->next = head;
        free(temp1);
        temp1 = NULL;
    }
}
void del_end()
{
    struct node *temp, *temp1;
    temp = temp1 = head;
    if (head == NULL)
    {
        printf("Under Flow\n");
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        while (temp1->next != temp)
        {
            temp1 = temp1->next;
        }
        temp1->next = head;
        free(temp);
        temp = NULL;
    }
}
void print()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("Under Flow");
    }
    else
    {
        while (temp->next != head)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}
// Double linked list

// struct node
// {
//     struct node *prev;
//     int data;
//     struct node *next;
// };
// struct node *head = NULL;
// void insert_at_beg();
// int main()
// {
//     int choise;
//     struct node *ptr;
//     while (1)
//     {
//         printf("press 1 for insertion in the beg;\t press 2 for insertion at the end;\n press 3 for delition from the end;\tpress 4 to delition; \n Enter: ");
//         scanf("%d", &choise);
//         switch (choise)
//         {
//         case 1:
//             ptr = (struct node *)malloc(sizeof(struct node));
//             printf("Enter the value: ");
//             scanf("%d", &ptr->data);
//             ptr->next = NULL;
//             ptr->prev = NULL;
//             insert_at_beg(ptr);
//             break;
//         case 2:

//         case 3:
//             del_end();
//         }
//     }
// }
// void insert_at_beg(struct node *new)
// {
//     if (head == NULL)
//     {
//         head = new;
//     }
//     else
//     {
//         new->next = head;
//         head->prev = new;
//         head = new;
//     }
// }
