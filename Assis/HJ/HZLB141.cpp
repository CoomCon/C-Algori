//141 环状链表
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef struct ListNode {
	int data;
	ListNode *next;
    ListNode(int x) : data(x), next(NULL) {}
	//ListNode(int x) : data(x), next(NULL) {} //初始化方法 可以不写
}ListNode, *pListNode;

//链表头尾指针
//一般定义头指针和尾指针方便处理
pListNode g_pHead = NULL; //等效于 ListNode  *g_pHead = NULL;
ListNode *g_pEnd = NULL;
// 头插法 头插法一般在大数相乘 大数幂的情景用的比较多
// 大数幂时，结果是反过来存储的，高位存储在低位节点上 以后再说
void adddataFront(int a)
{
    //1。 创建一个节点
    pListNode ptemp = (pListNode)malloc(sizeof(pListNode));
    ptemp->data = a;
    ptemp->next = NULL;
    if(g_pHead==NULL)
    {
        g_pHead = ptemp;
        g_pEnd = ptemp;
    }else //将头链接进去
    {
        ptemp->next = g_pHead;
    }
    g_pHead = ptemp;

}




//尾插法
void adddata(int a)
{
	//1.创建一个节点
	pListNode ptemp = (pListNode)malloc(sizeof(pListNode));
	ptemp->data = a;
	ptemp->next = NULL;
	//2.链接到图表中
	if (NULL == g_pHead /* || NULL == g_pEnd*/) //如果是空表
	{
		g_pHead = ptemp;
		g_pEnd = ptemp;
	}
	else //向链表最后一个节点添加
	{
		g_pEnd->next = ptemp;

	}
	g_pEnd = ptemp; //更新尾结点位置
}

// reverse
pListNode reverse(pListNode head)
{
	//1.创建一个节点
    pListNode pre = NULL, cur = head, nex = head->next;

    while(cur->next)
    {

        cur->next = pre;
        pre = cur;
        cur = nex;
        
        nex = cur->next;
    }
    cur->next = pre;
    return cur;
}

//K个一组翻转链表
pListNode reverseK(pListNode head, int k)
{
	//1.创建一个节点
    pListNode  cur = head;
      


    for (int i = 0; i < k-1 && cur->next != NULL; i++) //k-1 
    {
        cur = cur->next;
        //if(cur->next == NULL)return head;
    }
    

    pListNode nexthead = cur->next;


    cur->next = NULL; 

    pListNode ret = reverse(head); //返回当前区域的头结点

    if(nexthead ==NULL)
        head->next = NULL;//如果扫描到最后一个 不连接任何链表
    else
        head ->next = reverseK(nexthead, k); // 前一块区域的尾结点指向 下一块区域的头结点

    return ret; //返回当前区域的头结点
}


/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *Slow = head,*Fast = head;
        while(Slow->next !=NULL && Fast != NULL)
        {
            
            Slow = Slow ->next;
            Fast = Fast ->next ->next;
            if(Fast != NULL && Fast == Slow) 
                return true;
        }
        return false;
    }
};
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<int, pListNode> data;
        while(head!=NULL)
        {
            if( data.count(""))
            data.insert(head->data, head->next);
            head = head->next;
        }
    }
};
int main()
{

     adddataFront(1);
	 adddataFront(2);
     adddataFront(3);
     adddataFront(4);

     //g_pEnd->next = g_pHead;

     Solution so;
     bool res = so.hasCycle(g_pHead);
     return 0;
}