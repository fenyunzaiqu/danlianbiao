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
Linklist DeleteMin(Linklist &L);//2.3.4 带头节点单链表中删除唯一最小元素
Linklist Reverse_1(Linklist L);//2.3.5.1逆置的第一种算法，将头节点摘下，然后依次用头插法插入，就达到逆置的效果
Linklist Reverse_2(Linklist L);//2.3.5.2逆置的第二种算法，将前驱指针pre，后驱指针r反转
void AscendSort(Linklist &L);//2.3.6 将单链表升序排序，还有一种是遍历访问完数据域，将他们存储到数组中后排序，然后再按顺序将数据重写入链表

int main()
{
    Linklist L=NULL;
    List_TrailInsert(L);
    showLinklist(L);
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
/* 2.3.3题的输入输出
    Res_Print(L);
    showLinklist(L);
*/
/*2.3.4题
    DeleteMin(L);
*/
/* 2.3.5题的不同两种算法
    showLinklist(Reverse_1(L));
    showLinklist(Reverse_2(L));
*/
    AscendSort(L);
    showLinklist(L);
    //cout<<GetElem(L, 3)->data<<endl; 用移动指针的方式来访问数据
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
    int A[]={1,3,1,2,3};
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

//2.3.4 删除带头节点单链表中唯一的最小元素
Linklist DeleteMin(Linklist &L)
{
    Node *p=L->next->next,*q=L->next,*pre=L,*minpre=L;//因为删除节点后，需要将删除节点的前后连接起来，所以要多用pre和minpre指针来做到。
    while(p!=NULL)
    {
        if(p->data<q->data)
        {
            q=p;//删除节点q
            minpre=pre;//删除节点q的前驱
        }
        pre=p;//更新pre指针和最小节点指针要在最后，注意顺序
        p=p->next;
    }
    minpre->next=q->next;//将删除节点的前后连接起来
    free(q);
    return L;
}

//2.3.5.1逆置的第一种算法，将头节点摘下，然后依次用头插法插入，就达到逆置的效果
Linklist Reverse_1(Linklist L)
{
    Node *p=L->next,*q=p->next;
    L->next=NULL;
    while(p!=NULL)
    {
        q=p->next;//q用来储存p的下一个节点（后继），这次需要插p进去。因为修改了p—>next,所以需要用q来储存
        p->next=L->next;//因为是用的头插法，所以要把L本来在后面的插在p后面
        L->next=p;//然后将p插在L后面
        p=q;//最后将p节点向后移，
    }
    return L;
}

//2.3.5.2 通过三个相临的节点不断逆置指针指向来达到逆置的效果
Linklist Reverse_2(Linklist L)
{
    Node *p=L->next,*r=p->next,*pre;
    p->next=NULL;
    while(r!=NULL)
    {
        pre=p;//遍历将p和r指针向后移，然后用pre储存p的位置
        p=r;
        r=r->next;
        p->next=pre;//然后将指针反向指向
    }
    L->next=p;//终止循环的条件是p的下一个节点为NULL，然后将头节点与最后一个节点连接。
    return L;
}

//2.3.6 升序排序单链表
void AscendSort(Linklist &L)
{
    Node *p=L->next,*q=p->next,*pre;//pre是新建只有一个元素链表（抽象）的指针，本质上是L的第一个节点p断开了后面的链接，造成L变成了新建链表，而q储存着后面链表的信息
    p->next=NULL;//以第一个节点构造只有一个节点的链表
    p=q;//断开后将后面的“地址信息”重新给p
    while(p!=NULL)
    {
        pre=L;//从头开始扫描，所以总要把pre置头节点
        q=p->next;//因为这一轮循环会将原来第二个节点断开，所以要向后一位储存链表信息
        while(pre->next!=NULL&&pre->next->data<p->data)
            //当pre没遍历到最后一个节点，且只要是pre遍历到的data比第一个节点小的就继续遍历（找到比p节点大的接上），第一轮循环只有1，然后pre->next就为空了，发现p->data即原来的比它大，就退出循环
            pre=pre->next;//遍历，到新建链表的尽头或者找到比p->data大的节点
        p->next=pre->next;//在新建链表中，将比p->data大的节点接到p后面，即把比p大的放在p后面，然后pre节点比p小，pre->next比p大，这一步也是将p节点与原本的链表断开了，如果p正巧是新链表中最大的，那么这个p->next也是Null,被放在了队尾
        pre->next=p;//然后将p节点放在pre后面，也就是p节点插入了pre（新链表中），上一个比它大，下一个比它小的指针
        p=q;//然后p节点在原本链表向后移一位
    }
}
