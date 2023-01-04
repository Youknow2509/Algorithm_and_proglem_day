// code thêm phần tử tại vị trí bất kì k.
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};
    
Node *newNode(int data){
    Node *temp = new Node();
    temp->next = NULL;
    temp->data = data;
    return temp;
}

Node *push_back(Node *ll, int data){
    Node *temp = ll;
    if (temp == NULL){
        temp = newNode( data);
        return temp;
    }
    temp->next = push_back(temp->next, data);
    return temp;
}

void printLl(Node * ll){
    Node *temp = ll;
    while ( temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *push(Node *ll, int data){
    Node *temp = newNode(data);
    temp->next = ll;
    return temp;
}

Node *insert_at_lc(Node *ll, int k, int data){
    Node *temp = ll;
    Node *insert = new Node();
    insert->data = data;
    for (int i = 0; i < k - 1; i++){
        temp = temp->next;
    }
    insert->next = temp->next;
    temp->next = insert;
    return ll;
    
}

int main(){
    Node *ll = NULL;
    int n, temp, x, k;
    cin >> n >> temp;
    ll = push_back(ll, temp);
    for (int i = 1; i < n; i++){
        cin >> temp;
        ll = push_back(ll, temp);
    }
    cin >> k >> x;
    if ( k == 0){
        ll = push(ll, x);
    }else{
        ll = insert_at_lc(ll, k, x);
    }
    printLl(ll);
    return 0;
}
