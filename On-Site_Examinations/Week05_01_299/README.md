# UVa 299 - Train Swapping

## 解題思路

這題要求我們計算將一列火車車廂依照編號由小到大排序時，最少需要進行多少次相鄰交換。

由於每次只能交換相鄰的兩節車廂，因此可以直接利用 **Bubble Sort（泡沫排序）** 來模擬排序過程。

每當前面的車廂編號比後面的車廂編號大時，就代表它們的位置錯誤，需要交換一次，同時將交換次數加一。

---

## 關鍵邏輯

### 1. 使用 Bubble Sort 排序

Bubble Sort 每次比較相鄰兩個元素：

```cpp
if (train[j] > train[j + 1])
```

若順序錯誤，就交換兩個元素：

```cpp
swap(train[j], train[j + 1]);
```

每交換一次，就代表進行了一次合法的相鄰交換，因此：

```cpp
swaps++;
```

---

### 2. 為什麼 Bubble Sort 就是答案？

Bubble Sort 的交換方式完全符合題目規定：

- 一次只能交換相鄰兩節車廂。
- 每次交換都會讓排序更接近完成。

因此 Bubble Sort 的交換次數，就是題目要求的最少交換次數（也就是逆序數）。

---

## 範例推導

假設輸入：

```text
3
3 2 1
```

排序過程：

第一次：

```text
3 2 1
↓
2 3 1
```

交換 1 次。

第二次：

```text
2 3 1
↓
2 1 3
```

交換 2 次。

第三次：

```text
2 1 3
↓
1 2 3
```

交換 3 次。

因此輸出：

```text
Optimal train swapping takes 3 swaps.
```

---

## 語言差異與踩坑紀錄

這題最容易犯的錯誤有：

1. Bubble Sort 內層迴圈範圍寫錯。
2. 每筆測資忘記把交換次數歸零。
3. 輸出格式要完全符合題目要求：

```text
Optimal train swapping takes X swaps.
```

最後一定要有句點 (`.`)。

---

## 總結（Takeaway）

這題其實就是 Bubble Sort 的經典應用。

透過模擬相鄰交換，可以直接得到最少交換次數。

雖然也可以利用 Merge Sort 計算逆序數，但由於本題資料量很小，Bubble Sort 已經足夠通過。

本題最大的收穫是理解 **Bubble Sort 的交換次數就是逆序數**，也是最少需要的相鄰交換次數。

**Time Complexity：** `O(n²)`

**Space Complexity：** `O(n)`
