// C++ implementation of a O(n) time method for spiral order traversal 
#include <iostream> 
#include <stack> 
using namespace std; 
  
// Binary Tree node 
 class node{ 
 public:
	int data; 
    node *left, *right; 
}; 
  
void printSpiral( node* root) 
{ 
    if (root == NULL) 
        return; // NULL check 
  
    // Create two stacks to store alternate levels 
    stack< node*> s1; // For levels to be printed from right to left 
    stack< node*> s2; // For levels to be printed from left to right 
  
    // Push first level to first stack 's1' 
    s1.push(root); 
  
    // Keep printing while any of the stacks has some nodes 
    while (!s1.empty() || !s2.empty()) { 
        // Print nodes of current level from s1 and push nodes of 
        // next level to s2 
        while (!s1.empty()) { 
             node* temp = s1.top(); 
            s1.pop(); 
            cout << temp->data << " "; 
  
            // Note that is right is pushed before left 
			if (temp->left) 
                s2.push(temp->left);
            if (temp->right) 
                s2.push(temp->right); 
           
        } 
		cout<<endl;
        // Print nodes of current level from s2 and push nodes of 
        // next level to s1 
        while (!s2.empty()) { 
             node* temp = s2.top(); 
            s2.pop(); 
            cout << temp->data << " "; 
  
            // Note that is left is pushed before right 
			if (temp->right) 
                s1.push(temp->right); 
            if (temp->left) 
                s1.push(temp->left); 
            
        } 
		cout<<endl;
    } 
} 
  
// A utility function to create a new node 
 node* newNode(int data) 
{ 
    
	node* pNode = new node();
    pNode->data = data; 
    pNode->left = NULL; 
    pNode->right = NULL; 
  
    return (pNode); 
} 
  
int main() 
{ 
     node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(5);
	
    root->left->left = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left = newNode(8); 
    root->right->right = newNode(6);

    root->left->left->left = newNode(7);
    root->left->left->right = newNode(10);
	
    cout << "Spiral Order traversal of binary tree is \n"; 
    printSpiral(root); 
  
    return 0; 
} 