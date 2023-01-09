// Code xử dụng danh sách liên kết vòng hiển thị dữ liệu của dãy số
// cho vào số nguyên n, nhập n số vào dãy số
// cho một số nguyên k, hiển thị số có số chỉ từ k - 1 đến n - 1 và 0 đến k - 1
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;
};

struct ll{
    Node *head;
    Node *tail;
};

Node *newNode(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}
ll *newll(int data){
    ll *temp_ll = new ll();
    Node *temp_n = newNode(data);
    temp_ll->head = temp_n;
    temp_ll->tail = temp_ll->head;
    return temp_ll;
}
ll *push_back(ll* l, int data){
    ll  *temp = l;
    ll *insert_ll = newll(data);
    if (temp == NULL) return newll(data);
    insert_ll->tail->next = temp->head;
    temp->tail->next = insert_ll->head;
    temp->tail = insert_ll->head;
    return l;
}
void print(ll *l, int k){
    Node *temp = l->head;
    while (k--) temp = temp->next;
    cout << temp->data << " ";
    Node *lct = temp;
    temp = temp->next;
    while(temp != lct) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){
    ll *l = NULL;
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