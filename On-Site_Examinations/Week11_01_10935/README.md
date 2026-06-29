# UVa 10935 - Throwing cards away I

## 解題思路

這題要模擬丟牌的過程。

一開始桌上有：

```text
1 2 3 ... N
```

依照規則不斷進行：

1. 丟掉最上面的牌。
2. 將新的最上面那張牌移到牌堆最底下。

一直重複直到只剩下一張牌。

最後輸出：

- 所有被丟掉的牌。
- 最後剩下的牌。

由於整個過程完全符合 **Queue（佇列）** 的操作，因此使用 Queue 最方便。

---

## 關鍵邏輯

### 1. 建立 Queue

先把：

```text
1 ~ N
```

全部放進 Queue。

```cpp
queue<int> q;
```

---

### 2. 丟掉最上面的牌

Queue 最前面就是牌堆最上方：

```cpp
q.front()
```

加入答案後：

```cpp
q.pop();
```

---

### 3. 將下一張牌放到底部

若 Queue 還有牌：

先取得：

```cpp
q.front()
```

然後：

```cpp
q.pop();
q.push(card);
```

即可完成：

```text
最上面 → 最下面
```

---

## 範例推導

假設：

```text
N = 7
```

初始：

```text
1 2 3 4 5 6 7
```

第一步：

```text
Discard 1

Queue：

2 3 4 5 6 7
```

第二步：

```text
Move 2

Queue：

3 4 5 6 7 2
```

接著：

```text
Discard 3

Move 4
```

一直重複直到：

```text
Remaining card: 6
```

---

## 語言差異與踩坑紀錄

這題容易犯的錯誤：

1. 使用 Queue，不是 Stack。
2. 最後只剩一張牌就停止。
3. 輸出格式要完全一致。
4. 若只有一張牌：

```text
Discarded cards:
Remaining card: 1
```

不要多印逗號。

5. 輸入：

```text
0
```

代表結束。

---

## 總結（Takeaway）

這題是 Queue 的經典模擬題。

解題流程如下：

1. 將 1~N 放入 Queue。
2. 丟掉 Queue 前端。
3. 將新的前端放到尾端。
4. 重複直到剩下一張牌。
5. 輸出所有被丟棄的牌與最後剩下的牌。

**Time Complexity：** `O(N)`

**Space Complexity：** `O(N)`
