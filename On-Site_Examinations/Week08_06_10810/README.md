# UVa 10810 - Ultra-QuickSort

## 解題思路

這題要求計算將一個數列排序時，需要進行多少次交換。

實際上，題目要求的就是 **逆序數（Inversion Count）**。

所謂逆序數，就是：

```text
i < j
但是
a[i] > a[j]
```

代表這兩個數字的順序相反。

例如：

```text
3 1 2
```

逆序有：

```text
(3,1)
(3,2)
```

所以答案就是：

```text
2
```

---

## 關鍵邏輯

### 1. 為什麼不能用 Bubble Sort？

Bubble Sort 每交換一次，就代表修正一個逆序。

但是：

```text
N 最大可到 500000
```

若使用 Bubble Sort：

```text
O(N²)
```

一定會 Time Limit Exceeded (TLE)。

因此必須使用：

```text
Merge Sort
```

在排序過程中同時計算逆序數。

---

### 2. Merge 時統計逆序

Merge Sort 合併左右兩段時：

假設：

```text
Left
5 8

Right
3 6
```

當：

```text
3 < 5
```

代表：

```text
5 > 3
8 > 3
```

左半部剩下所有元素都比 3 大。

因此：

```cpp
ans += mid - i + 1;
```

一次就能增加很多逆序。

---

## 範例推導

假設：

```text
2 4 1 3 5
```

逆序有：

```text
2 > 1
4 > 1
4 > 3
```

所以答案：

```text
3
```

Merge Sort 在合併時就能全部算出，不需要暴力比較。

---

## 語言差異與踩坑紀錄

這題最容易犯的錯誤：

1. 使用 Bubble Sort 會 TLE。
2. 答案可能非常大，要使用：

```cpp
long long
```

3. Merge 時：

```cpp
ans += mid - i + 1;
```

不要只加 1。

4. 題目輸入：

```text
0
```

代表結束。

---

## 總結（Takeaway）

這題是 Merge Sort 計算逆序數的經典題。

解題流程如下：

1. 將陣列分成左右兩半。
2. 分別排序。
3. Merge 時統計逆序數。
4. 最後輸出總逆序數。

這種做法比 Bubble Sort 快很多。

**Time Complexity：** `O(N log N)`

**Space Complexity：** `O(N)`
