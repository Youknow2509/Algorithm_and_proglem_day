
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> computeLPSArray(string concat){
        int M = concat.length();
        vector<int> lps(M);
        int len = 0;
        lps[0] = 0; // lps[0] is always 0 the loop calculates lps[i] for i = 1 to M-1
        // lps [0] luôn là 0 vòng lặp tính toán lps [i] cho i = 1 đến M-1
        int i = 1;
// debug 
        for ( auto i : concat) cout << i;
        cout << endl;
        
        while (i < M){
            if (concat[i] == concat[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else // (concat[i] != str[len])
            {       
            // This is tricky. Consider the example. AAACAAAA and i = 7. The idea is similar to search step.
            // Thật là khó. Hãy xem xét ví dụ. AAACAAAA và i = 7. Ý tưởng tương tự như bước tìm kiếm.
                if (len != 0){
                len = lps[len-1];
                // Also, note that we do not increment i here
                // Ngoài ra, lưu ý rằng chúng tôi không tăng i ở đây
                }
                else // if (len == 0)
                {
                    lps[i] = 0;
                    i++;
                }
            }
//debug
            cout << lps.back() <<" ";
        }
        return lps;
    }
    int minChar(string str){
        string revStr = str;
        reverse(revStr.begin(), revStr.end());
        // Get concatenation of string, special character and reverse string
        // Nhận nối chuỗi, ký tự đặc biệt và chuỗi ngược
        string concat = str + "$" + revStr;
        //  Get LPS array of this concatenated string
        // Nhận mảng LPS của chuỗi nối này
        vector<int> lps = computeLPSArray(concat);
        // By subtracting last entry of lps vector from string length, we will get our result
        // Bằng cách trừ mục nhập cuối cùng của vectơ lps khỏi độ dài chuỗi, chúng ta sẽ nhận được kết quả
        return (str.length() - lps.back());
    }
};



int main()
{
	
	string str ;
    cin >> str;
	Solution ob;
	int ans = ob.minChar(str);
    cout << endl;
	cout << ans ;
	return 0;
}
