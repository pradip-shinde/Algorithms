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
	void ReverseListIterative()
	{
		Node*pPrev = nullptr;
		Node*pCurr = m_pHead;
		Node*pNext = pCurr->pNext;
		while(pNext)
		{
			pCurr->pNext = pPrev;
			pPrev = pCurr;
			pCurr = pNext;
			pNext=pNext->pNext;
		}
		pCurr->pNext = pPrev;
		m_pHead = pCurr;
	}
	
	Node* RevRecurse(Node *pCurr, Node* pPrev)
	{
		Node* pHead =  nullptr;
		if(pCurr== nullptr)
			return pPrev;
		pHead= RevRecurse(pCurr->pNext, pCurr);
		pCurr->pNext = pPrev;
		return pHead;
		
	}
	void ReverseListRecurs()
	{
		m_pHead = RevRecurse(m_pHead, nullptr);
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
	for(int i=1; i< 150;i++)
	{
		obj.addNode(i);
	}
	obj.PrintList();
	cout<< endl;
	//obj.ReverseList();
	obj.ReverseListRecurs();
	cout<<endl;
	obj.PrintList();
	cout<<endl;
}
