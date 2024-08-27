#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }

};

Node* builtTree(Node* &root){
    cout<<"enter data: "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1) return nullptr;
    cout<<"enter left data for :"<<data<<endl;
    root->left=builtTree(root->left);
    cout<<"enter right data for :"<<data<<endl;
    root->right=builtTree(root->right);
    return root;

}

void levelorderTraversal(Node* &root){
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==nullptr) {
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout<<temp->data << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
            
    }
}


void inorder(Node* &root){
  if(root==nullptr) return ;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void preorder(Node* &root){
    if(root==nullptr) return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* &root){
    if(root==nullptr) return ;
    
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    
    Node* root=nullptr;
    root=builtTree(root);
    
    levelorderTraversal(root);
    cout<<"inorder"<<endl;
    inorder(root);
    cout<<endl<<"preorder"<<endl;
    preorder(root);
    cout<<endl<<"postorder"<<endl;
    postorder(root);

    return 0;
}