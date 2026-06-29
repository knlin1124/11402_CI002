# UVa 10474 - Where is the Marble?

## 解題思路

這題會給一堆彈珠的數字，以及多個查詢。

每次查詢一個數字時，要回答這個數字在排序後的彈珠中，第一次出現的位置。

如果找不到，就輸出：

```text
x not found
```

如果找到，就輸出：

```text
x found at y
```

其中 `y` 是排序後的位置，從 `1` 開始算。

---

## 關鍵邏輯

### 1. 先排序彈珠

因為題目要求的是排序後的位置，所以必須先排序：

```cpp
sort(marbles.begin(), marbles.end());
```

---

### 2. 使用 lower_bound 找第一次出現位置

`lower_bound` 會找到第一個大於或等於查詢值的位置。

```cpp
auto it = lower_bound(marbles.begin(), marbles.end(), query);
```

如果 `it` 沒有超出範圍，而且 `*it == query`，代表找到了。

位置為：

```cpp
it - marbles.begin() + 1
```

---

## 範例推導

假設彈珠是：

```text
4 1 2 2 3
```

排序後：

```text
1 2 2 3 4
```

查詢：

```text
2
```

`2` 第一次出現在第 `2` 個位置，所以輸出：

```text
2 found at 2
```

查詢：

```text
5
```

找不到，所以輸出：

```text
5 not found
```

---

## 語言差異與踩坑紀錄

這題容易錯的地方：

1. 輸入會有多組測資。
2. 當 `N = 0` 且 `Q = 0` 時結束。
3. 每組測資要輸出：

```text
CASE# 1:
```

注意 `CASE#` 後面有空格，數字後面有冒號。

4. 找到的位置是從 `1` 開始，不是從 `0` 開始。
5. 重複數字時，要輸出第一次出現的位置。

---

## 總結（Takeaway）

這題是排序與二分搜尋的基本題。

解題流程如下：

1. 讀入彈珠數量與查詢數量。
2. 將彈珠排序。
3. 對每個查詢使用 `lower_bound`。
4. 判斷是否找到。
5. 輸出第一次出現的位置。

**Time Complexity：** `O(N log N + Q log N)`

**Space Complexity：** `O(N)`
