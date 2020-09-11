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
	
	class DiagViewSupp{
		public:
		DiagViewSupp(Node* pNode, int iId)
		{
			m_id = iId;
			m_pNode =  pNode;
		}
		int m_id;
		Node* m_pNode;
	};
	void DiagonalView(Node* pNode)
	{
		if(pNode == nullptr)
			return;
		
		std::map<int, list<Node*>> mapDig;
		queue<DiagViewSupp> qu;
		qu.push(DiagViewSupp(pNode,0));
		while(!qu.empty())
		{
			DiagViewSupp obj = qu.front();
			qu.pop();
			if(obj.m_pNode->pLeft != nullptr)
				qu.push(DiagViewSupp(obj.m_pNode->pLeft, obj.m_id+1));
			
			if(obj.m_pNode->pRight != nullptr)
				qu.push(DiagViewSupp(obj.m_pNode->pRight, obj.m_id));
			
			list<Node*>& lst = mapDig[obj.m_id];
			lst.push_back(obj.m_pNode);
		}
		
		for(std::map<int, list<Node*>>::iterator itr = mapDig.begin(); itr != mapDig.end(); itr++)
		{
			list<Node*> lst = itr->second;
			cout<<"Diagonal Level :"<< itr->first <<" :   ";
			for(list<Node*>::iterator itrl = lst.begin(); itrl != lst.end(); itrl++)
			{
				cout<<" "<<(*itrl)->iData<<", ";
			}
			cout<<endl;
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
	obj.DiagonalView(proot);
	
	cout<<endl;
}
