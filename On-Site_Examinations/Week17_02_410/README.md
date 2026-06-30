# UVa 410 - Station Balance

## 解題思路

這題有：

- `C` 個 Chamber（艙室）
- `S` 個樣本（Sample）

每個樣本都有重量。

目標是：

1. 將所有樣本放入 `C` 個 Chamber。
2. 每個 Chamber 最多放兩個樣本。
3. 讓各 Chamber 的總重量盡量平均。
4. 最後輸出每個 Chamber 的內容，以及 **IMBALANCE**（不平衡值）。

這題使用 **Greedy（貪心法）**。

---

## 關鍵邏輯

### 1. 補齊樣本

每個 Chamber 最多放兩個樣本，因此總共需要：

```text
2 × C
```

個位置。

如果：

```text
S < 2 × C
```

不足的地方補：

```text
0
```

代表沒有樣本。

---

### 2. 排序

將所有重量排序：

```cpp
sort(sample.begin(), sample.end());
```

---

### 3. 配對

最小重量：

```text
sample[0]
```

配：

```text
sample[last]
```

依此類推：

```text
最小 + 最大

第二小 + 第二大
```

這樣可以讓每個 Chamber 的重量最平均。

---

### 4. 計算平均重量

所有樣本重量總和：

```text
sum
```

平均：

```text
average = sum / C
```

每個 Chamber：

```text
weight
```

的不平衡值：

```text
abs(weight - average)
```

全部加總就是答案。

---

## 範例推導

假設：

```text
C = 2

S = 3
```

重量：

```text
1 2 6
```

補：

```text
0
```

排序：

```text
0 1 2 6
```

配對：

```text
0 + 6

1 + 2
```

Chamber：

```text
6

3
```

平均：

```text
9 / 2 = 4.5
```

IMBALANCE：

```text
|6 - 4.5|

+

|3 - 4.5|

=

3
```

---

## 語言差異與踩坑紀錄

這題容易犯的錯誤：

1. 樣本不足要補 0。
2. 一定要排序。
3. 最小配最大。
4. 平均值使用 `double`。
5. IMBALANCE 保留五位小數。

---

## 總結（Takeaway）

這題是 Greedy 配對問題。

解題流程如下：

1. 補齊到 `2 × C` 個樣本。
2. 排序。
3. 最小與最大配對。
4. 計算每個 Chamber 重量。
5. 計算並輸出 IMBALANCE。

**Time Complexity：** `O(C log C)`

**Space Complexity：** `O(C)`
