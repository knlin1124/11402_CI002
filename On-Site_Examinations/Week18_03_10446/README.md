# UVa 10446 - The Marriage Interview :-)

## 解題思路

這題給一個遞迴函式，形式類似 Fibonacci，但多了一個參數 `back`。

題目要求計算：

```text
trib(n, back)
```

這個函式的呼叫次數。

如果直接使用遞迴，會產生大量重複計算，因此需要使用 **Dynamic Programming / Memoization（記憶化搜尋）**。

---

## 關鍵邏輯

### 1. 遞迴定義

當：

```text
n <= 1
```

表示已經到達基本情況。

此時呼叫次數為：

```text
1
```

---

### 2. 一般情況

對於：

```text
trib(n, back)
```

會呼叫：

```text
trib(n-1, back)
trib(n-2, back)
...
trib(n-back, back)
```

因此總呼叫次數為：

```text
1 + trib(n-1, back) + trib(n-2, back) + ... + trib(n-back, back)
```

其中前面的 `1` 代表目前這次函式呼叫本身。

---

### 3. 使用 DP 儲存答案

由於同樣的：

```text
n, back
```

可能被重複計算很多次，因此使用陣列：

```cpp
dp[n][back]
```

記錄已經算過的結果。

---

## 範例推導

假設：

```text
n = 3
back = 2
```

則：

```text
trib(3,2)
= 1 + trib(2,2) + trib(1,2)
```

而：

```text
trib(2,2)
= 1 + trib(1,2) + trib(0,2)
```

所以會有許多重複的子問題。

使用 DP 就可以避免重複計算。

---

## 語言差異與踩坑紀錄

這題容易犯的錯誤：

1. 不能直接暴力遞迴。
2. 答案可能很大，要使用 `long long`。
3. 基本情況 `n <= 1` 回傳 `1`。
4. 每組輸出格式為：

```text
Case X: answer
```

5. 輸入：

```text
n > 60
```

時結束。

---

## 總結（Takeaway）

這題是記憶化遞迴的經典題。

解題流程如下：

1. 定義遞迴函式。
2. 遇到 `n <= 1` 回傳 `1`。
3. 否則計算前 `back` 個子問題。
4. 使用 DP 陣列避免重複計算。
5. 依照 Case 格式輸出。

**Time Complexity：** `O(n × back)`

**Space Complexity：** `O(n × back)`
