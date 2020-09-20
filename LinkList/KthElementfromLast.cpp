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
	void PrintList()
	{
		Node* pTemp =m_pHead;
		while(pTemp != nullptr)
		{
			cout<<"-"<<pTemp->m_iData<<"->";
			pTemp= pTemp->pNext;
		}
	}
	
	~LinkList()
	{
		
	}
private:
	Node* m_pHead;
};
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
	
	cout<<endl;
}
