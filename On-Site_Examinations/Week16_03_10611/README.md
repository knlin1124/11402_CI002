# UVa 10611 - The Playboy Chimp

## 解題思路

這題會給一排母猩猩的身高，接著有多個查詢。

每個查詢是一隻公猩猩的身高 `x`，要找出：

1. 比 `x` 矮的最高身高。
2. 比 `x` 高的最低身高。

如果找不到，就輸出：

```text
X
```

因為母猩猩身高已經是排序好的，所以可以使用 **Binary Search（二分搜尋）**。

---

## 關鍵邏輯

### 1. 找比 x 矮的最高身高

要找第一個大於等於 `x` 的位置：

```cpp
lower_bound(heights.begin(), heights.end(), x)
```

它前一個位置就是比 `x` 小的最大值。

---

### 2. 找比 x 高的最低身高

要找第一個大於 `x` 的位置：

```cpp
upper_bound(heights.begin(), heights.end(), x)
```

這個位置就是比 `x` 大的最小值。

---

## 範例推導

假設母猩猩身高：

```text
1 4 4 7 10
```

查詢：

```text
4
```

比 `4` 矮的最高身高：

```text
1
```

比 `4` 高的最低身高：

```text
7
```

所以輸出：

```text
1 7
```

---

## 語言差異與踩坑紀錄

這題容易犯的錯誤：

1. 不能輸出等於查詢值的身高。
2. 左邊要找的是 `< x`。
3. 右邊要找的是 `> x`。
4. 找不到時要輸出 `X`。
5. 可以直接使用 `lower_bound` 和 `upper_bound`。

---

## 總結（Takeaway）

這題是 Binary Search 的基本應用。

解題流程如下：

1. 讀入排序好的身高陣列。
2. 對每個查詢使用 `lower_bound` 找左答案。
3. 使用 `upper_bound` 找右答案。
4. 依照格式輸出。

**Time Complexity：** `O(q log n)`

**Space Complexity：** `O(n)`
