#include <stdio.h>
#include <stdlib.h>
struct link
{
    int data;
    struct link* next;
};

struct link* CREATandADDnode(struct link* head)//尾插法
{
    struct link* p=NULL,*pr=head;
    int data;
    p=(struct link*)malloc(sizeof(struct link));
    if(NULL==p)
    {
        printf("分配空间失败，退出程序\n");
        exit(-1);
    }
    if(NULL==head)
    {
        head=p;//把新节点当作头节点
    }
    else
    {
        while(NULL!=pr->next)//当退出程序时，pr到尾节点
        {
            pr=pr->next;
        }
        pr->next=p;//让尾节点的指针域指向新节点
    }
    printf("请输入数据：\n");
    scanf("%d",&data);

    p->data=data;
    p->next=NULL;

    return head;
}

int SortNode(struct link* head,int len)//升序排序
{
    struct link* p1,*p2;
    int temp,i,j;
    for(i=0,p1=head->next;i<len-1;i++,p1=p1->next)
    {
        for(j=i+1,p2=p1->next;j<len;j++,p2=p2->next)
        {
            if(p1->data > p2->data)
            {
                temp=p1->data;
                p1->data=p2->data;
                p2->data=temp;
            }
        }
    }
    return 0;
}

struct link* InsertNode(struct link* head,int nodedata)//链表本身为升序
{
    struct link* pr=head,*p=NULL,*temp=NULL;
    p=((struct link*)malloc(sizeof(struct link)));
    if(NULL==p)
    {
        printf("分配失败，程序退出\n");
        exit(-1);
    }
    p->next=NULL;//让插入节点指向NULL
    p->data=nodedata;//赋数据域
    if(NULL==head)
    {
        head=p;//将插入节点作为头节点
    }
    else
    {
        while(pr->data<nodedata && pr->next!=NULL)//其中一个为假则退出循环
        {
            temp=pr;//记录向下一个节点移动前时的节点
            pr=pr->next;//指向下一个节点
        }
        if(pr->data >= nodedata)
        {
            if(pr==head)//在头节点前插入新节点
            {
                p->next=head;
                head=p;
            }
            else//中间插入新节点
            {
                p->next=temp->next;//新节点p指向的原本temp指向的节点
                temp->next=p;//现在temp指向的是新节点p
            }
        }
        else//插入的节点的数据域比链表内的都大
        {
            pr->next=p;//让尾节点指向新节点
        }
    }
    return head;
}

struct link* DeleteNode(struct link*head,int nodedata)
{
    struct link*p=head,*pr;
    if(NULL==head)
    {
        printf("要删除的节点不存在");
        exit(-1);
    }
    while(p->data!=nodedata && NULL!=p->next)//其中一个不成立时退出循环
    {
        pr=p;
        p=p->next;
    }
    if(nodedata==p->data)//要删除的节点存在，分删除头节点或中间的节点
    {
        if(p==head)//删除头节点
        {
            head=p->next;//头节点变为原本第二的节点
        }
        else//删除中间的节点
        {
            pr->next=p->next;//让头一节点指向删除节点的后一节点
        }
        free(p);
    }
    else
    {
        printf("要删除的节点不存在");
        exit(-1);
    }
    return head;
}

void DisPlay(struct link* head)
{
    struct link*p=head;
    int j=1;
    while(NULL!=p)
    {
        printf("第%d个节点的数据为%d\n",j,p->data);
        p=p->next;
        j++;
    }
}

struct link* DeleteAll(struct link* head)
{
    struct link*p=head,*pr=NULL;
    while(p!=NULL)
    {
        pr=p;
        p=p->next;
        free(pr);
    }
    head=NULL;
    return head;
}

void Menu(struct link* head,int len,int nodedata)
{
    int key,flag=1;
    char flag1,c;
    do
    {
        printf("请选择对链表进行哪项操作：\n");
        printf("1:创建\t2:排序\t3:插入\t4:删除\t5:输出\t6:销毁\t");
        printf("7:退出页面\n");
        scanf("%d",&key);

    switch(key)
    {
        case 1:
            do
            {
                printf("创建链表\n");
                head=CREATandADDnode(head);
                printf("是否想再创建一个新节点，并接在尾部？(y/n)\n");
                getchar();
                scanf("%c",&c);
                if(c=='Y'||c=='y')
                    flag1=1;
                else
                    flag1=0;
                len++;
            }while(flag1);break;
        case 2:
            {
                printf("升序链表\n");
                SortNode(head,len);
                printf("已完成\n");
            }
        case 3:
            do
            {
                printf("请输入插入节点的数据域：\n");
                scanf("%d",&nodedata);
                head=InsertNode(head,nodedata);
                printf("是否想再插入一个新节点？(y/n)\n");
                getchar();
                scanf("%c",&c);
                if(c=='Y'||c=='y')
                    flag1=1;
                else
                    flag1=0;
            }while(flag1);break;
        case 4:
            do
            {
                printf("请输入删除节点的数据域：\n");
                scanf("%d",&nodedata);
                head=DeleteNode(head,nodedata);
                printf("是否想再删除一个新节点？(y/n)\n");
                getchar();
                scanf("%c",&c);
                if(c=='Y'||c=='y')
                    flag1=1;
                else
                    flag1=0;
            }while(flag1);break;
        case 5:
                printf("输出链表\n");
                DisPlay(head);
                break;
        case 6:
                printf("销毁链表\n");
                head=DeleteAll(head);
                break;
        case 7:
                printf("退出\n");
                flag=0;
                break;
        default:
                printf("输入有误，请重新输入\n");
                break;
        }

    }while(flag);
}

int main()
{
    int len=0,nodedata=0;
    struct link* head=NULL;
    Menu(head,len,nodedata);
    return 0;
}
