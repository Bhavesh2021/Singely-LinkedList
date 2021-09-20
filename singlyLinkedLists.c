#include<stdio.h>
#include<malloc.h>
#include<conio.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE *start = NULL; //to indentify yeh start node hai

int insert_beg(int x) //insert at start x=5
{
    NODE *ptr;
    ptr = (NODE *)malloc(sizeof(NODE));
    if(ptr==NULL) //not found memory to store node so ptr will be null
    {
        printf("Memory Full");
        return 0;
    }
    ptr->data=x;
    ptr->next=NULL;

    if(start==NULL) //to check if ptr is first node
    {
        start=ptr;
        printf("%d is inserted",x);
        return 1;
    }
    ptr->next=start;
    start=ptr;
    printf("%d is inserted",x);
    return 1;
}

int insert_end(int x)
{
    NODE *ptr,*temp;
    ptr = (NODE *)malloc(sizeof(NODE));
    if(ptr==NULL) //not found memory to store node so ptr will be null
    {
        printf("Memory Full");
        return 0;
    }
    ptr->data=x;
    ptr->next=NULL;

    if(start==NULL) //to check if ptr is first node
    {
        start=ptr;
        printf("%d is inserted",x);
        return 1;
    }
    temp=start; //temp start se start kar
    while(temp->next!=NULL)  //tabhie tak age ja jabhie tak temp ka next null nhi hai
    {
        temp=temp->next;
    }
    temp->next=ptr;
    printf("%d is inserted",x);
    return 1;
}

int insert_after(int key,int x)//key=5 and x=6
{
    NODE *ptr,*temp;
    ptr = (NODE *)malloc(sizeof(NODE));
    if(ptr==NULL) //not found memory to store node so ptr will be null
    {
        printf("Memory Full");
        return 0;
    }
    ptr->data=x;
    ptr->next=NULL;
    temp=start;  //temp start se start kar
    while(temp->next!=NULL && temp->data!=key)
    {
        temp=temp->next;
    }
    if(temp->next==NULL && temp->data!=key)
    {
        printf("%d not found",key);
        return 0;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    printf("%d is inserted",x);
    return 1;
}
int insert_before(int key,int x)
{
    NODE *ptr,*temp, *prev;
    ptr = (NODE *)malloc(sizeof(NODE));
    if(ptr==NULL) //not found memory to store node so ptr will be null
    {
        printf("Memory Full");
        return 0;
    }
    ptr->data=x;
    ptr->next=NULL;
    temp=start;
    prev=NULL;
    while(temp->next!=NULL && temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp->next==NULL && temp->data!=key)
    {
        printf("%d not found",key);
        return 0;
    }
    ptr->next=prev->next;
    prev->next=ptr;
    printf("%d is inserted",x);
    return 1;
}
void empty()
{
    if(start==NULL)
        printf("LinkedList is empty");
    else
        printf("LinkedList is not empty");
}
void full()
{
    NODE *ptr;
    ptr = (NODE *)malloc(sizeof(NODE));

    if(ptr==NULL)
        printf("Memory full");
    else
    {
        free(ptr);
        printf("Memory not full");
    }
}
void traverse()
{
    NODE *temp = start;
    while(temp->next!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
	printf("%d",temp->data);
}
void tellCount()
{
    NODE *temp = start;
    int count = 0;
    while(temp->next!=NULL)
    {
        count++;
        temp=temp->next;
    }
	count++;
    printf("%d",count);
}
int delete_beg()
{
    NODE *ptr;
    ptr=start;
    if(ptr==NULL)
    {
        printf("No element");
        return 0;
    }
    start=start->next;
    ptr->next=NULL;
    printf("%d is deleted",ptr->data);
    free(ptr);
    return 1;
}
int delete_end()
{
    NODE *ptr,*prev;
    ptr=start;
    prev=NULL;
    if(ptr==NULL)
    {
        printf("No element");
        return 0;
    }
    while(ptr->next!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=NULL;
    printf("%d is deleted",ptr->data);
    free(ptr);
    return 1;
}
int delete_after(int key)
{
    NODE *ptr,*prev;
    ptr=start;
    prev=NULL;
    if(ptr==NULL)
    {
        printf("No element");
        return 0;
    }
    while(prev!=NULL && prev->data!=key)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=ptr->next;
    printf("%d is deleted",ptr->data);
    free(ptr);
    return 1;
}
int delete_before(int key)
{
    NODE *ptr,*prev;
    ptr=start;
    prev=NULL;
    if(ptr==NULL)
    {
        printf("No element");
        return 0;
    }
    while(ptr->next->data!=key && ptr->next!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    if(ptr->next==NULL)
    {
        printf("No element");
        return 0;
    }
    prev->next=ptr->next;
    printf("%d is deleted",ptr->data);
    free(ptr);
    return 1;
}
int delete_node(int key)
{
    NODE *ptr,*prev;
    ptr=start;
    prev=NULL;
    if(ptr==NULL)
    {
        printf("No element");
        return 0;
    }
    while(ptr->data!=key)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=ptr->next;
    ptr->next=NULL;
    printf("%d is deleted",ptr->data);
    free(ptr);
    return 1;
}
int main()
{
    int option,a,b,pos;
    do
    {
        printf("\n Choose an option\n");
        printf("\n1.Insert Beginning\n");
        printf("\n2.Insert End\n");
        printf("\n3.Insert After\n");
        printf("\n4.Insert Before\n");
        printf("\n5. Check Empty\n");
        printf("\n6. Check Full\n");
        printf("\n7. Traverse\n");
        printf("\n8. Count\n");
        printf("\n9. Delete Beginning\n");
        printf("\n10. Delete End\n");
        printf("\n11. Delete After\n");
        printf("\n12. Delete Before\n");
        printf("\n13. Delete Particular node\n");
        printf("\n14. Exit\n");

        printf("\n Enter your option \n");
        scanf("%d",&option);
        switch(option)
        {
            case 1: printf("Enter the node to be inserted\n");
            scanf("%d",&a);
            b = insert_beg(a);
            if(b==0)
            {
                printf("Element not inserted\n");
            }
            break;
            case 2: printf("Enter the node to be inserted\n");
            scanf("%d",&a);
            b = insert_end(a);
            if(b==0)
            {
                printf("Element not inserted\n");
            }
            break;
            case 3: printf("Enter the node to be inserted\n");
            scanf("%d",&a);
            printf("Enter the position\n");
			scanf("%d",&pos);
            b = insert_after(pos,a);
            if(b==0)
            {
                printf("Element not inserted\n");
            }
            break;
            case 4: printf("Enter the node to be inserted\n");
            scanf("%d",&a);
            printf("Enter the position\n");
			scanf("%d",&pos);
            b = insert_before(pos,a);
            if(b==0)
            {
                printf("Element not inserted\n");
            }
            break;
            case 5: empty();
            break;
            case 6: full();
            break;
            case 7: traverse();
            break;
            case 8: tellCount();
            break;
            case 9: b=delete_beg();
            if(b==0)
                printf("Element not deleted\n");
            break;
            case 10: b=delete_end();
            if(b==0)
                printf("Element not deleted\n");
            break;
            case 11: printf("Enter the position\n");
			scanf("%d",&pos);
            b = delete_after(pos);
            if(b==0)
            {
                printf("Element not deleted\n");
            }
            break;
            case 12: printf("Enter the position\n");
			scanf("%d",&pos);
            b = delete_before(pos);
            if(b==0)
            {
                printf("Element not deleted\n");
            }
            break;
            case 13: printf("Enter the node to be deleted\n");
            scanf("%d",&a);
            b = delete_node(a);
            if(b==0)
            {
                printf("Element not deleted\n");
            }
            break;
            case 14: printf("End");
            break;
        }
    }
    while(option!=14);
    return 0;
}
