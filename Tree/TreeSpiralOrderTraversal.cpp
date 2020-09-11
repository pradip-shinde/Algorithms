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
		pLeft = NULL;
		pRight = NULL;	
	}
	int iData;
	Node* pLeft;
	Node* pRight;
};


class Tree{
	public:
	Tree(){
		m_pRoot = NULL;
	}

	Node* getNode() { return m_pRoot;}
	void CreateTree()
	{		
		m_pRoot = new Node(1);
		m_pRoot->pLeft = new Node(2);
		m_pRoot->pRight = new Node(5);
		
		m_pRoot->pLeft->pLeft = new Node(3);
		m_pRoot->pLeft->pRight = new Node(4);
		
		m_pRoot->pRight->pLeft = new Node(8);
		m_pRoot->pRight->pRight = new Node(6);
		
		m_pRoot->pLeft->pLeft->pLeft = new Node(7);
		m_pRoot->pLeft->pLeft->pRight = new Node(10);
	}
	void SpiralOrderTraversal( Node* pRoot) 
	{
		if (pRoot == NULL)
		return;
		stack< Node*> stk1;
		stack< Node*> stk2;
		stk1.push(pRoot);
		while(!stk1.empty() || !stk2.empty())
		{
			while(!stk1.empty())
			{
				Node* pNode = stk1.top();
				stk1.pop();	
				cout<<" "<<pNode->iData<<", ";
								
				if(pNode->pLeft)
					stk2.push(pNode->pLeft);
				
				if(pNode->pRight)	
					stk2.push(pNode->pRight);
					
											
			}
			cout<<endl;
			
			while (!stk2.empty())
			{
				Node* pNode = stk2.top();
				stk2.pop();

				cout<<" "<<pNode->iData<<", ";

				if(pNode->pRight)
					stk1.push(pNode->pRight);

				if(pNode->pLeft)
					stk1.push(pNode->pLeft);
				
			}
			cout<<endl;
		}
	}
private:
	Node* m_pRoot;

};
int main()
{
	Tree obj;
		
	obj.CreateTree();
	Node* proot = obj.getNode();
	obj.SpiralOrderTraversal(proot);
	cout<<endl;
}
