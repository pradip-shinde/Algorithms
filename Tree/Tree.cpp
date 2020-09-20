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
	void InorderTravesal(const Node* proot) const
	{
		if(proot == nullptr)
		return;

		InorderTravesal(proot->pLeft);
		cout<<" "<< proot->iData<<", ";
		InorderTravesal(proot->pRight);
		
	}	
	
	void PreorderTraversal(const Node* proot) const
	{
		if(proot == nullptr)
			return;
		
		cout<<" "<< proot->iData<<", ";
		PreorderTraversal(proot->pLeft);
		PreorderTraversal(proot->pRight);
	}
	void PostOrderTraversal(const Node* proot) const
	{
		if(proot == nullptr)
		 return;
		PostOrderTraversal(proot->pLeft);
		PostOrderTraversal(proot->pRight);
		cout<<" "<< proot->iData<<", ";
	
	}
	int HeightofTree(const Node* pRoot) const
	{
		if(pRoot == nullptr)
			return 0 ;

		int lh = HeightofTree(pRoot->pLeft);
		int rh = HeightofTree(pRoot->pRight);
		return max(lh,rh)+1;		
	}
	void LevelorderTraversal(const Node* proot) const
	{
		cout<<endl;
		queue<const Node*> qu;
		qu.push(proot);
		cout<<"Level Order Traversal:"<<endl;
		while(!qu.empty())
		{
			const Node* pNode = qu.front();
			cout<<" "<< pNode->iData<<", ";
			qu.pop();
			if(pNode->pLeft != nullptr)
				qu.push(pNode->pLeft);
			if(pNode->pRight != nullptr)
				qu.push(pNode->pRight);
		}

	}

	void InorderIterative(const Node* pRoot) const
	{
		cout<<endl;
		cout<<"In_order Iterative:"<< endl;
		stack<const Node*> stk;
		const Node* pTemp = pRoot;
		while(pTemp != nullptr || !stk.empty())
		{
			if(pTemp != nullptr)
			{
				stk.push(pTemp);
				pTemp = pTemp->pLeft;
			}
			else
			{
				pTemp = stk.top();
				stk.pop();	
				cout<<" "<< pTemp->iData<<", ";	
				pTemp = pTemp->pRight;
			}
		}	
	}

	void PreorderIterative(const Node* pRoot) const
	{
		cout<<endl;
		cout<<"Pre_order Iterative:"<< endl;
		stack<const Node*> stk;
		const Node* pTemp = pRoot;
		while(pTemp != nullptr || !stk.empty())
		{
			if(pTemp != nullptr)
			{
				cout<<" "<< pTemp->iData<<", ";	
				stk.push(pTemp);
				pTemp = pTemp->pLeft;
			}
			else
			{
				pTemp = stk.top();
				stk.pop();	
				pTemp = pTemp->pRight;
			}
		}	
	}
	int CountNodes(const Node* pRoot)
	{
		if(pRoot == nullptr)
			return 0;
		int iL = CountNodes(pRoot->pLeft);
		int iR = CountNodes(pRoot->pRight);
		return (iL+iR +1);
	}
	int CountNumerofLeafNodes(const Node* pRoot)
	{
		if(pRoot == nullptr)
			return 0;
		if(pRoot->pLeft == nullptr && pRoot->pRight == nullptr)
			return 1;
		int iL = CountNumerofLeafNodes(pRoot->pLeft);
		int iR = CountNumerofLeafNodes(pRoot->pRight);
		return (iL+iR);
	}
	void PostorderIterative(const Node* pRoot) const
	{
		cout<<endl;
		cout<<"Post_order Iterative:"<< endl;
		stack<const Node*> stk;
		stack<const Node*> stk2;
		const Node* pTemp = pRoot;
		while(pTemp != nullptr || !stk.empty())
		{
			if(pTemp != nullptr)
			{
				stk.push(pTemp);
				stk2.push(pTemp);
				pTemp = pTemp->pRight;
			}
			else
			{
				pTemp = stk.top();
				stk.pop();	
				pTemp = pTemp->pLeft;
			}
		}
		while(!stk2.empty())
		{
			cout<<" "<< stk2.top()->iData <<", ";
			stk2.pop();
		}
	}	
	Node* getNode() const{ return m_pRoot;}
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
	const Node* proot = obj.getNode();
	cout<<"Inorder"<<endl;
	obj.InorderTravesal(proot);
	obj.InorderIterative(proot);
	
	cout<<endl<<"Pre order"<<endl;
	obj.PreorderTraversal(proot);
	obj.PreorderIterative(proot);

	cout<<endl<<"Post order"<<endl;
	obj.PostOrderTraversal(proot);
	obj.PostorderIterative(proot);

	obj.LevelorderTraversal(proot);

	int iHeight = obj.HeightofTree(proot);
	cout<<endl<<"Helight: "<< iHeight <<endl;
	
	int iNodes = obj.CountNodes(proot);
	cout<<endl<<"Number of Nodes: "<< iNodes <<endl;
	
	int iLeafNodes = obj.CountNumerofLeafNodes(proot);
	cout<<endl<<"Number of Leaf Nodes: "<< iLeafNodes <<endl;
	cout<<endl;
}
