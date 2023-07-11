- Thuật toán **Dijkstra** dùng để giải quyết bài toán *đường đi ngắn nhất một nguồn* (Single-source shortest path), **đồ thị trọng số không âm**.
  
- Tạo một mảng lưu khoảng cách từ điểm gốc truyền vào `distant`. Chúng ta cần tạo một mảng để đánh dấu điểm đã truyền vào mảng đã tạo `visited`.

- Ở mỗi bước chúng ta tìm điểm chưa được đánh dấu trong `visited` và có khoảng cách nhỏ nhất. Sau khi tìm được điểm, ta cập nhập khoaảng cách vào mảng `distant`. Loop đến khi trong `visited` hết điểm. 
