#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <algorithm>
using namespace std;
class Node{
public:
	Node(int iDta)
	{
		iData = iDta;
		pLeft = nullptr;
		pRight = nullptr;	
	}
	int iData;
	Node* pLeft;
	Node* pRight;
};


class Tree{
	public:
	Tree(){
		m_pRoot = nullptr;
	}
	
	void LeftView(Node* pNode)
	{
		if(pNode == nullptr)
			return;
		int iCount =0;	
		queue<Node*> qu;
		qu.push(pNode);
		iCount = qu.size();	
		while(!qu.empty())
		{
			iCount = qu.size();
			int iqueCount  = qu.size();	
			while(iCount >0)
			{	
				Node* pNode = qu.front();
				qu.pop();
				if(iCount ==iqueCount)
				{
					cout<<"Left View "<< pNode->iData<<endl;
				}
				if(pNode->pLeft != nullptr)
				{
					qu.push(pNode->pLeft);
				}
				if(pNode->pRight != nullptr)
				{	
					qu.push(pNode->pRight);
				}
				iCount--;
			}
		}
	}
	void RightView(Node* pNode)
	{
		if(pNode == nullptr)
			return;
		int iCount =0;	
		queue<Node*> qu;
		qu.push(pNode);
		iCount = qu.size();	
		while(!qu.empty())
		{
			iCount = qu.size();
			int iqueCount  = qu.size();	
			while(iCount >0)
			{	
				Node* pNode = qu.front();
				qu.pop();
				if(iCount ==1)
				{
					cout<<"Right View "<< pNode->iData<<endl;
				}
				if(pNode->pLeft != nullptr)
				{
					qu.push(pNode->pLeft);
				}
				if(pNode->pRight != nullptr)
				{	
					qu.push(pNode->pRight);
				}
				iCount--;
			}
		}
	}
	
	Node* getNode() { return m_pRoot;}
	void CreateTree()
	{		
		m_pRoot = new Node(1);
		m_pRoot->pLeft = new Node(2);
		m_pRoot->pRight = new Node(5);

		m_pRoot->pRight->pRight = new Node(6);
		m_pRoot->pRight->pLeft = new Node(8);

		m_pRoot->pLeft->pLeft = new Node(3);
		m_pRoot->pLeft->pRight = new Node(4);

		m_pRoot->pLeft->pLeft->pLeft = new Node(7);
		m_pRoot->pLeft->pLeft->pRight = new Node(10);
		
		m_pRoot->pRight->pRight->pRight = new Node(11);
		m_pRoot->pRight->pLeft->pRight = new Node(12);
		m_pRoot->pRight->pLeft->pLeft = new Node(13);
	}
private:
	Node* m_pRoot;

};
int main()
{
	Tree obj;
		
	obj.CreateTree();
	Node* proot = obj.getNode();
	obj.LeftView(proot);
	obj.RightView(proot);
	
	cout<<endl;
}
