# UVa 10954 - Add All

## 解題思路

這題要將一串數字全部加總，但每次只能選 **兩個數字相加**。

兩數相加後：

1. 產生新的數字。
2. 新的數字還要再放回集合中，繼續參與之後的加法。
3. 最後只剩下一個數字。

題目要求的是：

```text
所有加法成本（Cost）的最小值
```

這題與 **Huffman Coding** 的概念完全相同，因此最佳策略就是：

> **每次都挑目前最小的兩個數字相加。**

最適合使用 **Priority Queue（Min Heap）**。

---

## 關鍵邏輯

### 1. 建立 Min Heap

把所有數字放進：

```cpp
priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;
```

Heap 最上面永遠都是最小值。

---

### 2. 每次取最小兩個

例如：

```text
1 2 3 4
```

先取：

```text
1 + 2 = 3
```

成本增加：

```text
3
```

再把：

```text
3
```

放回 Heap。

Heap 變成：

```text
3 3 4
```

---

### 3. 重複直到剩一個數字

每次：

```cpp
a = pq.top();
pq.pop();

b = pq.top();
pq.pop();
```

再：

```cpp
sum = a + b;
```

累加成本：

```cpp
cost += sum;
```

最後：

```cpp
pq.push(sum);
```

---

## 範例推導

假設：

```text
1 2 3 4
```

第一次：

```text
1 + 2 = 3

Cost = 3
```

Heap：

```text
3 3 4
```

第二次：

```text
3 + 3 = 6

Cost = 9
```

Heap：

```text
4 6
```

第三次：

```text
4 + 6 = 10

Cost = 19
```

答案：

```text
19
```

---

## 語言差異與踩坑紀錄

這題容易犯的錯誤：

1. 一定要使用 Min Heap。
2. 不可以排序一次後直接一直相加。
3. 每次產生的新數字要重新放回 Heap。
4. 題目直到：

```text
0
```

結束。

5. 成本要一直累加。

---

## 總結（Takeaway）

這題是 Priority Queue（Min Heap）的經典題。

解題流程如下：

1. 將所有數字放入 Min Heap。
2. 每次取出最小兩個數。
3. 相加後更新總成本。
4. 將新的數字放回 Heap。
5. 重複直到 Heap 剩下一個元素。

**Time Complexity：** `O(n log n)`

**Space Complexity：** `O(n)`
