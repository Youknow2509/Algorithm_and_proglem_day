
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node *left,
        *right;
};

Node *new_Node(int val){
    Node *temp = new Node();
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

class storing_paths{
    bool find_path(Node *root, vector<int>& path, int key){
        if (!root){
            return false;
        }
        path.push_back(root->val);
        if (root->val == key){
            return true;
        }

        if (find_path(root->left, path, key) || find_path(root->right, path, key)){
            return true;
        }
        path.pop_back();
        return false;
    }

    int LowestCommonAncestor(Node *root, int u, int v){
        vector<int> path1,
            path2;
        
        if (!find_path(root, path1, u) || !find_path(root, path2, v)){
            return -1;
        }

        int a = path1.size(),
            b = path2.size();

        int temp = (a < b) ? a : b,
            index = 0;

        for (; index < temp; index++){
            if (path1[index] != path2[index]){
                break;
            }
        }
        return path1[index - 1];
    }
};

class single_traversal{
/*     
Time Complexity: O(N) as the method does a simple tree traversal in a bottom-up fashion. 
Auxiliary Space: O(H), where H is the height of the tree.
 */
    Node *find_LCA(Node *root, int u, int v){
        if (!root){
            return NULL;
        }

        if (root->val == u || root->val == v){
            return root;
        }

        Node *left_node = find_LCA(root->left, u, v),
            *right_node = find_LCA(root->right, u, v);

        if (left_node && right_node){
            return root;
        }
        return (left_node != NULL) ? left_node : right_node;
    }

    int LowestCommonAncestor(Node *root, int u, int v){
        return find_LCA(root, u, v)->val;
    }
};

class hash_table{
    unordered_map<Node*, Node*> buildParenMap(Node *root){
        unordered_map<Node*, Node*> temp;
        temp[root] = NULL;

        vector<Node*> q;
        q.push_back(root);

        while(!q.empty()){
            Node* x = q.front();
            q.erase(q.begin());
            if (x->left){
                q.push_back(x->left);
                temp[x->left] = x;
            }
            if (x->right){
                q.push_back(x->right);
                temp[x->right] = x;
            }
        }
        return temp;
    }

    int LowestCommonAncestor(Node *root, int u, int v){
        unordered_map<Node*, Node*> parentMap = buildParenMap(root);

        Node *q, // lct root->val = u
            *p; // lct root->val = v
        
        vector<Node*> queue = {root};

        // find q and p
        while(!queue.empty()){
            Node *node = queue.front();
            queue.erase(queue.begin());
            if (node->val == u){
                q = node;
            }
            if (node->val == v){
                p = node;
            }
            if (node->left){
                queue.push_back(node->left);
            }
            if (node->right){
                queue.push_back(node->right);
            }
        }
        //
        set<Node*> s;
        //creat s
        while(p){
            s.insert(p);
            p = parentMap[p];
        }
        //
        while(q){
            if (s.find(q) != s.end()){
                return q->val;
            }
            q = parentMap[q];
        }
        return -1;
    }
};

int main(){
    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
    freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif

    int n;
    cin >> n;

    Node *root = new_Node(1);

    // push val root 

    //

    // solve with storing paths 


    // solve with single traversal

    return 0;
}