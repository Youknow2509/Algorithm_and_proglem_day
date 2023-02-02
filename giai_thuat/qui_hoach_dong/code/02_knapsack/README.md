
```markdown
Cho n loại hàng. Món hàng thuộc loại hàng i có khối lượng A[i] 
và giá trị C[i]. 

Số lượng các món hàng của mỗi loại không hạn chế. 

Cần chọn các món hàng trong từng loại để bỏ vào một ba lô sao 
cho tổng giá trị của các món hàng đã chọn là lớn nhất nhưng 
tổng khối lượng của chúng không vượt quá khối lượng M cho 
trước. Cho biết số lượng món hàng từng loại hàng được chọn.
```

### Nhận xét bài toán này tương tự bài trước, nhưng khi ta loại bỏ phần tử hay chọn thì phần tử đó vẫn được tính.

- Gọi `F(i, v)` là tổng giá trị lớn nhất của các món hàng được chọn sao cho tổng khối lượng <= v trong i loại hàng.
    - Trường hợp `A[i] > v`: `F(i, v) = F(i-1, v)`
    -  Trường hợp `A[i] <= v`:
        - Nếu loại hàng `i` không được chọn thì:
            `F(i, v) = F(i-1, v)`
        - Nếu có `k` món hàng loại `i` được chọn:
            `F(i, v) = F(i-1, v – A[i]*k) + C[i]*k` 
            - Do đó:
                `F(i, v) = Max{F(i-1, v – A[i]*k) + C[i]*k }`, `(1 <= k <= v/A[i])`
-  Bài toán nhỏ nhất ứng với `i = 0` hay `v = 0` ta có: `F(0, v) = 0`

