//
//  main.cpp
//  danlianbiao
//
//  Created by 周南 on 2021/1/24.
//

#include <iostream>
#include <vector>
using namespace::std;
typedef struct Node{
    int data;
    struct Node *next;//因为指针要和它指向的变量是一个数据类型，next指针要指向下一个Lnode，所以也要用Lnode来定义
}LNode, *Linklist;//等同于Node定义了Linklist和LNode，这里下面的Lnode *强调返回的是一个结点（和上面的Node不是一个东西，上面的Node是方法），如Lnode * GetElem(Linklist L, int i)一目了然
//循环双链表
typedef struct NodeD{
    int data;
    struct NodeD *pr;
    struct NodeD *next;
}DNode,*DLinklist;
//20题非循环双链表
typedef struct NonNode{
    int data;
    int freq;
    struct NonNode *pred;
    struct NonNode *next;
}NonDNode,*NonDLinklist;
//22题字母
typedef struct word{
    char data;
    struct word *next;
}wordNode,*wordList;

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
void DeleteBetween(Linklist &L, int left, int right);//2.3.7 将无序带头节点的单链表处于给定两个元素之间的元素删除
Linklist findcommon(Linklist L1, Linklist L2);//2.3.8 寻找两个链表的公共节点
int Length(Linklist L);//计算表长的函数
void SequenceAscend(Linklist L);//2.3.9 依次递增输出单链表的元素并释放节点，不能用数组当辅助存储空间
Linklist Discrete(Linklist &A);//2.3.10 将单链表中奇偶序号的元素分开
Linklist Discrete2(Linklist &A);//2.3.11 一个用头插一个用尾插将元素分开
void DeleteSame(Linklist &L);//2.3.12 在递增单链表中删除相同元素
void MergeAscendList(Linklist &A,Linklist &B);//2.3.13 将两个递增单链表合成为一个递减单链表
Linklist Get_Common(Linklist A,Linklist B);//2.3.14 找出两个递增链表的公共元素，创建出一个新链表
Linklist Union(Linklist &A,Linklist &B);//2.3.15 将两个递增单链表求交集，存放在A链表中
int Pattern(Linklist A,Linklist B);//2.3.16 判断B的序列是不是A的子序列
int Symmetry(DLinklist DL);//2.3.17 判断一个循环双链表是否对称
DLinklist DList_HeadInsert(DLinklist &DL);//头插法创建一个带头节点的循环双链表
void showDLinklist(DLinklist &DL);//展示循环双链表
void showCirularLinklist(Linklist L);//展示循环单链表
Linklist CreateCircularLinklistWithHead(Linklist &L);//创建有头节点的循环单链表
Linklist LinkTwoCircularLinklistWithHead(Linklist &h1,Linklist &h2);//2.3.18 将h2循环单链表接到h1后面
void DeleteMinToNull(Linklist &L);//2.3.19 每次删除循环单链表中最小的节点并释放，直到链表为空
NonDLinklist CreateNonCircularDLinklistWithHead(NonDLinklist &L);//创建带头节点和freq的非循环双向链表
NonDLinklist Locate(NonDLinklist &L, int x);//2.3.20 查找x的节点，摘下（删除），然后插入到该被插（freq）的地方
int FindLastKposition(Linklist L, int k);//2.3.21 找到单链表倒数第k个位置的元素的值
wordList CreateWordListWithHead(wordList &L, vector<char>A, wordList &r);
int wordlen(wordNode *L);
wordNode* find_addr(wordNode *str1,wordNode *str2);//2.3.22 找到两个有公共后缀链表的第一个公共节点
void DeleteAbsoulute(Linklist &L,int n);//2.3.23 删除单链表重复的绝对值，并用数组下标储存
int MaxAbsoultedata(Linklist L);
Linklist FindCirularNode(Linklist L);//2.3.24 判断一个单链表里有没有环，如果有，则输出环的入口
void changelist(Linklist L);//2.3.25 将a1,a2,a3..an重新排列为 a1,an,a2,an-1..

LNode *tempp;

int main()
{
    Linklist L=nullptr;
    Linklist B=NULL;
    DLinklist DL;
    DList_HeadInsert(DL);
    List_TrailInsert(L);
    showLinklist(L);
    List_HeadInsert(B);
    showDLinklist(DL);
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
/* 2.3.6的升序排序
    AscendSort(L);
*/
    //DeleteBetween(L, 2, 3); 2.3.7的删除两个之间的元素
/* 2.3.8创建一个有公共节点的单链表并查找公共节点
    Linklist L2=NULL,L3=NULL;//L2是公共节点（链表）
    List_HeadInsertWithoutHead(L2);//创建公共节点第一个值为13的链表
    List_HeadInsert(L3);//短链表
    Node *p=L->next,*q=L3->next;//将p指针和q指针移动到L和L3的末尾
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=L2;//将L和L3的末尾接上L2
    while(q->next!=NULL)
    {
        q=q->next;
    }
    q->next=L2;
    cout<<findcommon(L, L3)->data<<endl;
*/
    //SequenceAscend(L); 2.3.9 升序输出元素
    //showLinklist(Discrete(L)); 2.3.10将奇偶序号的元素分为两个链表，这个返回的事偶数序号的链表，原来的链表被接上了奇数序号节点z
    //showLinklist(Discrete2(L));2.3.11一个用尾插法，一个用头插法
    //DeleteSame(L);2.3.12 将重复的元素删除
    //MergeAscendList(L, B);2.3.13 合并两个递增单链表为单个递减单链表
    //showLinklist(Get_Common(L, B));2.3.15 一个奇数序号尾插，一个偶数序号头插
    //Pattern(L, B);2.3.16 判断B是不是A的子序列
    //Symmetry(DL);2.3.17 判断循环双链表是否对称
    /*2.3.18 将两个循环单链表连起来，且还为循环形式
    Linklist h1=NULL,h2=NULL;
    CreateCircularLinklistWithHead(h1);
    CreateCircularLinklistWithHead(h2);
    showCirularLinklist(h1);
    LinkTwoCircularLinklistWithHead(h1, h2);
    showCirularLinklist(h1);
     */
    /*2.3.19的测试流程
    Linklist h1=NULL;
    CreateCircularLinklistWithHead(h1);
    DeleteMinToNull(h1);
    */
    /*2.3.20的测试流程
    NonDLinklist L2;
    CreateNonCircularDLinklistWithHead(L2);
    cout<<Locate(L2, 2)<<endl;
    Locate(L2, 3);
    Locate(L2, 3);
    */
    //FindLastKposition(L, 4);2.3.21 找出倒数第k个元素
    /* 2.3.22 创建一个有公共后缀的链表好，找出公共节点的地址
    vector<char>A1={'l','o','a','d'};
    vector<char>B1={'b','e'};
    vector<char>C1={'i','n','g'};
    wordList L1,L2,L3,pl1,pl2,pl3;
    CreateWordListWithHead(L1, A1, pl1);
    CreateWordListWithHead(L2, B1, pl2);
    CreateWordListWithHead(L3, C1, pl3);
    pl1->next=L3->next;
    pl2->next=L3->next;
    cout<<find_addr(L1, L2)->data<<endl;
    */
    /*2.3.23的测试程序
     int n=MaxAbsoultedata(L);
    DeleteAbsoulute(L, n);
    */
    /*2.3.24 制造一个带环的单链表
     Linklist L2=NULL;
    CreateCircularLinklistWithHead(L2);
    tempp->next=L2->next;
    cout<<FindCirularNode(L)->data<<"this"<<endl;
     */
    //cout<<GetElem(L, 3)->data<<endl; 用移动指针的方式来访问数据
    changelist(L);//2.3.25 逆置
    showLinklist(L);
    return 0;
}

//头插法
Linklist List_HeadInsert(Linklist &L)
{
    Node *s;//定义节点s
    L=(Linklist)malloc(sizeof(Node));
    //定义头节点L,并申请内存空间，其中Linklist也可以换成Node*，是一个东西，代表申请空间的数据类型是啥。当没有这个头节点L的时候，需要在每次插入新节点后将它的地址赋值给L 即L=s;
    L->next=nullptr;
    int A[]={7,5,4,3,3};
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
    int A[]={1,2,3,4,5};
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
    int A[]={0,1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<sizeof(A)/sizeof(int);i++)
    {
        s=(Node*)malloc(sizeof(Node));
        s->data=A[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;//最后赋值初始化完需要将尾指针置空来达到“它是尾指针”的目的
    tempp=r;
    return L;
}

//带头节点的循环双链表头插法
DLinklist DList_HeadInsert(DLinklist &DL)
{
    DL=(DLinklist)malloc(sizeof(NodeD));
    DNode *s;
    DL->next=DL;DL->pr=DL;//初始化循环双链表
    int A[]={1,2,3,3,2,1};
    for(int i=0;i<sizeof(A)/sizeof(int);i++)
    {
        if(DL->next!=DL)
        {
            s=(DNode*)malloc(sizeof(NodeD));
            s->data=A[i];
            s->next=DL->next;
            DL->next->pr=s;
            DL->next=s;
            s->pr=DL;
        }
        else
        {
            s=(DNode*)malloc(sizeof(NodeD));
            s->data=A[i];
            s->next=DL->next;
            DL->next=s;
            s->pr=DL;
            DL->pr=s;
        }
    }
    return DL;
}

//创建有头节点的循环单链表，尾插法
Linklist CreateCircularLinklistWithHead(Linklist &L)
{
    L=(Linklist)malloc(sizeof(Node));
    Node *r=L,*s;
    int A[]={1,2,3};
    for(int i=0;i<sizeof(A)/sizeof(int);i++)
    {
        s=(Node*)malloc(sizeof(Node));
        s->data=A[i];
        r->next=s;
        r=s;
    }
    r->next=L;
    return L;
}

//尾插法创建非循环双链表
NonDLinklist CreateNonCircularDLinklistWithHead(NonDLinklist &L)
{
    L=(NonDLinklist)malloc(sizeof(NonNode));
    L->pred=NULL;
    NonDNode *s,*r=L;
    int A[]={1,2,3,4,5,6,7};
    for(int i=0;i<sizeof(A)/sizeof(int);i++)
    {
        s=(NonDNode*)malloc(sizeof(NonNode));
        s->data=A[i];
        s->freq=0;
        r->next=s;
        s->pred=r;
        s->next=NULL;
        r=s;
    }
    return L;
}

//尾插法
wordList CreateWordListWithHead(wordList &L, vector<char>A,wordList &r)
{
    L=(wordList)malloc(sizeof(word));
    L->next=NULL;
    wordNode *s;
    r=L;//r为尾指针
    for(int i=0;i<A.size();i++)
    {
        s=(wordNode*)malloc(sizeof(word));
        s->data=A[i];
        s->next=NULL;
        r->next=s;
        r=s;
    }
    return L;
}

//展示循环双链表
void showDLinklist(DLinklist &DL)
{
    DNode *s=DL->next;
    while(s!=DL)//当s没回到头节点
    {
        cout<<s->data<<" ";
        s=s->next;
    }
    cout<<endl;
}

//展示循环单链表
void showCirularLinklist(Linklist L)
{
    Node *s=L->next;
    while(s!=L)
    {
        cout<<s->data<<" ";
        s=s->next;
    }
    cout<<endl;
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
    Node *p=L->next,*q=p->next,*pre;//pre是新建只有一个元素链表（抽象的指针，本质上是L的第一个节点p断开了后面的链接，造成L变成了新建链表，而q储存着后面链表的信息
    p->next=nullptr;//以第一个节点构造只有一个节点的链表
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

//2.3.7 将无序带头节点的单链表处于给定两个元素之间的元素删除
void DeleteBetween(Linklist &L, int left, int right)
{
    Node *p=L->next,*pre=L;
    while(p!=NULL)
    {
        if(p->data>=left&&p->data<=right)
        {
            pre->next=p->next;//断开p的前驱节点与p的链接，将pre连到p的下一个节点
            free(p);//删除节点p
            p=pre->next;//将p节点移动到pre的下一个节点
        }
        else
        {
            pre=p;//两个指针同时向后移动一个
            p=p->next;
        }
    }
}

//2.3.8 寻找两个单链表的公共节点
Linklist findcommon(Linklist L1, Linklist L2)
{
    int len1=Length(L1),len2=Length(L2);//得到两个单链表的长度
    int distance=0;//长度之差
    Linklist longList,shortList;
    if(len1>len2)//根据长度来决定哪个是长链表，哪个是短链表
    {
        longList=L1->next;
        shortList=L2->next;
        distance=len1-len2;
    }
    else
    {
        longList=L2->next;
        shortList=L1->next;
        distance=len2-len1;
    }
    while(distance--)//将长链表的指针移到直到长度与短链表相同
    {
        longList=longList->next;
    }
    while (longList!=NULL) {
        if(longList==shortList)//到达公共节点
            return longList;
        else//否则一起同时向后遍历
        {
            longList=longList->next;
            shortList=shortList->next;
        }
    }
    return NULL;
}

//求数组长度的函数
int Length(Linklist L)
{
    Node *p=L;
    int length=0;
    if(L->data==0)//如果第一个节点是头节点，那么长度-1；
        length=-1;
    while(p!=NULL)
    {
        p=p->next;
        length++;
    }
    return length;
}

//2.3.9 升序输出带头节点单链表中的元素
void SequenceAscend(Linklist L)
{
    Node *p,*min,*minpre;//只能用p->next来做访问，因为如果多加一个p的前驱pre，然后直接用p->data来比较，那只剩一个节点的时候，p就是无法访问的Null指针，除非再多些一个if处理。
    while(L->next!=NULL)
    {
        p=L->next;//扫描节点
        minpre=L;//最小值节点的前驱
        while (p->next!=NULL) {
            if(p->next->data<minpre->next->data)//两个前驱节点均用next访问，这样找到minpre就能在删除min节点后，重新连上
            {
                minpre=p;
                p=p->next;
            }
            else
            {
                p=p->next;
            }
        }
        min=minpre->next;
        minpre->next=min->next;//将这次循环最小元素的前后节点连起来
        cout<<min->data<<" ";
        free(min);
    }
    free(L);//删除头节点
}

//2.3.10 奇偶序号不同输出
Linklist Discrete(Linklist &A)
{
    int i=0;//虽然完全可以不计数，但如果一次处理两个节点，很容易第二个节点就是末尾的NULL节点，这时候就要多写一个if判断，所以不如简单的来个计数i，然后每次循环处理一个节点。
    Linklist B=(Linklist)malloc(sizeof(Node));
    B->next=NULL;
    Node *ra=A,*rb=B;//创建链表的尾节点，这样好不断衔接尾插链表
    Node *p=A->next;//遍历的工作指针
    A->next=NULL;//断开A链表的头节点
    while(p!=NULL)
    {
        i++;
        if(i%2!=0)
        {
            ra->next=p;
            ra=p;
        }
        if(i%2==0)
        {
            rb->next=p;
            rb=p;
        }
        p=p->next;
    }
    ra->next=NULL;//设置尾节点：即下一个节点为Null
    rb->next=NULL;
    return B;
}

//2.3.11 B链表用头插法
Linklist Discrete2(Linklist &A)
{
    Linklist B=(Linklist)malloc(sizeof(Node));
    B->next=NULL;
    Node *ra=A,*p=A->next,*q;
    A->next=NULL;
    while(p!=NULL)
    {
        ra->next=p;
        ra=p;
        p=p->next;
        if(p!=NULL)//括号要全扩住
        {
            q=p->next;
            p->next=B->next;//将p的下一个节点断为B的第一个节点
            B->next=p;//接着将头节点的下一个节点接为B
            p=q;//向后移一个节点
        }
    }
    ra->next=NULL;
    return B;
}

//2.3.12 在递增单链表中删除相同元素
void DeleteSame(Linklist &L)
{
    Node *p=L->next,*q=p->next;//这里要用两个节点，扫描节点p和后继节点q
    while(p->next!=NULL)
    {
        q=p->next;//每次循环保证q是p的下一个节点
        if(p->data==q->data)
        {
            p->next=q->next;
            free(q);
        }
        else
        p=p->next;//这里p进下一个节点一定要写else里，因为如果出现多个重复的话 如111，p扫到第一个1，删除第二个1，如果这时候就直接进入下一个节点，就会有第三个1没删掉
    }
}

//2.3.13 将一个递增单链表合并为一个递减单链表
void MergeAscendList(Linklist &A,Linklist &B)
{
    Node *a=A->next,*b=B->next,*r;
    A->next=NULL;//将A链表断开
    while(a!=NULL&&b!=NULL)//当AB链表均没有遍历到最后一个指针
    {
        if(a->data<b->data)
        {
            r=a->next;//r用来存放a指针后面节点的位置信息
            a->next=A->next;//头插法，把a插到A的头节点与第一个节点之间
            A->next=a;
            a=r;
        }
        else
        {
            r=b->next;//头插到A、
            b->next=A->next;
            A->next=b;
            b=r;
        }
    }
    if(a)//如果A链表有多的
    {
        b=a;//a指针付给b指针
    }
    while(b!=NULL)
    {
        r=b->next;//头插到A
        b->next=A->next;
        A->next=b;
        b=r;
    }
    free(B);
}

//2.3.14 找出两个递增链表的公共元素，创建出一个新链表
Linklist Get_Common(Linklist A,Linklist B)
{
    Linklist C=(Linklist)malloc(sizeof(Node));
    Node *ra=A->next,*rb=B->next,*rc=C,*s;//s为创建节点
    while(ra!=NULL&&rb!=NULL)
    {
        if(ra->data<rb->data)//重点！当两个指针，其中一个比较小的时候，较小的就往后移一个
            ra=ra->next;
        else if(ra->data>rb->data)
            rb=rb->next;
        else//当两个指针的元素相同时，就创建节点尾接，然后
        {
            s=(Node*)malloc(sizeof(Node));
            s->data=ra->data;
            rc->next=s;//尾插法，接在尾上
            rc=rc->next;//然后向后移一位
            ra=ra->next;//a,b扫描的指针也同时往后移一位
            rb=rb->next;
        }
    }
    rc->next=NULL;
    return C;
}

//2.3.15 将两个递增单链表求交集，存放在A链表中
Linklist Union(Linklist &A,Linklist &B)
{
    Node *pa=A->next,*pb=B->next,*pc=A,*u;//pc为合并节点的前驱指针,u为删除节点的指针
    while(pa!=NULL&&pb!=NULL)//同上题，多加了一个u来删除节点
    {
        if(pa->data>pb->data)
        {
            u=pb;
            pb=pb->next;
            free(u);
        }
        else if(pa->data<pb->data)
        {
            u=pa;
            pa=pa->next;
            free(u);
        }
        else
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
            u=pb;
            pb=pb->next;
            free(u);
        }
    }
    while(pa)//pa不为Null
    {
        u=pa;
        pa=pa->next;
        free(u);
    }
    while(pb)//pb不为Null
    {
        u=pb;
        pb=pb->next;
        free(u);
    }
    pc->next=NULL;//设置尾节点
    free(B);//删除B头
    return A;
}

//2.3.16 判断B是不是A的子序列
int Pattern(Linklist A,Linklist B)
{
    Node *ra=A->next,*rb=B->next,*pre=ra;//扫描是有一个没对上，A的扫描指针就往后移一个，然后B指针从头开始扫，所以这个pre指针很关键
    while(ra!=NULL&&rb!=NULL)//其实真正节省空间的判断条件是A的剩余长度小于B的长度就停止循环
    {
        if(ra->data==rb->data)//指针共同前进
        {
            ra=ra->next;
            rb=rb->next;
        }
        else//指针重置
        {
            pre=pre->next;
            rb=B->next;
            ra=pre;
        }
    }
    if(rb==NULL)//B扫完了
    {
        cout<<"B是A的子序列"<<endl;
        return 1;
    }
    else
    {
        cout<<"B不是A的子序列"<<endl;
        return 0;
    }
}

//2.3.17 判断双链表是否对称
int Symmetry(DLinklist DL)
{
    DNode *p=DL->next,*q=DL->pr;
    while (p!=q&&q->next!=p) {//如果是偶数个元素，那么终止条件尾p的下一个不为q，如果为偶数个元素，那么循环终止条件p不为q
        if(p->data==q->data)
        {
            p=p->next;//p往前指q往后指
            q=q->pr;
        }
        else
        {
            cout<<"不为对称双链表"<<endl;
            return 0;
        }
    }
    cout<<"为循环双链表"<<endl;
    return 1;
}

//2.3.18 将h2循环单链表接到h1后面，保持循环链表
Linklist LinkTwoCircularLinklistWithHead(Linklist &h1,Linklist &h2)
{
    Node *p=h1,*q;//p指向h1的尾节点，q指向h2的尾节点
    while(p->next!=h1)
        p=p->next;
    q=h2;
    while(q->next!=h2)
        q=q->next;
    p->next=h2;
    q->next=h1;
    return h1;
}

//2.3.19 每次将循环单链表中最小的元素删除直到为空
void DeleteMinToNull(Linklist &L)
{
    Node *min,*p,*premin,*pre;//要四个变量，两个不够，三个也不够,且初始化放循环里，删一个节点就初始化
    while(L->next!=L)//这里结束循环的条件是只剩一个头节点，那么它的下一个节点也是自己
    {
        p=L->next;pre=L;
        min=p;premin=pre;
        while(p!=L)
        {
            if(p->data<min->data)
            {
                min=p;//赋值
                premin=pre;
            }
            p=p->next;
            pre=pre->next;//移动节点
        }
        cout<<min->data<<" ";
        premin->next=min->next;
        free(min);//释放
    }
    cout<<endl;
    free(L);
}

//2.3.20 x元素的查找，删除，插入算法
NonDLinklist Locate(NonDLinklist &L, int x)
{
    NonDNode *r=L->next,*p;
    while(r!=NULL)
    {
        if(r->data==x)//找到x元素的位置
        {
            r->freq++;
            if(r->next==NULL)//防止r元素在最后一位，将r前后链接，把r摘出来
            {
                r->pred->next=NULL;
            }
            else
            {
                r->pred->next=r->next;
            }
            break;
        }
        r=r->next;//没找到就遍历
    }
    p=r->pred;//p为r前一个节点，因为r的freq增加了一，肯定至少要往前挪
    while (p!=L&&p->freq<=r->freq) {//查找要插入的位置，到头节点或频率刚刚大于找出来的r节点位置
        p=p->pred;//往前挪
    }
    r->next=p->next;//首先，插入的位置是在p和p的下一个之间，所以r的下一个是p的下一个
    p->next->pred=r;//然后p的下一个的前一个是r，也就是p的下一个和r链接起来了
    r->pred=p;//将r和p链接
    p->next=r;
    return r;//返回找到的元素的地址
}

//2.3.21 找出倒数第k个元素
int FindLastKposition(Linklist L,int k)
{
    Node *p=L->next,*pr=p;//p是往前k个，pr是一开始
    int count=0;//计数，让p跑到前面第k个地方
    while(count!=k)
    {
        p=p->next;
        count++;
    }
    while(p!=NULL)//p到末尾，pr就是倒数第k个了
    {
        p=p->next;
        pr=pr->next;
    }
    if(count<k)
        return 0;
    else
    {
        cout<<pr->data<<endl;
        return 1;
    }
}

int wordlen(wordNode *L)
{
    int count=0;
    wordNode *p=L;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

//2.3.22 找到公共后缀节点
wordNode* find_addr(wordNode *str1,wordNode *str2)
{
    int m,n;
    wordNode *p,*q;
    m=wordlen(str1);
    n=wordlen(str2);
    for(p=str1;m>n;m--)//这个用for赋值并用来判断m和n哪个大的写法非常有意思,功能是遍历到
    p=p->next;
    for(q=str2;n>m;n--)
    q=q->next;
    while(p->next!=NULL&&p->next!=q->next)
    {
        p=p->next;
        q=q->next;
    }
    return p->next;
}


void DeleteAbsoulute(Linklist &L,int n)
{
    vector<int>arr(n+1,0);//创建一个n+1的数组拿来存数，并初始化为0
    Node *p=L,*r;
    while(p->next!=NULL)//p为要被删除节点的前驱
    {
        if(p->next->data<0)//这里可以简写为 <0?x:y
        {
            if(arr[-p->next->data]==0)
            {
                arr[-p->next->data]=1;
                p=p->next;//只有为0（第一个出现的）才能往下继续遍历，要不然会跳过要删的
            }
            else
            {
                r=p->next;
                p->next=p->next->next;
                free(r);
            }
        }
        else
        {
            if(arr[p->next->data]==0)
            {
                arr[p->next->data]=1;
                p=p->next;
            }
            else
            {
                r=p->next;
                p->next=p->next->next;
                free(r);
            }
        }
    }
}

int MaxAbsoultedata(Linklist L)
{
    int max=L->next->data;
    Node *p;
    p=L->next;
    while(p!=NULL)
    {
        if(p->data<0)
        {
            if(-p->data>max)
                max=-p->data;
        }
        else
        {
            if(p->data>max)
                max=p->data;
        }
        p=p->next;
    }
    return max;
}

//判断表里有没有环 如果有 环的入口在哪
Linklist FindCirularNode(Linklist L)
{
    Node *fast=L->next->next,*slow=L->next;//快指针动两格
    while(slow!=NULL&&fast->next!=NULL)//遍历到其中一个到尾节点（下一个为NULL）
    {
        fast=fast->next->next;//这个走两步最好用走一步，如果下一个不为空继续走一步
        slow=slow->next;
        if(slow==fast)//如果是环节点，遇上了就退出循环
            break;
    }
    if(slow==NULL||fast->next==NULL)//如果有个到了尾节点，就返回不是有环单链表
        return NULL;
    Node *p=slow,*r=L;//根据流程图，一个设置在相遇节点，一个设置在头节点，两个依次移动，遇上了就是入口
    while(p!=r)
    {
        p=p->next;
        r=r->next;
    }
    return r;
}

void changelist(Linklist L)//先找中间节点
{
    Node *fast=L,*slow=L,*temp,*insert;//一个走一步一个走两步来找中间节点
    while(fast->next!=NULL)//只能保证指针在最后一个节点时停止循环，要加个如果fast在空节点了，也要停止循环
    {
        fast=fast->next;
        slow=slow->next;
        if(fast!=NULL)
            fast=fast->next;
        if(fast==NULL)
            break;
    }
    fast=slow->next;
    slow->next=NULL;//断链，并开始用头插法来原地逆置
    while(fast!=NULL)
    {
        temp=fast->next;//储存后面节点
        fast->next=slow->next;
        slow->next=fast;
        fast=temp;
    }
    insert=L->next;
    fast=slow->next;
    slow->next=NULL;//断链
    while(fast!=NULL)//开始间接插入
    {
        temp=fast->next;//存储下一个节点的信息
        fast->next=insert->next;//先与后面的接上
        insert->next=fast;//再接前面的
        insert=fast->next;//移动
        fast=temp;
    }
}
