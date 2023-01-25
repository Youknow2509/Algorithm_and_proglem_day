
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node *newnode(int data){
    node *temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node *push_back(node* tree, int data){
    node *temp = tree;
    if ( temp == NULL) return newnode(data);
    if ( data < temp->data) 
        temp->left = push_back(temp->left, data);
    else {
        temp->right = push_back(temp->right, data);
    }
    return tree;
}

void in_order_traversal_tree(node *tree){
    node *temp = tree;
    if (temp != NULL){
        in_order_traversal_tree(temp->left);
        cout << temp->data << " ";
        in_order_traversal_tree(temp->right);
    }
}

int main(){
    node *tree = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree = push_back(tree, x);
    }
    in_order_traversal_tree(tree);
    return 0;
}