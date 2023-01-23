# Đề bài: 
- Trong một trong trò chơi đoán số, hệ thống sẽ tạo ngẫu nhiên một số nguyên từ 1 đến n. Việc của bạn cần đoán ra số đó là số nào:
    - Nếu bạn đoán trúng thì bạn chiến thắng, trò chơi kết thúc.
    - Nếu bạn đoán lớn hơn thì hệ thống sẽ thông báo là: "`high`" và yêu cầu bạn đoán số khác.
    - Nếu bạn đoán bé hơn thì hệ thống sẽ thông báo là: "`low`" và yêu cầu bạn đoán số khác.
- Hải là một người kém may mắn. Cho số nguyên dương n (1 ≤ n ≤ 1015) hãy tìm và đưa ra số lần đoán ít nhất để Hải chắc chắn sẽ đoán trúng số của hệ thống.

- Biết rằng Hải sẽ chọn cách đoán thông minh nhất có thể.

# Hưỡng dẫn
Cách đoạn thông minh nhất là chúng ta sẽ đoán phần tử ở giữa trong đoạn từ `1 đến n`, do Hải kém may mắn nên phần tử cần đoán sẽ nhỏ hoặc lớn hơn phần tử cần đoán, Số phần tử mà Hải phải đoán trong lần tiếp theo là `n-(n+1)/2`, đến khi chỉ còn 1 phần tử thì Hải chắc chắn sẽ đoán trúng.

```c++
int gameGuessNumber(long long n)
{
    if (n==1) return 1;
	return 1 + gameGuessNumber(n-(n+1)/2);
}
```