#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
class node
{
public:
       int data;
       node* left;
       node* right;

       node(int d)
       {
              data=d;
              left=NULL;
              right=NULL;
       }
};

node* buildTree()
{
          int d;cin>>d;
          if(d==-1)
                return NULL;
          node* root=new node(d);
          root->left=buildTree();
          root->right=buildTree();
          return root;
}


//Level Order Traversal with O(n) complexity
//BFS Traversal
void printBFSAllLevels(node* root)
{
    queue <node*> q;
    while(!q.empty())
    { 
        node*f=q.front();
        cout<<f->data<<" ";
        q.pop();
        if(f->left)
            q.push(f->left);
        if(f->right)
             q.push(f->right);
    }
    return;
}
//

//Level Order Traversal with Each level on New Line O(n) Complexity


int main()
{
    node*root=buildTree();
    printBFSAllLevels(root,level);
}