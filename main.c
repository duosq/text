#include <stdio.h>
#include <stdlib.h>
struct link
{
    int data;
    struct link* next;
};

struct link* CREATandADDnode(struct link* head)//β�巨
{
    struct link* p=NULL,*pr=head;
    int data;
    p=(struct link*)malloc(sizeof(struct link));
    if(NULL==p)
    {
        printf("����ռ�ʧ�ܣ��˳�����\n");
        exit(-1);
    }
    if(NULL==head)
    {
        head=p;//���½ڵ㵱��ͷ�ڵ�
    }
    else
    {
        while(NULL!=pr->next)//���˳�����ʱ��pr��β�ڵ�
        {
            pr=pr->next;
        }
        pr->next=p;//��β�ڵ��ָ����ָ���½ڵ�
    }
    printf("���������ݣ�\n");
    scanf("%d",&data);

    p->data=data;
    p->next=NULL;

    return head;
}

int SortNode(struct link* head,int len)//��������
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

struct link* InsertNode(struct link* head,int nodedata)//������Ϊ����
{
    struct link* pr=head,*p=NULL,*temp=NULL;
    p=((struct link*)malloc(sizeof(struct link)));
    if(NULL==p)
    {
        printf("����ʧ�ܣ������˳�\n");
        exit(-1);
    }
    p->next=NULL;//�ò���ڵ�ָ��NULL
    p->data=nodedata;//��������
    if(NULL==head)
    {
        head=p;//������ڵ���Ϊͷ�ڵ�
    }
    else
    {
        while(pr->data<nodedata && pr->next!=NULL)//����һ��Ϊ�����˳�ѭ��
        {
            temp=pr;//��¼����һ���ڵ��ƶ�ǰʱ�Ľڵ�
            pr=pr->next;//ָ����һ���ڵ�
        }
        if(pr->data >= nodedata)
        {
            if(pr==head)//��ͷ�ڵ�ǰ�����½ڵ�
            {
                p->next=head;
                head=p;
            }
            else//�м�����½ڵ�
            {
                p->next=temp->next;//�½ڵ�pָ���ԭ��tempָ��Ľڵ�
                temp->next=p;//����tempָ������½ڵ�p
            }
        }
        else//����Ľڵ��������������ڵĶ���
        {
            pr->next=p;//��β�ڵ�ָ���½ڵ�
        }
    }
    return head;
}

struct link* DeleteNode(struct link*head,int nodedata)
{
    struct link*p=head,*pr;
    if(NULL==head)
    {
        printf("Ҫɾ���Ľڵ㲻����");
        exit(-1);
    }
    while(p->data!=nodedata && NULL!=p->next)//����һ��������ʱ�˳�ѭ��
    {
        pr=p;
        p=p->next;
    }
    if(nodedata==p->data)//Ҫɾ���Ľڵ���ڣ���ɾ��ͷ�ڵ���м�Ľڵ�
    {
        if(p==head)//ɾ��ͷ�ڵ�
        {
            head=p->next;//ͷ�ڵ��Ϊԭ���ڶ��Ľڵ�
        }
        else//ɾ���м�Ľڵ�
        {
            pr->next=p->next;//��ͷһ�ڵ�ָ��ɾ���ڵ�ĺ�һ�ڵ�
        }
        free(p);
    }
    else
    {
        printf("Ҫɾ���Ľڵ㲻����");
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
        printf("��%d���ڵ������Ϊ%d\n",j,p->data);
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
        printf("��ѡ�������������������\n");
        printf("1:����\t2:����\t3:����\t4:ɾ��\t5:���\t6:����\t");
        printf("7:�˳�ҳ��\n");
        scanf("%d",&key);

    switch(key)
    {
        case 1:
            do
            {
                printf("��������\n");
                head=CREATandADDnode(head);
                printf("�Ƿ����ٴ���һ���½ڵ㣬������β����(y/n)\n");
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
                printf("��������\n");
                SortNode(head,len);
                printf("�����\n");
            }
        case 3:
            do
            {
                printf("���������ڵ��������\n");
                scanf("%d",&nodedata);
                head=InsertNode(head,nodedata);
                printf("�Ƿ����ٲ���һ���½ڵ㣿(y/n)\n");
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
                printf("������ɾ���ڵ��������\n");
                scanf("%d",&nodedata);
                head=DeleteNode(head,nodedata);
                printf("�Ƿ�����ɾ��һ���½ڵ㣿(y/n)\n");
                getchar();
                scanf("%c",&c);
                if(c=='Y'||c=='y')
                    flag1=1;
                else
                    flag1=0;
            }while(flag1);break;
        case 5:
                printf("�������\n");
                DisPlay(head);
                break;
        case 6:
                printf("��������\n");
                head=DeleteAll(head);
                break;
        case 7:
                printf("�˳�\n");
                flag=0;
                break;
        default:
                printf("������������������\n");
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
