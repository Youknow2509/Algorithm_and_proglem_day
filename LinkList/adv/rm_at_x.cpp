// xoá phần tử tại node có chỉ số k;
#include<iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

node *createNode(int x){
    node *temp = new node;
    temp->next = NULL;
    temp->data = x; 
    return temp;
}

void printList(node *l){
	node *p = l;
	while (p != NULL){
		cout << p->data << " ";
		p = p->next;
	}
}

node *addElement(node*p, int x){
	node *temp = createNode(x);
	p->next = temp;
	return temp;
}

node *deleteHead(node *l){
	node *p = l;
	p = p->next;
	delete(l);
	return p;
}

node *deleteTail(node *l){
	node *p = l;
	while (p->next->next != NULL){
		p = p->next;
	}
	delete(p->next);
	p->next = NULL;
	return l;
}

node *deleteAt(node *l, int k){
	node *p = l;
	for (int i = 0; i < k-1; i++){
		p = p->next;
	}
	node *temp = p->next;
	p->next = p->next->next;
	delete(temp);
	return l;
}

int main(){
	int n, x, k;
	cin >> n;
	cin >> x;
	node *l = createNode(x);
	node *p = l;
	for (int i = 1; i < n; i++){
		cin >> x;
		p = addElement(p, x);
	}
	cin >> k;
    // chia 3 th vì cách hoạt động cua nó khác nhau.
	if (k == 0){// xoá Node đầu 
		l = deleteHead(l);
	} else if (k == n-1){ // xoá Node cuối
		l = deleteTail(l);
	} else{ // xoá một trong những nút còn lại 
		l = deleteAt(l, k);
	}
	printList(l);
	return 0;
}