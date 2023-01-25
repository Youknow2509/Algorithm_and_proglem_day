# Đề bài

- Nhập vào số nguyên `n` (1 <= n <= 9).
- In ra chuỗi hoán vị các chữ số từ `1` đến `n`, các chuỗi tăng dần theo thứ tự từ điển, sau mỗi hoán vị cách nhau đúng một khoảng trống.
- **Yêu cầu xử dụng đệ qui.**
  
# Ví dụ

| Input | Output |
| ----- | ------ |
| 3  | 123 132 213 231 312 321 |

Với `n = 3` thì kết quả mong muốn là: `"123 132 213 231 312 321"`.

| Input | Output |
| ----- | ------ |
| 4  | 1234 1243 1324 1342 1423 1432 2134 2143 2314 2341 2413 2431 3124 3142 3214 3241 3412 3421 4123 4132 4213 4231 4312 4321 |

Với `n = 4` thì kết quả mong muốn là: `"1234 1243 1324 1342 1423 1432 2134 2143 2314 2341 2413 2431 3124 3142 3214 3241 3412 3421 4123 4132 4213 4231 4312 4321"`.

# Hướng làm

- Xử dụng kĩ thuật đánh dấu để đánh dấu các số đã xuất hiện trong chuỗi.
- Chúng ta sẽ lưu các giá trị của chuỗi vào mảng để dễ ghép các số.