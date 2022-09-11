
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findOccurrence(vector<vector<char> > &mat, string target){
        // lay lai kich thuoc cua mang 2D
        int a = mat.size();    //So phan tu lon mang
        int b = mat[0].size(); // Trong moi phan tu lon co b phan tu con
        int c = target.size(); //kich thuoc target
        int result = 0; // Bien luu dap an
        // Tim phan tu dau tien cua "tagret"
        for (int i = 0; i < a; i++){
            for (int j = 0; j < b; j ++){
                if (mat[i][j] == target[0]){
                result += solve(i,j,mat,target,0,a,b,c);
    //khi ta tim dc ki tu dau tieu thi se tiep cac ki tu qua ham solve de xem tu ki tu dau  thi di duoc bao nhieu truong hop
    // Truyen vao solve mang 2D, vi tri dang chon, kich thuoc mang 2D, target 
                }
            }
        }
        return result;
    }

    int solve (int i, int j , vector<vector <char> >mat, string target, int index,int a, int b, int c){
        int count = 0;

        if ( i < a && j <b && i>=0 && j>=0 && mat[i][j] == target[index]){
            index ++;
            char temp=m[i][j];
            m[i][j]='*';
            if (index == c){
                count = 1;
            }
            else{
                 //goi 4 huong chi 
                count += solve(i+1,j,mat,target,index,a,b,c); // down
                count += solve(i-1,j,mat,target,index,a,b,c);// top
                count += solve(i,j-1,mat,target,index,a,b,c);// left
                count += solve(i,j+1,mat,target,index,a,b,c);//right
            }
            m[i][j] = temp; // chong truong hop vd "aba" no se quay dau lai a cu .
        }
        return count;
    }
};

int main() {
    int t;
    // Nhap so lan chuong trinh chay
    cin >> t;
    while (t--) {
        int R, C;

        cin >> R >> C;
        vector<vector<char> > mat(R);
        // => tuong duong mang hai chieu mat[R][C].
        // Nhap du lieu vao mang.
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        // Nhap tu can tim
        cin >> target;

        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;

    }
    return 0;
} 
 

// manin debug
/* int main() {
    
        int R, C;

        R = C = 3;
        vector<vector<char> > mat(R);
        mat = {{'c','a','t'},{'a','t','c'},{'c','t','a'}};
        string target = "cat";
        

        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;

        return 0;
    
}   */