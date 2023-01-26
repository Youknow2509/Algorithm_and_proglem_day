
# Kỹ thuật xoay phải.

- Kỹ thuật này thường áp dụng cho những cây nhị phần tìm kiếm bị **lệch về bên trái** (độ cao của cây con trái lớn hơn độ của của cây con phải).
  
    ![](image/1.png)

- Với cách xoay này ta cần quan tâm tới node gốc (A) cây con bên trái (B) và cây con bên phải của cây con bên trái (D).

- Cách xoay:

    - Biến đổi node B thành node gốc, node gốc (A) thành cây con bên phải của B.

        ![](image/2.png)

    - Nếu như trên hình thi node B có tới 3 cây con, sai quy tắc của cây nhị phân, nên ta cần chuyển node D thành node con trái của A.
    *(lưu ý là 2 hoạt động trên diễn ra cùng lúc nên cần phải thêm một số node tạm).*

        ![](image/3.png)

- Ví dụ cụ thể:

    ![](image/4.png)

    Xoay cách xoay phải node trên:

    Gán code node tạm A, B, D vào các vị trí sau:

    ![](image/5.png)

    Đầu tiên gán cây con bên trái của A thành D.

    ![](image/6.png)

    Gán cây con bên phải của B thành A:

    ![](image/7.png)

    Cây sau khi xoay là:

    ![](image/8.png)

- Code mẫu C++:
  ```c++
  node *turnRight(node *a){
  	node *b = a->left;
  	node *d = b->right;
  	a->left = d;
  	b->right = a;
  	return b;
  }
  ```

# Kỹ thuật xoay trái.

- Tương tự kĩ thuật xoay phải

    ![](image/9.png)

- Code mẫu C++:
  ```c++
  node *turnLeft(node *a){
  	node *b = a->right;
  	node *c = b->left;
  	a->right = c;
  	b->left = a;
  	return b;
  }
  ```

# Cách trường hợp xử lý cần bằng để thành cây AVL:

- Có `4` trường hợp lệch trong cây nhị phân tìm kiếm:`
    - Lệch trái - trái:
    - Lệch trái - phải:
    - Lệch phải - phải:
    - Lệch phải  - trái:

## Xử lý lệch trái - trái -> Xoay phải

```markdown
T1, T2, T3 and T4 are subtrees.
         z                                      y 
        / \                                   /   \
       y   T4      Xoay phải (z)             x      z
      / \          - - - - - - - - ->      /  \    /  \ 
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2

```

## Xử lý lệch trái - phải:

```markdown
Với trường hợp lệnh trái - phải, ta phải thực hiện 2 phép xoay:
    Xoay trái trái ở cây con bên trái.
    Xoay phải cây.
```

```markdown
     z                               z                           x
    / \                            /   \                        /  \ 
   y   T4  Xoay trái (y)          x    T4  Xoay phải (z)      y      z
  / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
T1   x                          y    T3                    T1  T2 T3  T4
    / \                        / \
  T2   T3                    T1   T2
```

## Xử lý lệch phải phải -> Xoay phải

```markdown

  z                                y
 /  \                            /   \ 
T1   y     Xoay trái (z)        z      x
    /  \   - - - - - - - ->    / \    / \
   T2   x                     T1  T2 T3  T4
       / \
     T3  T4

```

## Xử lý lệch phải trái:

```markdown
   z                            z                            x
  / \                          / \                          /  \ 
T1   y   Xoay phải (y)       T1   x      Xoay trái (z)    z      y
    / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
   x   T4                      T2   y                  T1  T2  T3  T4
  / \                              /  \
T2   T3                           T3   T4
```

