# UVa 10405 - Longest Common Subsequence

## 解題思路

這題要求找出兩個字串的 **Longest Common Subsequence（最長共同子序列，LCS）** 長度。

**子序列（Subsequence）** 不要求字元連續，但必須保持原本的相對順序。

例如：

```text
String A：ABCBDAB
String B：BDCABA
```

其中一個 LCS 為：

```text
BCBA
```

長度就是：

```text
4
```

這題是 Dynamic Programming（DP）的經典題目。

---

## 關鍵邏輯

### 1. 定義 DP 狀態

令：

```cpp
dp[i][j]
```

表示：

```text
A 前 i 個字元
與
B 前 j 個字元

LCS 的最大長度
```

---

### 2. 狀態轉移

如果目前兩個字元相同：

```cpp
A[i-1] == B[j-1]
```

代表可以加入共同子序列：

```cpp
dp[i][j] = dp[i-1][j-1] + 1;
```

---

若不同：

```cpp
A[i-1] != B[j-1]
```

只能捨棄其中一個字元：

```cpp
dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
```

---

## 範例推導

假設：

```text
A = ABCD

B = ACBD
```

建立 DP 表格：

```text
      A C B D

A     1
B
C
D
```

依序填表後：

```text
答案 = dp[n][m]
```

最後得到：

```text
3
```

其中一個 LCS：

```text
ABD
```

---

## 語言差異與踩坑紀錄

這題容易犯的錯誤：

1. LCS 不是連續字串。
2. 與 Longest Common Substring 不同。
3. 要使用 `getline()`，因為字串可能包含空白。
4. 每組測資輸出一個整數即可。
5. 題目輸入直到 EOF。

---

## 總結（Takeaway）

這題是 Dynamic Programming 的經典題。

解題流程如下：

1. 讀入兩個字串。
2. 建立 DP 表。
3. 若字元相同，左上角 +1。
4. 若不同，取上方或左方最大值。
5. 最後輸出 `dp[n][m]`。

**Time Complexity：** `O(n × m)`

**Space Complexity：** `O(n × m)`
