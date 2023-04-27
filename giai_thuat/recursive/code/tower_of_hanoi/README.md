# Bài Toán Tháp Hà Nội
Cho ba cột `A`, `B`, `C`, có `N` đĩa được đặt ở cột `A`. Xử lí bài toán sao cho:
- Các đĩa trong cột được sắp xếp sao cho đĩa to hơn phải ở bên dưới.
- Mỗi lần di chuyển đĩa chỉ được di chuyển `1` đĩa.

*Hãy di chuyển đĩa từ cột `A` sang cột `C` thoả mãn yêu cầu.*

# Tư duy thuật toán
- Đầu tiên lấy cột `C` làm trung gian, chuyển `n - 1` chiếc đĩa sang cột `B`.
- Chuyển đĩa lớn nhất sang cột `C`.
- Lấy cột `A` làm cột trung gian, chuyển `n - 1` đĩa từ cột `B` sang cột `C`.

*Xem: https://www.youtube.com/watch?v=rf6uf3jNjbo để hiểu hơn.*