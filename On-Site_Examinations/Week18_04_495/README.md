# UVa 495 - Fibonacci Freeze

## 解題思路

這題要求輸出第 `n` 個 Fibonacci 數。

由於：

```text
n ≤ 5000
```

第 5000 個 Fibonacci 數已經超過一般整數型別 (`long long`) 能表示的範圍，因此必須使用 **Big Integer（大數）**。

這題是一道非常經典的 **Dynamic Programming（DP） + Big Integer** 題目。

---

## 關鍵邏輯

### 1. DP 定義

令：

```cpp
dp[i]
```

表示：

```text
第 i 個 Fibonacci 數。
```

---

### 2. 狀態轉移

Fibonacci 的定義：

```text
F(0) = 0

F(1) = 1
```

之後：

```cpp
F(n) = F(n-1) + F(n-2)
```

因此：

```cpp
dp[i] = dp[i-1] + dp[i-2];
```

---

### 3. 預先計算

因為：

```text
n ≤ 5000
```

所以可以一次預先算好：

```text
F(0) ~ F(5000)
```

之後每筆查詢：

```text
O(1)
```

即可回答。

---

## 範例推導

DP：

```text
F(0)=0

F(1)=1

F(2)=1

F(3)=2

F(4)=3

F(5)=5

F(6)=8
```

若輸入：

```text
6
```

答案：

```text
8
```

---

## 語言差異與踩坑紀錄

這題容易犯的錯誤：

1. `long long` 不夠大。
2. 必須使用 Big Integer。
3. Fibonacci 從：

```text
F(0)=0

F(1)=1
```

開始。

4. 可以一次預先計算全部。
5. 題目直到 EOF。

---

## 總結（Takeaway）

這題是 Big Integer DP 的經典題。

解題流程如下：

1. 建立 DP 陣列。
2. 使用：

```cpp
dp[i] = dp[i-1] + dp[i-2];
```

3. 預先算到 5000。
4. 每次查詢直接輸出。

**Time Complexity：**

```text
預處理：O(n)

查詢：O(1)
```

**Space Complexity：** `O(n)`
