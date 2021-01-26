//
//  main.cpp
//  danlianbiao
//
//  Created by 周南 on 2021/1/24.
//

#include <iostream>
using namespace::std;
typedef struct Node{
    int data;
    struct Node *next;//因为指针要和它指向的变量是一个数据类型，next指针要指向下一个Lnode，所以也要用Lnode来定义
}LNode, *Linklist;//等同于Node定义了Linklist和LNode，这里下面的Lnode *强调返回的是一个结点（和上面的Node不是一个东西，上面的Node是方法），如Lnode * GetElem(Linklist L, int i)一目了然

Linklist List_HeadInsert(Linklist &L);//通过头插法来初始化单链表
Linklist List_TrailInsert(Linklist &L);//通过尾插法来初始化单链表
LNode *GetElem(Linklist L,int i);//按序号查找节点值
Linklist List_HeadInsertWithoutHead(Linklist &L);//不带头节点的头插法
void showLinklist(Linklist L);
void DeleteWithoutHead(Linklist &L, int x);//2.3.1 删除不带头节点的值为x的递归算法（即函数里面套函数，明确终止条件）
void DeleteWithHead(Linklist &L, int x);//2.3.2 删除带头节点值为x的算法
void Res_Print(Linklist L);//2.3.3 倒叙输出带头节点单链表的元素
void DeleteMin(Linklist L);//2.3.4 带头节点单链表中删除唯一最小元素

int main()
{
    Linklist L=NULL;
/* 2.3.1题的输入输出测试
    List_HeadInsertWithoutHead(L);
    showLinklist(L);
    DeleteWithoutHead(L, 1);
    showLinklist(L);
*/
/* 2.3.2题的输入输出
    List_TrailInsert(L);
    showLinklist(L);
    DeleteWithHead(L, 2);
    showLinklist(L);
*/
    List_TrailInsert(L);
    showLinklist(L);
    Res_Print(L);

    //cout<<GetElem(L, 3)->data<<endl; 用移动指针的方式来访问数据
    cout<<"hello"<<endl;
    return 0;
}

//头插法
Linklist List_HeadInsert(Linklist &L)
{
    Node *s;//定义节点s
    L=(Linklist)malloc(sizeof(Node));
    //定义头节点L,并申请内存空间，其中Linklist也可以换成Node*，是一个东西，代表申请空间的数据类型是啥。当没有这个头节点L的时候，需要在每次插入新节点后将它的地址赋值给L 即L=s;
    L->next=NULL;
    int A[]={1,3,4,5,6,12,3,14,5};
    for(int i=0;i<(sizeof(A)/sizeof(int));i++)
    {
        s=(Node*)malloc(sizeof(Node));
        s->data=A[i];
        s->next=L->next;
        L->next=s;
    }
    return L;
}

//不带头节点的头插法
Linklist List_HeadInsertWithoutHead(Linklist &L)
{
    Node *s=NULL;
    int A[]={1,2,3,4,5,1,1};
    for(int i=0;i<(sizeof(A)/sizeof(int));i++)
    {
        s=(Node*)malloc(sizeof(Node));
        s->data=A[i];
        s->next=L;
        L=s;
    }
    return L;
}

//尾插法
Linklist List_TrailInsert(Linklist &L)
{
    L=(Linklist)malloc(sizeof(Node));//因为不需要关心L->next指向哪里，所以也不需要初始化空链表了
    Node *s,*r=L;//需要多一个尾指针r来指向最后一个将要插入的元素，且要先申请L这个空间，再将L的地址赋值给r，
    int A[]={2,2,1,3,2,3,2,2};
    for(int i=0;i<sizeof(A)/sizeof(int);i++)
    {
        s=(Node*)malloc(sizeof(Node));
        s->data=A[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;//最后赋值初始化完需要将尾指针置空来达到“它是尾指针”的目的
    return L;
}

//按序号查找节点值
LNode *GetElem(Linklist L,int i)
{
    int j=1;//用来计数
    LNode *p=L->next;
    if(i==0)
        return L;
    if(i<1)
        return NULL;
    while(p&&j<i)//p不为空（null)即最后一个，那么就找到第i个位置
    {
        p=p->next;//不断指下去
        j++;
    }
    return p;//返回p这个节点
}

void showLinklist(Linklist L)
{
    while (L!=NULL)
    {
        cout<<L->data<<" ";
        L=L->next;
    }
    cout<<endl;
    return;
}

//2.3.1 删除不带头节点的值为x的递归算法（即函数里面套函数，明确终止条件）
void DeleteWithoutHead(Linklist &L, int x)
{
    LNode *p;//用p指向删除节点
    if(L==NULL)
        return;
    if(L->data==x)//当L指向的这个节点数据域为x的时候
    {
        p=L;//要删除这个节点
        L=L->next;//让L指向下个节点，变相的将上一个节点->next变成L->next,跳过了L原本指代的节点连接
        free(p);//释放原来L这个地址
        DeleteWithoutHead(L, x);//这里要注意递归这个函数
    }
    else
        DeleteWithoutHead(L->next, x);//如果数据域不是x，那么跳到下个节点
}

//2.3.2 删除带头节点值为x的算法,并释放空间
void DeleteWithHead(Linklist &L, int x)
{
    Node *p=L->next,*pre=L,*q;//p来起到遍历访问所有节点的作用，和上一题L的作用相同，q用来表示要删除的节点来释放空间，pre是p的前驱节点
    while(p!=NULL)
    {
        if(p->data==x)
        {
            q=p;
            p=p->next;
            pre->next=p;
            free(q);
        }
        else
        {
            pre=p;
            p=p->next;
        }
    }
    return;
}

//2.3.3 反向输出带头节点的单链表
void Res_Print(Linklist L)
{
    if(L->next!=NULL)//确定遍历到最后一个节点
    {
        Res_Print(L->next);//这里可以把函数换成语句写进去，就可以发现最后的节点是最里面的循环，然后它的cout要第一个输出，然后从上到下，第一个节点的cout最后一个输出
    }
    if(L!=NULL) cout<<L->data<<" ";
}
