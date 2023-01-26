#include<bits/stdc++.h>

using namespace std;

struct Node{
	int key;
	Node *left;
	Node *right;
	int height;
};
// Hàm để lấy chiều cao của cây
int height(Node *N){
	if (N == NULL)
		return 0;
	return N->height;
}
// Hàm trả về số lớn hơn trong hai số nguyên
int max(int a, int b){
	return (a > b)? a : b;
}
/* Hàm trợ giúp phân bổ một nút mới với khóa đã cho và NULL con trỏ trái và phải. */
Node* newNode(int key){
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // nút mới ban đầu được thêm vào lá. 
	return (node);
}
// Một chức năng tiện ích để xoay phải cây con bắt nguồn từ y
Node *rightRotate(Node *y){
	Node *x = y->left;
	Node *T2 = x->right;
	// Thực hiện xoay
	x->right = y;
	y->left = T2;
	// Cập nhật chiều cao
	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;
	// Trả về gốc mới
	return x;
}
// Một chức năng tiện ích để xoay trái cây con bắt nguồn từ x
Node *leftRotate(Node *x){
	Node *y = x->right;
	Node *T2 = y->left;
	// Thực hiện xoay
	y->left = x;
	x->right = T2;
	// Cập nhật chiều cao
	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;
	// Trả về gốc mới
	return y;
}
// Nhận hệ số cân bằng của nút N
int getBalance(Node *N){
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}
// Hàm đệ quy để chèn một khóa vào cây con có gốc bằng nút và trả về gốc mới của cây con.
Node* insert(Node* node, int key){
	/* 1. Thực hiện chèn BST bình thường */
	if (node == NULL)
		return(newNode(key));
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // Khóa bằng không được phép trong BST
		return node;
	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
						height(node->right));
	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);
	// If this node becomes unbalanced, then there are 4 cases
	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);
	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);
	// Left Right Case
	if (balance > 1 && key > node->left->key){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	// Right Left Case
	if (balance < -1 && key < node->right->key){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	/* return the (unchanged) node pointer */
	return node;
}
// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void preOrder(Node *root){
	if(root != NULL){
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}
// Driver Code
int main(){
	Node *root = NULL;
	/* Constructing tree given in the above figure */
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);
	/* The constructed AVL Tree would be
			30
			/ \
		   20 40
		  / \   \
		10 25   50
	*/
	cout << "Preorder traversal of the "
			"constructed AVL tree is \n";
	preOrder(root);
	return 0;
}


