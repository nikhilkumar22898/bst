#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node * left;
    Node * right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }  
};

class BST{
public:
    Node * root;
    BST(){
        root = NULL;
    }
    void insertHelper(int value){
        insert(root, value);
    }
    void insert(Node *curr, int value){ 
        if (root == NULL) root = new Node(value); 
        else if (value < curr->data)  { 
            if (curr->left == NULL) curr->left = new Node(value); 
            else insert(curr->left, value);
        }
        else { 
            if (curr->right == NULL) curr->right = new Node(value);
            else insert(curr->right, value);
        }
    }
    void displayHelper(){
        display(root);
    }
    void display(Node * curr){
        if( curr ==  NULL) return; 
        display(curr->left);
        cout << curr->data << ", ";
        display(curr->right);
    }
    Node * searchHelper(int value){
        return search(root, value);
    }
    Node * search(Node * curr, int value){
        if(curr == NULL || curr->data == value ) return curr;
        else if(value < curr->data) return search(curr->left, value);
        else  return search(curr->right, value);
    }

};

int main(){
    BST bst1;
    bst1.insertHelper(4);
    bst1.insertHelper(2);
    bst1.insertHelper(1);
    bst1.insertHelper(3);
    bst1.insertHelper(5);
    bst1.displayHelper();
    if(bst1.searchHelper(3) != NULL){
        cout << endl << bst1.searchHelper(3)->data << endl;
    }
}
