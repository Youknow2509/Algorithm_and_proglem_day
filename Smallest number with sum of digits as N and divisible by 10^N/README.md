___**Contact**___
- ___Github___:<https://github.com/Youknow2509>
- ___Gmail___: <lytranvinh.work@gmail.com>
  
# *Smallest number with sum of digits as N and divisible by 10^N*

**Tìm số nhỏ nhất chia hết cho N và 10^N**

Ví dụ:

```
Input: N = 5
Outptut: 500000
Explanation: Sum of digits of 500000
is 5 and divisible by 10^5.
```

```
Input: N = 20
Output: 29900000000000000000000
Explanation: Sum of digits of 
29900000000000000000000 is 20 and
divisible by 10^20.
```

##Active code:
- Kết quả sẽ có dạng AB.
- Tạo một string trả về kết quả AB.
- Chia hết cho 10^N -> B chính là N số 0. 
- A là số nhỏ nhất chia hết cho N. So sánh A với 9:
  - Nếu N > 9 -> thêm một số 9 vào A và lấy N trừ 9 rồi tiếp tục so sánh.
  - Nếu N < 9 , nhập giá trị của N vào vị trí bên trái của A.