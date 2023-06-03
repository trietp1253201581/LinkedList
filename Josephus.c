/*Bài toán Josephus:
n khách hàng tham gia vào vòng quay trúng thưởng của công ty X được xếp thành vòng tròn.
Giám đốc chọn ngẫu nhiên một số nguyên dương m<=n. 
Chọn ngẫu nhiên một người. Bắt đầu từ người đó giám đốc bắt đầu đếm theo chiều kim đồng hồ
và dừng lại khi đếm tới m. Người ở vị trí này phải dừng cuộc chơi.
Người cuối cùng còn lại là người trúng thưởng.
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//Khai báo danh sách liên kết đơn
struct LinkedList{
    int data;
    struct LinkedList *next;
 };
 
typedef struct LinkedList *node;
/*Khởi tạo 1 node*/
node CreateNode(int value){
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct LinkedList)); // Cấp phát vùng nhớ dùng malloc()
    temp->next = NULL;// Cho next trỏ tới NULL
    temp->data = value; // Gán giá trị cho Node
    return temp;//Trả về node mới đã có giá trị
}
/*Thêm 1 node mang giá trị value vào cuối danh sách*/
node AddTail(node head, int value){
    node temp,p;// Khai báo 2 node tạm temp và p
    temp = CreateNode(value);//Gọi hàm createNode để khởi tạo node temp có next trỏ tới NULL và giá trị là value
    if(head == NULL){
        head = temp;     //Nếu linked list đang trống thì Node temp là head luôn
    }
    else{
        p  = head;// Khởi tạo p trỏ tới head
        while(p->next != NULL){
            p = p->next;//Duyệt danh sách liên kết đến cuối. Node cuối là node có next = NULL
        }
        p->next = temp;//Gán next của thằng cuối = temp. Khi đó temp sẽ là thằng cuối(temp->next = NULL mà)
    }
    return head;
}
node DelHead(node head){
    if(head == NULL){
        printf("\nCha co gi de xoa het!");
    }else{
        head = head->next;
    }
    return head;
}
/*Xoá node được trỏ bởi lnode*/
node DeleteNode(node head, node lnode)
{
    node temp;
    temp=head;
    if (head==lnode)
    {
        head=head->next;
        return head;
    }
    else
    {
        while(temp->next!=lnode)
        temp=temp->next;
    }
    if(temp->next=NULL)
    printf("Khong tim thay lnode");
    else temp->next=lnode->next;
    return head;
}
/*Thuật toán giải bài toán Josephus*/
void Josephus(int n,int m)
{
    int i,j;
    node dlist,current,p;
    /*Nhập danh sách*/
    for(i=1;i<=n;i++)
    dlist=AddTail(dlist,i);
    /*Bắt đầu đếm*/
    current=dlist;
    for(i=1;i<n;i++)
    {   
        /*Thực hiện đếm*/
        for(j=1;j<m;j++)
        {
            current=current->next;
            /*Nếu current trước đó là người cuối thì cho về đầu*/
            if(current==NULL)
            current=dlist;
        }
        printf("Xoa khach hang %d \n",current->data);
        p=current;
        dlist=DeleteNode(dlist,p);
        current=current->next;
        /*Nếu current trước đó là người cuối thì cho về đầu*/
        if(current==NULL)
        current=dlist;
    }
    printf("Khach hang %d la nguoi thang cuoc",current->data);
}
void Traverser(node head){
    printf("\n");
    node p=head;
    while(p!=NULL)
    {
        printf("%5d", p->data);
        p=p->next;
    }
}
int main()
{
    int n,m;//n-số người chơi, m-số được giám đốc 
    printf("Nhap so nguoi choi: ");
    scanf("%d",&n);
    //Tạo ngẫu nhiên m
    printf("Nhap so dem: ");
    scanf("%d",&m);
    /*Nhập danh sách*/
    Josephus(n,m);
    getch();
}


