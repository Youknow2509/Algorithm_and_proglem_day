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
    Node *new_Node = newNode(data);
    Node *temp = dll->head;
    while (lct > 0){
        temp = temp->next;
        lct--;
    }
    if ( temp == dll->head){
        dll = insert_f(dll, data);
        return dll;
    }
    new_Node->next = temp;
    new_Node->pre = temp->pre;
    temp->pre->next = new_Node;
    return dll;
}
// Thêm phần tử trước một phần tử tại vị trí k.
Dll *insert_after_at (Dll *dll, int lct, int data){
    Node *new_Node = newNode(data);
    Node *temp = dll->head;
    while (lct > 0){
        temp = temp->next;
        lct--;
    }
    if ( temp == dll->tail){
        dll = insert_l(dll, data);
        return dll;
    }
    new_Node->next = temp->next;
    new_Node->pre = temp;
    temp->next = new_Node;
    return dll;
}
// Xoá phần tử vào đầu dll.
Dll *remote_data_head (Dll *dll){
    Node *temp = dll->head->next;
    delete(dll->head);
    dll->head = temp;
    dll->head->pre = nullptr;
    return dll;
}
// Xoá phần tử vào cuối dll.
Dll *remote_data_tail (Dll *dll){
    Node *temp = dll->tail->pre;
    delete(dll->tail);
    dll->tail = temp;
    dll->tail->next = nullptr;
    return dll;
}
// Xoá phần tử vào vị trí k.
Dll *remote_at (Dll* dll, int lct){
    Node *temp = dll->head;
    Node *temp_del = NULL;
    // trỏ tới vị trí cần chỉnh sửa
    while (lct > 1){
        temp = temp->next;
        lct--;
    }
    temp_del = temp->next;
    if (lct == 0) {
        dll = remote_data_head(dll);// không để if (temp_del == dll->head) do lỗi tự tìm hiều ....
        return dll;
    }
    if (temp_del == dll->tail) {
        dll = remote_data_tail(dll);
        return dll;
    }
    temp->next = temp->next->next;
    temp->next->pre = temp;
    delete(temp_del);
    return dll;
}
// Thay thế giá trị tại số chỉ k thành data
Dll *replace_element_data_at (Dll *dll, int lct, int data){
    Node *temp = dll->head;
    // trỏ tới vị trí cần chỉnh sửa
    while (lct > 1){
        temp = temp->next;
        lct--;
    }
    temp->data = data;
    return dll;
}

int main(){
    Dll *dll = NULL;

    dll = insert_l(dll, 1);
    printf_l(dll);
    dll = insert_l (dll, 2);
    printf_l(dll);
    dll = insert_l (dll, 3);
    printf_l(dll);
    dll = insert_l (dll, 4);
    printf_l(dll);
    dll = insert_l (dll, 5);
    printf_l(dll);
    dll = replace_element_data_at(dll, 5, 0);
    printf_l(dll);
    cout << "Data Head: " <<dll->head->data << ", Data tail: " << dll->tail->data << endl;
    return 0;
}