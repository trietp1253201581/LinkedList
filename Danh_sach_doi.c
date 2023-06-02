#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct dllist
{
    int number;
    struct dllist *next;
    struct dllist *prev;
};
struct dllist *head,*tail;
/*Khởi tạo một node mới*/
struct dllist *GetNewNode(int value)
{
    struct dllist *NewNode
        = (struct dllist*)malloc(sizeof(struct dllist));
    NewNode->number = value;
    NewNode->prev = NULL;
    NewNode->next = NULL;
    return NewNode;
}
/*Thêm một node vào đầu*/
struct dllist *InsertAtHead(struct dllist *Head, struct dllist *Tail, int value)
{
    struct dllist *NewNode=GetNewNode(value);
    struct dllist *HEAD,*TAIL;
    if(Head==NULL)
    {
        Head=NewNode;
        Tail=NewNode;
    }
    else
    {
        Head->prev=NewNode;
        NewNode->next=Head;
        Head=NewNode;
    }
    return Head;
}
/*Thêm một node vào cuối*/
struct dllist *InsertAtTail(struct dllist *Head, struct dllist *Tail, int value)
{
    struct dllist *NewNode=GetNewNode(value);
    if(Head==NULL)
    {
        Head=NewNode;
        Tail=NewNode;
    }
    else
    {
        Tail->next=NewNode;
        NewNode->prev=Tail;
        Tail=NewNode;
    }
    return Tail;
}
/*Xoá 1 node ở đầu*/
void DeleteAtHead(struct dllist *Head, struct dllist *Tail)
{
    if(Head=NULL)
    return;
    Head=Head->next;
    Head->prev=NULL;
}
/*Xoá 1 node ở cuối*/
void DeleteAtTail(struct dllist *Head, struct dllist *Tail)
{
    if(Head==NULL)
    return;
    Tail=Tail->prev;
    Tail->next=NULL;
}
/*In danh sách liên kết từ đầu tới cuối*/
void Print(struct dllist *Head)
{
    struct dllist *node;
    node=Head;
    while(node!=NULL)
    {
        printf("%d\n",node->number);
        node=node->next;
    }
}
/*In danh sách liên kết từ cuối lên đầu*/
void ReservePrint(struct dllist *Tail)
{
    struct dllist *node; int i;
    node=Tail;
    while(node!=NULL)
    {
        printf("%d\n",node->number);
        node=node->prev;
    }
}
int main()
{
    struct dllist *so; int i;
    /*Bổ sung các giá trị từ 1 tới 5 vào node*/\
    head=NULL; tail=NULL;
    head=InsertAtHead(head,tail,1);
    tail=head;
    for(i=2;i<=5;i++)
    tail=InsertAtTail(head,tail,i);
    /*In ra danh sách so*/
    printf("\nDanh sach: ");
    Print(head);
    printf("\nDanh sach nguoc");
    ReservePrint(tail);
    getch();
}
