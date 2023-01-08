#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node *pre;
};
struct Dll{
    Node *head; // lưu địa chỉ node đầu của dll.
    Node *tail;// lưu địa chỉ node cuối của dll.
};
// Tạo một node động
Node *newNode(int data){
    Node *node = new Node();
    node->data = data;
    node->next = NULL;
    node->pre = NULL;
    return node;
}
// Tạo ra double link động.
Dll *newDll(int data){
    Dll *double_link_list = new Dll();
    Node* node = newNode(data);
    double_link_list->head = node;
    double_link_list->tail = double_link_list->head;
    return double_link_list;
}
// in ra màn hình giá trị của các double link list từ đầu đến cuối.
void printf_l(Dll *dll){
    Node *temp = dll->head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// Tìm kiếm xem có phần tử nào có giá trị X không ?
bool find_data (Dll *dll, int data_find){
    Node *temp = dll->head;
    while (temp != NULL){
        if (temp->data == data_find){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
// Thêm phần tử vào đầu dll.
Dll *insert_f (Dll *dll, int data){
    Dll *newdll = newDll(data);
    if (dll == NULL) return newdll;
    newdll->head->next = dll->head;
    dll->head->pre = newdll->head;
    dll->head = newdll->head; // chú ý thay đổi vị trí con trỏ địa chỉ đâù và cuối của dll.
    return dll;
}
// Thêm phần tử vào cuối dll.
Dll *insert_l (Dll *dll, int data){
    Dll *newdll = newDll(data);
    if (dll == NULL) return newdll;
    newdll->head->pre = dll->tail;
    dll->tail->next = newdll->head;
    dll->tail = newdll->head;// chú ý thay đổi vị trí con trỏ địa chỉ đâù và cuối của dll.rrrvke
    return dll;
}
// Thêm phần tử sau một phần tử tại vị trí k.
Dll *insert_before_at (Dll *dll, int lct, int data){

    return dll;
}
// Thêm phần tử trước một phần tử tại vị trí k.
Dll *insert_after_at (Dll *dll, int lct, int data){

    return dll;
}
// Xoá phần tử vào đầu dll.
Dll *remote_data_head (Dll *dll){

    return dll;
}
// Xoá phần tử vào cuối dll.
Dll *remote_data_tail (Dll *dll){

    return dll;
}
// Xoá phần tử vào vị trí k.
Dll *remote_at (Dll* dll, int lct){

    return dll;
}

int main(){
    Dll *dll = NULL;
    dll = insert_f(dll, 1);
    printf_l(dll);
    dll = insert_f (dll, 2);
    printf_l(dll);
    dll = insert_f (dll, 3);
    printf_l(dll);
    dll = insert_l (dll, 3);
    printf_l(dll);
    return 0;
}