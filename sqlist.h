#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED
#include<iostream>
using namespace std;
struct Node
{
// ���ݳ�Ա:
    int data;				// ������
    Node *next;		// ָ����

// ���캯��ģ��:
    Node();						// �޲����Ĺ��캯��ģ��
    Node(int item, Node *link = NULL);	// ��֪����Ԫ��ֵ��ָ�뽨���ṹ
};
Node::Node()
// �������������ָ����Ϊ�յĽ��
{
    next = NULL;
}

Node::Node(int item, Node *link)
// �������������һ��������Ϊitem��ָ����Ϊlink�Ľ��
{
    data = item;
    next = link;
}
class SimpleLinkList
{
protected:
//  ����ʵ�ֵ����ݳ�Ա:
    Node *head;		// ͷ���ָ��

// ��������ģ��:
    Node *GetElemPtr(int position) const;	// ����ָ���position������ָ��
    void Init();				// ��ʼ�����Ա�

public:
//  �����������ͷ������������ر���ϵͳĬ�Ϸ�������:
    SimpleLinkList();			// �޲����Ĺ��캯��ģ��
    virtual ~SimpleLinkList();	// ��������ģ��
    int Length() const;			// �����Ա���
    bool Empty() const;			// �ж����Ա��Ƿ�Ϊ��
    void Clear();				// �����Ա����
    void Traverse() const;	// �������Ա�
    bool GetElem(int position, int &e) const;	// ��ָ��λ�õ�Ԫ��
    bool SetElem(int position, const int &e);	// ����ָ��λ�õ�Ԫ��ֵ
    bool Delete(int position, int &e);			// ɾ��Ԫ��
    bool Insert(int position, const int &e);		// ����Ԫ��
    SimpleLinkList(const SimpleLinkList &copy);	// ���ƹ��캯��ģ��
    SimpleLinkList(int a[],int n);
    bool Delete_x(int &x);

};


// ������������ģ���ʵ�ֲ���
Node *SimpleLinkList::GetElemPtr(int position) const
// �������������ָ���position������ָ��
{
    Node *tmpPtr = head;		// ��tmpPtr�������Ա��Բ��ҵ�position�����
    int curPosition = 0;				// tmpPtr��ָ����λ��

    while (tmpPtr != NULL && curPosition < position)
        // ˳ָ�������ң�ֱ��tmpPtrָ���position�����
    {
        tmpPtr = tmpPtr->next;
        curPosition++;
    }

    if (tmpPtr != NULL && curPosition == position)
    {
        // ���ҳɹ�
        return tmpPtr;
    }
    else
    {
        // ����ʧ��
        return NULL;
    }

}

void SimpleLinkList::Init()
// �����������ʼ�����Ա�
{
    head = new Node;		// ����ͷָ��

}

SimpleLinkList::SimpleLinkList()
// �������������һ��������
{
    Init();
}


SimpleLinkList::~SimpleLinkList()
// ����������������Ա�
{
    Clear();			// ������Ա�
    delete head;		// �ͷ�ͷ�������ռ�
}

int SimpleLinkList::Length() const
// ����������������Ա�Ԫ�ظ���
{
    int count = 0;		// ������
    for (Node *tmpPtr = head->next; tmpPtr != NULL; tmpPtr = tmpPtr->next)
    {
        // ��tmpPtr����ָ��ÿ��Ԫ��
        count++;	// �����Ա��ÿ��Ԫ�ؽ��м���
    }
    return count;
}

bool SimpleLinkList::Empty() const
// ��������������Ա�Ϊ�գ��򷵻�true�����򷵻�false
{
    return head->next == NULL;
}

void SimpleLinkList::Clear()
// ���������������Ա�
{

    int tmpElem;	// ��ʱԪ��ֵ
    while (Length() > 0)
    {
        // ���Ա�ǿգ���ɾ����1��Ԫ��
        Delete(1, tmpElem);
    }
}

void SimpleLinkList::Traverse() const
// ������������ζ����Ա��ÿ��Ԫ�ص��ú���(*visit)
{
    for (Node *tmpPtr = head->next; tmpPtr != NULL; tmpPtr = tmpPtr->next)
    {
        // ��tmpPtr����ָ��ÿ��Ԫ��
        cout<<tmpPtr->data<<" ";	// �����Ա��ÿ��Ԫ�ص��ú���(*visit)
    }
    cout<<endl;
}

bool SimpleLinkList::GetElem(int position, int &e) const
// ��������������Ա���ڵ�position��Ԫ��ʱ����e������ֵ������ENTRY_FOUND,
//	���򷵻�NOT_PRESENT
{
    if (position < 1 || position > Length())
    {
        // position��Χ��
        return false;	// Ԫ�ز�����
    }
    else
    {
        // position�Ϸ�
        Node *tmpPtr;
        tmpPtr = GetElemPtr(position);	// ȡ��ָ���position������ָ��
        e = tmpPtr->data;				// ��e���ص�position��Ԫ�ص�ֵ
        return true;
    }
}

bool SimpleLinkList::SetElem(int position, const int &e)
// ��������������Ա�ĵ�position��λ�õ�Ԫ�ظ�ֵΪe,
//	position��ȡֵ��ΧΪ1��position��Length(),
//	position�Ϸ�ʱ����SUCCESS,���򷵻�RANGE_ERROR
{
    if (position < 1 || position > Length())
    {
        // position��Χ��
        return false;
    }
    else
    {
        // position�Ϸ�
        Node *tmpPtr;
        tmpPtr = GetElemPtr(position);	// ȡ��ָ���position������ָ��
        tmpPtr->data = e;				// ���õ�position��Ԫ�ص�ֵ
        return true;
    }
}

bool SimpleLinkList::Delete(int position, int &e)
// ���������ɾ�����Ա�ĵ�position��λ�õ�Ԫ��, ����e������ֵ,
//	position��ȡֵ��ΧΪ1��position��Length(),
//	position�Ϸ�ʱ����SUCCESS,���򷵻�RANGE_ERROR
{
    if (position < 1 || position > Length())
    {
        // position��Χ��
        return false;
    }
    else
    {
        // position�Ϸ�
        Node *tmpPtr;
        tmpPtr = GetElemPtr(position - 1);		// ȡ��ָ���position-1������ָ��
        Node *nextPtr = tmpPtr->next;	// nextPtrΪtmpPtr�ĺ��
        tmpPtr->next = nextPtr->next;			// ɾ�����
        e = nextPtr->data;						// ��e���ر�ɾ���Ԫ��ֵ
        delete nextPtr;							// �ͷű�ɾ���
        return true;
    }
}

bool SimpleLinkList::Insert(int position, const int &e)
// ��������������Ա�ĵ�position��λ��ǰ����Ԫ��e
//	position��ȡֵ��ΧΪ1��position��Length()+1
//	position�Ϸ�ʱ����SUCCESS, ���򷵻�RANGE_ERROR
{
    if (position < 1 || position > Length() + 1)
    {
        // position��Χ��
        return false; // λ�ò��Ϸ�
    }
    else
    {
        // position�Ϸ�
        Node *tmpPtr;
        tmpPtr = GetElemPtr(position - 1);	// ȡ��ָ���position-1������ָ��
        Node *newPtr;
        newPtr = new Node(e, tmpPtr->next);// �����½��
        tmpPtr->next = newPtr;			// ��tmpPtr���뵽������
        return true;
    }
}


SimpleLinkList::SimpleLinkList(const SimpleLinkList &copy)
// ��������������Ա�copy���������Ա������ƹ��캯��ģ��
{
    int copyLength = copy.Length();		// copy�ĳ���
    int e;
    Init();								// ��ʼ�����Ա�

    for (int curPosition = 1; curPosition <= copyLength; curPosition++)
    {
        // ��������Ԫ��
        copy.GetElem(curPosition, e);	// ȡ����curPosition��Ԫ��
        Insert(Length() + 1, e);		// ��e���뵽��ǰ���Ա�
    }
}


SimpleLinkList::SimpleLinkList(int a[],int n)
{
    int copyLength = n;		// copy�ĳ���
    int e;
    Init();								// ��ʼ�����Ա�

    for (int curPosition = 1; curPosition <= copyLength; curPosition++)
    {
        // ��������Ԫ��
        Insert(Length() + 1, a[curPosition-1]);		// ��e���뵽��ǰ���Ա�
    }
}

bool SimpleLinkList::Delete_x(int &x)   //ɾ��ֵΪx�Ľڵ��ǰһ���ڵ�
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
