# UVa 11413 - Fill the Containers

## 解題思路

這題要把 `n` 個 vessel 的容量依照原本順序，裝進 `m` 個 containers 裡。

重點是：

- vessel 的順序不能改變。
- 每個 container 可以裝連續的幾個 vessel。
- 要找出最小的 container 容量，使得所有 vessel 都能被裝完。

這種「找最小可行最大值」的問題，很適合使用 **Binary Search（二分搜尋）**。

---

## 關鍵邏輯

### 1. 答案範圍

container 最小容量至少要能裝下最大的 vessel：

```cpp
left = max(vessel[i])
```

最大容量則可以是所有 vessel 容量總和：

```cpp
right = sum(vessel[i])
```

所以答案一定在：

```text
max(vessel) ~ sum(vessel)
```

---

### 2. 判斷某個容量是否可行

假設 container 容量是 `capacity`。

我們依序把 vessel 放進 container：

- 如果目前 container 還放得下，就繼續放。
- 如果放不下，就換下一個 container。
- 最後檢查使用的 container 數量是否小於等於 `m`。

如果可以在 `m` 個 container 內裝完，代表這個容量可行。

---

### 3. 二分搜尋最小可行容量

如果 `mid` 可行：

```text
代表容量可能還可以更小
```

所以往左半邊找。

如果 `mid` 不可行：

```text
代表容量太小
```

所以往右半邊找。

---

## 範例推導

假設：

```text
vessels = 1 2 3 4 5
m = 3
```

答案範圍：

```text
left = 5
right = 15
```

嘗試容量 `6`：

```text
Container 1: 1 + 2 + 3 = 6
Container 2: 4
Container 3: 5
```

可以裝完，所以 `6` 可行。

嘗試容量 `5`：

```text
Container 1: 1 + 2 = 3
Container 2: 3
Container 3: 4
Container 4: 5
```

需要 4 個 container，超過 `m = 3`，所以不可行。

因此最小容量是：

```text
6
```

---

## 語言差異與踩坑紀錄

這題容易錯的地方：

1. vessel 的順序不能重新排序。
2. container 裝的是連續的 vessel。
3. 最小容量不能小於最大的 vessel。
4. 判斷可行時，要正確計算 container 數量。
5. 輸入有多組測資，直到 EOF 結束。

---

## 總結（Takeaway）

這題是 Binary Search on Answer 的經典題。

解題流程如下：

1. 找出答案範圍：`max(vessel)` 到 `sum(vessel)`。
2. 用二分搜尋猜一個 container 容量。
3. 檢查這個容量是否能在 `m` 個 container 內裝完。
4. 不斷縮小範圍，找出最小可行容量。

**Time Complexity：** `O(n log sum)`

**Space Complexity：** `O(n)`
