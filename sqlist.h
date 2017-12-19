#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED
#include<iostream>
using namespace std;
struct Node
{
// 数据成员:
    int data;				// 数据域
    Node *next;		// 指针域

// 构造函数模板:
    Node();						// 无参数的构造函数模板
    Node(int item, Node *link = NULL);	// 已知数据元素值和指针建立结构
};
Node::Node()
// 操作结果：构造指针域为空的结点
{
    next = NULL;
}

Node::Node(int item, Node *link)
// 操作结果：构造一个数据域为item和指针域为link的结点
{
    data = item;
    next = link;
}
class SimpleLinkList
{
protected:
//  链表实现的数据成员:
    Node *head;		// 头结点指针

// 辅助函数模板:
    Node *GetElemPtr(int position) const;	// 返回指向第position个结点的指针
    void Init();				// 初始化线性表

public:
//  抽象数据类型方法声明及重载编译系统默认方法声明:
    SimpleLinkList();			// 无参数的构造函数模板
    virtual ~SimpleLinkList();	// 析构函数模板
    int Length() const;			// 求线性表长度
    bool Empty() const;			// 判断线性表是否为空
    void Clear();				// 将线性表清空
    void Traverse() const;	// 遍历线性表
    bool GetElem(int position, int &e) const;	// 求指定位置的元素
    bool SetElem(int position, const int &e);	// 设置指定位置的元素值
    bool Delete(int position, int &e);			// 删除元素
    bool Insert(int position, const int &e);		// 插入元素
    SimpleLinkList(const SimpleLinkList &copy);	// 复制构造函数模板
    SimpleLinkList(int a[],int n);
    bool Delete_x(int &x);

};


// 简单线性链表类模板的实现部分
Node *SimpleLinkList::GetElemPtr(int position) const
// 操作结果：返回指向第position个结点的指针
{
    Node *tmpPtr = head;		// 用tmpPtr遍历线性表以查找第position个结点
    int curPosition = 0;				// tmpPtr所指结点的位置

    while (tmpPtr != NULL && curPosition < position)
        // 顺指针向后查找，直到tmpPtr指向第position个结点
    {
        tmpPtr = tmpPtr->next;
        curPosition++;
    }

    if (tmpPtr != NULL && curPosition == position)
    {
        // 查找成功
        return tmpPtr;
    }
    else
    {
        // 查找失败
        return NULL;
    }

}

void SimpleLinkList::Init()
// 操作结果：初始化线性表
{
    head = new Node;		// 构造头指针

}

SimpleLinkList::SimpleLinkList()
// 操作结果：构造一个空链表
{
    Init();
}


SimpleLinkList::~SimpleLinkList()
// 操作结果：销毁线性表
{
    Clear();			// 清空线性表
    delete head;		// 释放头结点所点空间
}

int SimpleLinkList::Length() const
// 操作结果：返回线性表元素个数
{
    int count = 0;		// 计数器
    for (Node *tmpPtr = head->next; tmpPtr != NULL; tmpPtr = tmpPtr->next)
    {
        // 用tmpPtr依次指向每个元素
        count++;	// 对线性表的每个元素进行计数
    }
    return count;
}

bool SimpleLinkList::Empty() const
// 操作结果：如线性表为空，则返回true，否则返回false
{
    return head->next == NULL;
}

void SimpleLinkList::Clear()
// 操作结果：清空线性表
{

    int tmpElem;	// 临时元素值
    while (Length() > 0)
    {
        // 表性表非空，则删除第1个元素
        Delete(1, tmpElem);
    }
}

void SimpleLinkList::Traverse() const
// 操作结果：依次对线性表的每个元素调用函数(*visit)
{
    for (Node *tmpPtr = head->next; tmpPtr != NULL; tmpPtr = tmpPtr->next)
    {
        // 用tmpPtr依次指向每个元素
        cout<<tmpPtr->data<<" ";	// 对线性表的每个元素调用函数(*visit)
    }
    cout<<endl;
}

bool SimpleLinkList::GetElem(int position, int &e) const
// 操作结果：当线性表存在第position个元素时，用e返回其值，返回ENTRY_FOUND,
//	否则返回NOT_PRESENT
{
    if (position < 1 || position > Length())
    {
        // position范围错
        return false;	// 元素不存在
    }
    else
    {
        // position合法
        Node *tmpPtr;
        tmpPtr = GetElemPtr(position);	// 取出指向第position个结点的指针
        e = tmpPtr->data;				// 用e返回第position个元素的值
        return true;
    }
}

bool SimpleLinkList::SetElem(int position, const int &e)
// 操作结果：将线性表的第position个位置的元素赋值为e,
//	position的取值范围为1≤position≤Length(),
//	position合法时返回SUCCESS,否则返回RANGE_ERROR
{
    if (position < 1 || position > Length())
    {
        // position范围错
        return false;
    }
    else
    {
        // position合法
        Node *tmpPtr;
        tmpPtr = GetElemPtr(position);	// 取出指向第position个结点的指针
        tmpPtr->data = e;				// 设置第position个元素的值
        return true;
    }
}

bool SimpleLinkList::Delete(int position, int &e)
// 操作结果：删除线性表的第position个位置的元素, 并用e返回其值,
//	position的取值范围为1≤position≤Length(),
//	position合法时返回SUCCESS,否则返回RANGE_ERROR
{
    if (position < 1 || position > Length())
    {
        // position范围错
        return false;
    }
    else
    {
        // position合法
        Node *tmpPtr;
        tmpPtr = GetElemPtr(position - 1);		// 取出指向第position-1个结点的指针
        Node *nextPtr = tmpPtr->next;	// nextPtr为tmpPtr的后继
        tmpPtr->next = nextPtr->next;			// 删除结点
        e = nextPtr->data;						// 用e返回被删结点元素值
        delete nextPtr;							// 释放被删结点
        return true;
    }
}

bool SimpleLinkList::Insert(int position, const int &e)
// 操作结果：在线性表的第position个位置前插入元素e
//	position的取值范围为1≤position≤Length()+1
//	position合法时返回SUCCESS, 否则返回RANGE_ERROR
{
    if (position < 1 || position > Length() + 1)
    {
        // position范围错
        return false; // 位置不合法
    }
    else
    {
        // position合法
        Node *tmpPtr;
        tmpPtr = GetElemPtr(position - 1);	// 取出指向第position-1个结点的指针
        Node *newPtr;
        newPtr = new Node(e, tmpPtr->next);// 生成新结点
        tmpPtr->next = newPtr;			// 将tmpPtr插入到链表中
        return true;
    }
}


SimpleLinkList::SimpleLinkList(const SimpleLinkList &copy)
// 操作结果：由线性表copy构造新线性表——复制构造函数模板
{
    int copyLength = copy.Length();		// copy的长度
    int e;
    Init();								// 初始化线性表

    for (int curPosition = 1; curPosition <= copyLength; curPosition++)
    {
        // 复制数据元素
        copy.GetElem(curPosition, e);	// 取出第curPosition个元素
        Insert(Length() + 1, e);		// 将e插入到当前线性表
    }
}


SimpleLinkList::SimpleLinkList(int a[],int n)
{
    int copyLength = n;		// copy的长度
    int e;
    Init();								// 初始化线性表

    for (int curPosition = 1; curPosition <= copyLength; curPosition++)
    {
        // 复制数据元素
        Insert(Length() + 1, a[curPosition-1]);		// 将e插入到当前线性表
    }
}

bool SimpleLinkList::Delete_x(int &x)   //删除值为x的节点的前一个节点
{
    Node  *p,*q;
    int Position=0;
    bool flag=false;
    p=head;
    p=p->next;
    while(p != NULL)
    {
        Position++;
        if (Position>=2 && p->data == x)
        {
            q = GetElemPtr(Position);
            Node *tmpPtr = q->next;
            q->next = tmpPtr->next;
            delete tmpPtr;
            flag=true;
            Position--;
        }
        p=p->next;
    }
    return flag;
}



#endif // SQLIST_H_INCLUDED
