#include "sqlist.h"
#include <iostream> //如果把下面的链表的类的代码放到一个sqlist的头文件里，那这里需要把这个头文件include进来
using namespace std;

////////////////////////////////////////这个是没有用模板的版本////////////////////////////////////

int main()
{
    int a[9]= {1,5,4,8,6,11,12,13,56};

    SimpleLinkList la(a,9);  //使用构造函数将数组a中的元素赋值给单链表la
    la.Traverse();           //调用遍历函数
    la.Delete_x(a[5]);    //调用删除值为x的节点的前一个节点的函数
    la.Traverse();       //删除后再调用遍历函数
}
