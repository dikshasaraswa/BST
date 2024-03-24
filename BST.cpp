#include<iostream>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;

    Node(int value):key(value),left(nullptr),right(nullptr){}

};
Node* insert(Node* root,int key){
       if(root == nullptr){
        return new Node(key);
       }
       if(key < root-> key){
        root->left=insert(root->left,key);
       }
       else if(key > root->key){
        root->right=insert(root->right,key);
       }
       return root;
}

bool search(Node* root,int key){
    if(root==nullptr){
        return false;
    }
    if(key == root->key){
        return true;
    }
    else if (key < root->key){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}
void inorder(Node* root){
    if(root!= nullptr){
        inorder(root->left);
        cout<<root->key<<endl;
        inorder(root->right);
    }
}
Node* findmin(Node* root){
    if(root->left !=nullptr){
        root=root->left ;
    }
    return root;
}
Node* deletenode(Node* root,int key){
     if(root==nullptr){
        return root;
     }
     if(key < root->key){
        root->left=deletenode(root->left,key);
     }else if (key > root->key){
        root->right = deletenode(root->right,key);
     }
     //for one child
     else{
        if(root->left==nullptr){
        Node* temp = root->right;
        delete root;
        return temp;
     }else if (root->right == nullptr){
        Node* temp = root->left;
        delete root;
        return temp;
     }
     //two child
     Node* temp = findmin(root->right);
     root->key = temp->key;
     root->right = deletenode(root->right,temp->key);
     }
     return root;
}
int main(){
    Node* root = nullptr;
    cout<<"Binary Search Tree operations"<<endl;
    cout<<"1. Insert"<<endl;
    cout<<"2. Search"<<endl;
    cout<<"3. Inorder traversal"<<endl;
    cout<<"4. Delete"<<endl;
    int choice,key;
    while(true){
        cout<<"enter choice"<<endl;
        cin>> choice;
        switch(choice){
            case 1 : cout<<"Enter number to be Inserted"<<endl;
            cin>> key;
            root=insert(root,key);
            break;
            case 2 : cout<<"Enter number to be Searched"<<endl;
            cin>> key;
            if(search(root,key)){
                cout<<"Find"<<endl;
            }else{
                cout<<"Not find"<<endl;
            }
            break;
            case 3 : cout<<"Inordertraversal"<<endl;
            inorder(root);
            break;
            case 4 : cout<<" Enter number to be Deleted"<<endl;
            cin>> key;
            root=deletenode(root,key);
            cout<<"Deleted"<<endl;
            break;
            case 0: cout<<"Exit program"<<endl;
            return 0;
            break;
            default : cout<<"Invalid choice"<<endl;
            
        }
    }
    return 0;
}