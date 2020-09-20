#include <iostream>
using namespace std;

class Node {
	public:
	Node(int iData){
		m_iData = iData;
		pNext = nullptr;
	}
	int m_iData;
	Node* pNext;
};

class LinkList{
	public:
	LinkList()
	{
		m_pHead = nullptr;
	}
	void addNode(int iData)
	{
		if(m_pHead == nullptr)
		{
			m_pHead = new Node(iData);
			return;
		}
		Node* pTemp = m_pHead;
		while(pTemp->pNext != nullptr)
		{
			pTemp = pTemp->pNext;
		}
		pTemp->pNext = new Node(iData);
	}
	
	void PrintList()
	{
		Node* pTemp =m_pHead;
		while(pTemp != nullptr)
		{
			cout<<"-"<<pTemp->m_iData<<"->";
			pTemp= pTemp->pNext;
		}
	}
	int getSize(){
		
		Node* pTemp = m_pHead;
		int iCount =0;
		while(pTemp)
		{
			pTemp = pTemp->pNext;
			iCount++;
		}
		return iCount;
	}
	Node* getHead()
	{
		return m_pHead;	
	}
	Node* GetKthNode(int iIndex)
	{
		if(m_pHead == nullptr)
			return nullptr;
		Node* pKthNode = m_pHead;
		Node* pTemp= m_pHead;
		for(int i=0;i< iIndex;i++)
		{
			if(pTemp == nullptr)
				return nullptr;
			pTemp = pTemp->pNext;
		}
		while(pTemp != nullptr)
		{
			pTemp=pTemp->pNext;
			pKthNode = pKthNode->pNext;
		}
		
		return pKthNode;
	}
	~LinkList()
	{
		
	}
private:
	Node* m_pHead;
};


Node* FindIntesrsect(LinkList& obj1, LinkList& obj2)
{
	int iList1Size = obj1.getSize();
	int iList2Size = obj2.getSize();
	int idiff = abs((iList1Size-iList2Size));
	Node* p1Curr = obj1.getHead();
	Node* p2Curr = obj2.getHead();
	if(iList2Size > iList1Size)
	{
		for(int i=0; i< idiff; i++)
			p2Curr = p2Curr->pNext;
	}
	else
	{
		for(int i=0; i< idiff; i++)
			p1Curr = p1Curr->pNext;
	}
	Node *pCommon = nullptr;
	while(p1Curr && p2Curr)
	{
		if(p1Curr == p2Curr)
		{
			pCommon = p1Curr;
			break;
		}
		p1Curr = p1Curr->pNext;
		p2Curr = p2Curr->pNext;
	}
	return pCommon;
}
int main()
{
	LinkList obj;
	for(int i=1; i< 10;i++)
	{
		obj.addNode(i);
	}
	obj.PrintList();
	cout<< endl;
	//obj.ReverseList();
	Node* pNode = obj.GetKthNode(4);
	if(pNode != nullptr)
		cout<<"Kth Node  from Last:"<<pNode->m_iData;
	else
		cout<<"Kth index is larger than list size"<<endl;
	
	LinkList obj2;
	for(int i=11; i< 15;i++)
	{
		obj2.addNode(i);
	}
	Node* pNodeLast = obj2.GetKthNode(1);
	if(pNodeLast != nullptr)
		cout<<"Kth Node  from Last:"<<pNodeLast->m_iData;
	else
		cout<<"Kth index is larger than list size"<<endl;
	
	pNodeLast->pNext = pNode;
	cout<<endl;
	obj2.PrintList();
	cout<< endl;
	Node* pCommon = FindIntesrsect(obj, obj2);
	if(pCommon != nullptr)
		cout<<"Intersect Node:"<<pCommon->m_iData;
	else
		cout<<"No Intersection"<<endl;
	cout<<endl;
}
