
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};
// Tạo "một" Node.
Node *newNode(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}
// In linklist.
void printNode (Node *node){
    Node *temp = node; // sử dụng temp để không làm thay đổi con trỏ trỏ vào node.
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    
}
// Thêm Node vào "cuối" linklist.
Node *insertlsNode(Node *node, int data){
    Node *temp = node; // sử dụng temp để không làm thay đổi con trỏ trỏ vào node.
    if (temp == NULL) {
        temp = newNode(data);
        return temp;
    }
    temp->next = insertlsNode(temp->next, data);
    return node;
}
// Thêm Node vào "đầu" linklist.
Node *insertfsNode(Node *node, int data){
    Node *temp = newNode(data);
    temp->next = node;
    return temp;
}
// Thêm Node vào vị trí k bất kì.
Node *insert_at_k(Node *node, int data,int k){
    Node *temp_1 = node; // sử dụng temp để không làm thay đổi con trỏ trỏ vào node.
    // di chuyển con trỏ tới vị trí cần thêm vào.
    Node *temp_2 = new Node(); // tạo Node chuẩn bị chèn vào vị trí k.
    temp_2->data = data;
    for (int i = 0; i < k - 1; i++){
        temp_1 = temp_1->next; 
    }
    temp_2->next = temp_1->next;
    temp_1->next = temp_2;
    return node;
}   

int main(){

    Node *ll = NULL;
    ll = insertlsNode(ll, 1);
    ll = insertlsNode(ll, 2);
    ll = insertlsNode(ll, 3);
    printNode(ll); // Output: 1 2 3
    cout << endl;
    ll = insertfsNode(ll,4);
    ll = insertfsNode(ll, 5);
    printNode(ll); // Output: 5 4 1 2 3
    cout << endl;
    ll = insert_at_k(ll, 0, 2);
    //ll = addAt(ll, 2, 0);
    printNode(ll); // Output: 5 4 0 1 2 3
    cout << endl;
    return 0;
}