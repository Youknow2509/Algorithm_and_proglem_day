// Code xử dụng danh sách liên kết vòng hiển thị dữ liệu của dãy số
// cho vào số nguyên n, nhập n số vào dãy số
// cho một số nguyên k, hiển thị số có số chỉ từ k - 1 đến n - 1 và 0 đến k - 1

#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *pre, *next;
};
struct c_dll{
    Node *head, *tail;
};

Node *newNode(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->pre = NULL;
    temp->next = NULL;
    return temp;
}
c_dll *newDll(int data){
    c_dll *dll = new c_dll();
    Node *node = newNode(data);
    dll->head = node;
    dll->tail = dll->head;
    return dll;
}
c_dll *push_back(c_dll *dll, int data){
    c_dll *insert_dll = newDll(data);
    c_dll *temp = dll;
    if (temp == NULL) return insert_dll;
    insert_dll->head->next = temp->head;
    insert_dll->head->pre = temp->tail;
    temp->tail->next = insert_dll->head;
    temp->tail = insert_dll->head;
    return dll; 
}

void print(c_dll *dll, int k){
    Node *temp = dll->head;
    while (k--) temp = temp->next;

    cout << temp->data << " ";
    Node *node_lct = temp;
    temp = temp->next;

    while (temp != node_lct) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main(){
    c_dll *l = NULL;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        l = push_back(l, x);
    }
    cin >> k;
    print(l, k);
    return 0;
}