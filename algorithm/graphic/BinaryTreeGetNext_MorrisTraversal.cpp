// C++ program for Morris Preorder traversal 
#include <bits/stdc++.h>
using namespace std; 
  
class node 
{ 
    public:
    int data; 
    node *left, *right; 
}; 
  
node* newNode(int data) 
{ 
    node* temp = new node();
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
void morrisTraversalPreorder(node* root) 
{ 
    while (root) { 
        if (root->left == NULL) { 
            cout<<root->data<<" "; 
            root = root->right; 
        } 
        else { 
            // Find inorder predecessor 
            node* current = root->left; 
            while (current->right && current->right != root) 
                current = current->right; 
  
            // If the right child of inorder predecessor already points to 
            // this node 
            if (current->right == root) { 
                current->right = NULL; 
                root = root->right; 
            } 
  
            // If right child doesn't point to this node, then print this 
            // node and make right child point to this node 
            else { 
                cout<<root->data<<" "; 
                current->right = root; 
                root = root->left; 
            } 
        } 
    } 
} 
  
void morrisTraversalInorder(node* root) 
{ 
    while (root) { 
        if (root->left == NULL) { 
            cout<<root->data<<" "; 
            root = root->right; 
        } 
        else { 
            // Find inorder predecessor 
            node* current = root->left; 
            while (current->right && current->right != root) 
                current = current->right; 
  
            // If the right child of inorder predecessor already points to 
            // this node 
            if (current->right == root) { 
                cout<<root->data<<" "; 
                current->right = NULL; 
                root = root->right; 
            } else { 
                current->right = root; 
                root = root->left; 
            } 
        } 
    } 
} 
// Function for sStandard preorder traversal 
void preorder(node* root) { 
    if (root) { 
        cout<<root->data<<" "; 
        preorder(root->left); 
        preorder(root->right); 
    } 
} 
  
void postorder(node* root) { 
    if (root) { 
        postorder(root->left); 
        postorder(root->right); 
        cout<<root->data<<" "; 
    } 
} 
  
void inorder(node* root) { 
    if (root) { 
        inorder(root->left); 
        cout<<root->data<<" "; 
        inorder(root->right);
    } 
} 
/* Driver program to test above functions*/
int main() 
{ 
    node* root = NULL; 
  
    root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
  
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
  
    root->left->left->left = newNode(8); 
    root->left->left->right = newNode(9); 
  
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(11); 
  
    printf("pre : ");
    preorder(root); 
    cout<<endl; 
    printf("in  : ");
    inorder(root); 
    cout<<endl; 
    printf("post: ");
    postorder(root); 
    cout<<endl; 
    /*
    morrisTraversalPreorder(root); 
  
    cout<<endl; 
    
    morrisTraversalPostorder(root); 
  
    cout<<endl; 
    */
    printf("morr: ");
    morrisTraversalInorder(root); 
  
    
  
    return 0; 
} 
  