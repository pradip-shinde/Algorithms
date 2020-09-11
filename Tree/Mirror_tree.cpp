#include <iostream>
#include <queue>
#include <stack>
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
	void Mirror(Node* pNode)
	{
		if(pNode == nullptr)
			return;
		Mirror(pNode->pLeft);
		Mirror(pNode->pRight);
		
		Node* pTemp = pNode->pLeft;
		pNode->pLeft = pNode->pRight;
		pNode->pRight = pTemp;
	}
	void InorderTravesal(const Node* proot) const
	{
		if(proot == nullptr)
		return;

		InorderTravesal(proot->pLeft);
		cout<<" "<< proot->iData<<", ";
		InorderTravesal(proot->pRight);
		
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
	}
private:
	Node* m_pRoot;

};
int main()
{
	Tree obj;
		
	obj.CreateTree();
	Node* proot = obj.getNode();
	cout<<endl<<"Inorder"<<endl;
	obj.InorderTravesal(proot);
	obj.Mirror(proot);
	cout<<endl<<"Inorder - After Mirror"<<endl;
	obj.InorderTravesal(proot);
		cout<<endl;
}
