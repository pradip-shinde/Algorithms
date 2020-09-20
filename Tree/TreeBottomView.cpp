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
	
	class TopViewSupp{
		public:
		TopViewSupp(Node* pNode, int iId)
		{
			m_id = iId;
			m_pNode =  pNode;
		}
		int m_id;
		Node* m_pNode;
	};
	void BottomView(Node* pNode)
	{
		if(pNode == nullptr)
			return;
		
		std::map<int, Node*> mapTopView;
		queue<TopViewSupp> qu;
		qu.push(TopViewSupp(pNode,0));
		while(!qu.empty())
		{
			TopViewSupp obj = qu.front();
			qu.pop();
			if(obj.m_pNode->pLeft != nullptr)
				qu.push(TopViewSupp(obj.m_pNode->pLeft, obj.m_id-1));
			
			if(obj.m_pNode->pRight != nullptr)
				qu.push(TopViewSupp(obj.m_pNode->pRight, obj.m_id+1));
			
			mapTopView[obj.m_id] = obj.m_pNode;
		}
		
		for(std::map<int, Node*>::iterator itr = mapTopView.begin(); itr != mapTopView.end(); itr++)
		{
			cout<<"Bottom View Level :"<< itr->first <<" :   ";
			cout<<" "<<itr->second->iData<<", ";
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
		m_pRoot->pRight->pLeft->pRight->pRight = new Node(13);
		m_pRoot->pRight->pLeft->pRight->pRight->pRight = new Node(14);
		m_pRoot->pRight->pLeft->pRight->pRight->pRight->pRight = new Node(15);
		m_pRoot->pRight->pLeft->pRight->pRight->pRight->pRight->pRight = new Node(16);
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
	obj.BottomView(proot);
	
	cout<<endl;
}
