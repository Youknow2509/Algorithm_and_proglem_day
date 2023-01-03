
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};
// creat "a" Node.
Node *newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
// insert last Node.
Node *insertlsNode(Node *node, int data){
    if (node == NULL) node->next = newNode(data);
    node->next = insertlsNode(node->next, data);
    return node;
}
// insert first Node.
Node *insertfsNode(Node *node, int data){
    Node *temp = newNode(data);
    temp->next = node;
    return temp;
}


int main(){



    return 0;
}