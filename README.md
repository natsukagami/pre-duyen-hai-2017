# Lời giải cho Pre Duyên hải 2017
## 1. Chia hết! - smdivx
### Tóm tắt đề bài
 Cho 2 số N và X. Hãy tìm số nhỏ nhất có N chữ số mà chia hết cho X.
### Lời giải tự nhiên
 Hiển nhiên ta có thể thấy ngay thuật toán cho Subtask 1, thử tất cả các số, độ phức tạp O(10 ^ N).

 Với subtask 2, ta có thể sử dụng thuật backtrack 2 phía, tính trước số nhỏ nhất có N/2 chữ số mà chia X dư k rồi thử ghép, độ phức tạp O(10 ^ (N / 2)). Ta cũng có thể sử dụng quy hoạch động, tính `f[i][j]` là số nhỏ nhất có `i` chữ số mà chia X dư `j`, với độ phức tạp O(NX).

 Với subtask 3, thuật quy hoạch động không còn hữu dụng, nhưng ta vẫn có thể sử dụng backtrack 2 phía.

### Độ lớn của đáp án
Kể từ subtask 4, độ lớn của số cần tìm đã vượt xa giới hạn của X. Ta cần phải xem xét lại bài toán dưới một góc nhìn khác. Để đơn giản hóa, ta giả sử N > số chữ số của X.

Ta biết có `9 * 10^(N - 1)` số có `N` chữ số, và số này so với X lớn hơn rất nhiều, vì vậy chắc chắn đáp án có tồn tại.

Ta có thể phát biểu lại bài toán như sau: Cho số N và X, hãy tìm số nhỏ nhất lớn hơn hoặc bằng `10^(N - 1)` mà chia hết cho X.

Hiển nhiên số cần tìm sẽ được sinh ra bằng cách tăng dần số `10^(N - 1)` đến khi nó chia hết cho X. Cũng hiển nhiên không kém, lượng phải tăng thêm là `(10^(N - 1) - (10^(N - 1)) % X) % X`.

### Lời giải chuẩn
Từ nhận xét trên, ta có thuật toán sau:
 - Tính `k = (10^(N - 1) - (10^(N - 1)) % X) % X`
 - Đáp số là `10^(N - 1) + k`

Việc tính `k` có thể được thực hiện dễ dàng bằng vòng for `O(N)`, vừa nhân vừa mod. Để tính ra đáp số, ta có thể cài bignum hoặc xét riêng TH N bé (cộng số) và N lớn (ghép `10..0k`).

Độ phức tạp của thuật toán là `O(N)`.

## 2. Mua vé - tickets
### Tóm tắt đề bài
Có N loại vé, cần phải mua X vé. Mỗi loại vé đều có giá ban đầu là 0, mỗi lần mua vé loại i thì vé loại đó có giá tăng thêm A[i]. Chi phí bé nhất để mua X vé là bao nhiêu?
### Quy hoạch động
Ta có thể giải subtask 1 bằng phương pháp quy hoạch động khá hiển nhiên: gọi `f[i][j]` là chi phí bé nhất để mua `i` vé với các loại vé từ 1 đến `j`. Để tính được chi phí mua `x` vé loại `y` ta có công thức `(x * A[i] * (x + 1)) / 2`.

Độ phức tạp của qhđ sẽ là O(N * K^2) do chuyển trạng thái mất O(K).

### Tham lam?
Không khó để chứng minh ta có thể luôn mua vé rẻ nhất mỗi lần mua cho đến khi mua đủ X vé.

Vì vậy, ta có thuật toán sau:
```
While (chưa đủ X vé)
	k = vé rẻ nhất hiện tại
	mua vé k
```

Việc tìm `k` và cập nhật giá vé có thể làm bằng 1 `priority_queue` xếp theo giá vé.
Mỗi lần lấy 1 vé và thêm 1 vé giá đắt hơn tốn O(log N), vì thế độ phức tạp là O(X log N).

### Tính chất tăng của giá vé
Ta có thể thấy, mỗi lần mua vé, giá vé của tất cả đều không giảm, vì thế mỗi lần mua vé ta không bao giờ mua một vé mà có giá nhỏ hơn một vé đã mua.

Hơn nữa, khi mua một vé giá X, ta đã phải mua tất cả các vé có giá rẻ hơn X. Do vậy, nếu vé đắt nhất ta mua có giá trị là `M`, thì tất cả các vé có giá trị nhỏ hơn `M` đều phải được mua.

Từ đó, ta nhận thấy nếu biết giá của vé đắt nhất ta có thể tính được số vé đã mua. Và ngược lại - với mỗi số lượng vé cần mua ta có thể xác định giá vé đắt nhất ta sẽ mua - và từ đó tính được tổng giá phải trả.

### Thuật toán chuẩn
 - Tìm `M` - giá của vé đắt nhất.
Để tìm được `M` ta sử dụng chặt nhị phân, mỗi lần tính xem có bao nhiêu vé mà có giá không quá `M`, trong O(N).
 - Tính giá và số lượng vé có giá nhỏ hơn `M`. Cũng có thể làm trong O(N).
 - Hiển nhiên số vé còn lại phải mua sẽ có giá `M`.

Độ phức tạp sẽ là O(Nlog(10^9 * 100)).

## 3. ATM
### Lưu ý quan trọng
Đề bài không hề nói đến việc không có số âm. Vì thế ta phải xét trường hợp kí tự đầu tiên là `-`.

Một số bạn mặc dù không để ý nhưng vẫn qua được test, bởi thuật các bạn cho `-` là số bé nhất có thể (< 0), và luôn phải xóa đầu tiên - đúng như ý tưởng của solution.
### Tóm tắt đề bài
Cho một số biểu diễn bởi N kí tự, xóa K kí tự để số còn lại lớn nhất.
### Backtrack
18 kí tự là đủ để thực hiện backtrack O(2 ^ N) trên số gốc.
### Tham lam
Có 2 cách tham lam cho bài này.
Lưu ý nếu số âm ta luôn xóa dấu âm trước.
#### Sử dụng stack
```c++
vector<int> ans;
for (int i = 0; i < N; ++i) {
	while (ans.size() && ans.back() < A[i] && K) {
		ans.pop_back(); --K;
	}
	ans.push_back(A[i]);
}
while (K--) ans.pop_back();
// In ra ans
```
#### Sử dụng tham từng chữ số
```c++
for (int i = 1; i <= N - K; ++i) {
	for (int dig = 9; dig >= 0; --dig) {
		// next[dig] là vị trí số `dig` đầu tiên sau vị trí chữ số mình chọn cuối cùng.
		// Điều kiện là phải có đủ chữ số phia sau để điền nốt
		if (N - next[dig] >= N - K - i) {
			// thêm dig vào đáp số
			// update lại next[]
			break;
		}
	}
}
```
