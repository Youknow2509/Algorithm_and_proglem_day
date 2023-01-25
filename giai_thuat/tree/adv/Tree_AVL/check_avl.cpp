
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

int treelv(node *tree){
    node *temp = tree;
    if (temp == NULL) return -1;
    return 1 + max(treelv(temp->left), treelv(temp->right));  
    
}

bool checkAvl(node *t){
	if (t == NULL) 	return true;
	if (abs(treelv(t->left) - treelv(t->right)) > 1) return false;
	return checkAvl(t->left) && checkAvl(t->right);
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
    
    if (checkAvl(tree)) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}