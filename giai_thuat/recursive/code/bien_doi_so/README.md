# Đề bài: 

- Hải vừa nghĩ ra một phép biến đổi số, cụ thể như sau:

- Với số tự nhiên n nếu:

    - n là số chẵn thì biến đổi `n` thành `n/2`.
    - n là số lẽ thì biến đổi `n` thành `3*n+1`.
- Hiện tại Hải đang có hai số tự nhiên `n` và `k`, Hải muốn biết số lượng số mà khi số đó biến đổi `k` lần liên tiếp thì biến đổi thành số `n`.

# Ví dụ:

| Input | Output |
| ----- | ------ |
| 10 3  | 3      |
- Với `n = 10`, `k = 3`, thì kết quả mong muốn là `3`.
Giải thích: `3` số đó là `12`, `13`, `80`.
`12` biến đổi `3` lần:` 12->6->3->10`.
`13` biến đổi `3` lần: `13->40->20->10`.
`80` biến đổi `3` lần: `80->40->20->10`.

| Input | Output |
| ----- | ------ |
| 5 2   | 2      |
- Với `n = 5`,`k = 2`, thì kết quả mong muốn là `2`.
Giải thích: `2` số đó là `3`, `20`.
`3` biến đổi `2` lần: `3->10->5`.
`20` biến đổi `2` lần: `20->10->5`.

# Hưỡng dẫn
Thay vì kiểm tra các số nào có thể biến đổi `k` lần thành số `n`, thì hay lần lượt kiểm tra các số nào có thể biến đổi `1` lần thành số `n` ví dụ là `x` và `y`, sau đó tiếp tục gọi hàm xem số nào có thể biến đổi `k-1 `lần thành số `x` và `y`. Nếu `k = 0` thì trả về `1`.
