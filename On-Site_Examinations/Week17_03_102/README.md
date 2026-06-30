# UVa 102 - Ecological Bin Packing

## 解題思路

這題有 **3 個垃圾桶（Bin）**，每個垃圾桶中都有三種瓶子：

```text
B → Brown
G → Green
C → Clear
```

每個垃圾桶最後只能放一種顏色，因此需要搬動瓶子。

題目要求：

> **找出搬動次數最少的排列方式。**

如果有多組答案搬動次數相同，就輸出字典序（Lexicographical Order）較小的排列。

由於只有 **3! = 6** 種排列，因此直接暴力列舉所有情況即可。

---

## 關鍵邏輯

### 1. 六種排列

三種顏色共有：

```text
BCG
BGC
CBG
CGB
GBC
GCB
```

總共只有：

```text
6 種
```

---

### 2. 計算搬動次數

例如排列：

```text
BCG
```

表示：

```text
Bin0 放 Brown

Bin1 放 Clear

Bin2 放 Green
```

則：

Bin0 保留：

```text
Brown
```

其餘：

```text
Green + Clear
```

都要搬走。

Bin1 保留：

```text
Clear
```

其餘搬走。

Bin2 保留：

```text
Green
```

其餘搬走。

全部加總就是搬動次數。

---

### 3. 找最小值

六種排列全部算一次。

若：

```text
move < best
```

更新答案。

若：

```text
move == best
```

取字典序較小的排列。

---

## 範例推導

假設：

```text
Bin0：

1 2 3
```

```text
Bin1：

4 5 6
```

```text
Bin2：

7 8 9
```

若排列：

```text
BCG
```

保留：

```text
1

6

8
```

其他全部搬走。

算出搬動次數。

六種排列都計算一次。

選最小即可。

---

## 語言差異與踩坑紀錄

這題容易犯的錯誤：

1. 不需要 Greedy。
2. 不需要 DP。
3. 因為只有 6 種排列，直接暴力即可。
4. 相同搬動次數時，要選字典序較小。
5. 輸入直到 EOF。

---

## 總結（Takeaway）

這題是排列枚舉（Permutation Enumeration）的經典題。

解題流程如下：

1. 讀入三個 Bin 的資料。
2. 列舉六種排列。
3. 計算每種搬動次數。
4. 找最小值。
5. 輸出最佳排列與搬動次數。

**Time Complexity：** `O(6)`（固定常數時間）

**Space Complexity：** `O(1)`
