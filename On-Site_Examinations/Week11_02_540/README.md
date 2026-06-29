# UVa 540 - Team Queue

## 解題思路

這題模擬一個特殊的 Queue。

一般 Queue 是：

```text
先進先出（FIFO）
```

但這題多了一個規則：

**同一個 Team 的成員必須排在一起。**

也就是說：

- 如果某位 Team 的成員第一次進入 Queue，就排在最後。
- 如果他的隊友已經在 Queue 裡，就直接排到隊友的最後面，而不是整個 Queue 的最後。

因此需要同時維護：

1. 每個 Team 自己的 Queue。
2. Team 的 Queue。

---

## 關鍵邏輯

### 1. 建立隊員與 Team 的對應

先讀入所有隊伍：

```cpp
member → team
```

可以利用：

```cpp
map<int,int> teamID;
```

例如：

```text
101 → Team 0
102 → Team 0
201 → Team 1
```

方便之後查詢隊員屬於哪個 Team。

---

### 2. 每個 Team 都有自己的 Queue

建立：

```cpp
queue<int> teamQueue[1000];
```

每個 Team 自己排隊。

---

### 3. 建立 Team Queue

再建立：

```cpp
queue<int> order;
```

裡面放的是：

```text
Team 0
Team 2
Team 1
```

不是放人，而是放 Team 編號。

---

### 4. ENQUEUE

假設：

```text
ENQUEUE 203
```

先找到：

```text
203 屬於 Team 2
```

如果：

```text
Team 2 還沒出現在 Team Queue
```

就：

```cpp
order.push(2);
```

然後：

```cpp
teamQueue[2].push(203);
```

如果 Team 已經在 Queue 中：

只需要：

```cpp
teamQueue[2].push(203);
```

即可。

---

### 5. DEQUEUE

取出：

```cpp
Team Queue 前端
```

例如：

```text
Team 1
```

接著：

```cpp
teamQueue[1].front()
```

就是答案。

若 Team Queue 已空：

```cpp
order.pop();
```

即可。

---

## 範例推導

假設：

```text
Team1：

1 2

Team2：

3 4
```

操作：

```text
ENQUEUE 1

Queue：

1
```

再：

```text
ENQUEUE 3

Queue：

1 | 3
```

再：

```text
ENQUEUE 2
```

因為：

```text
2 和 1 同隊
```

所以：

```text
1 2 | 3
```

而不是：

```text
1 3 2
```

---

## 語言差異與踩坑紀錄

這題容易犯的錯誤：

1. 不只需要一個 Queue。
2. 每個 Team 都要有自己的 Queue。
3. Team Queue 存的是 Team，不是人。
4. 當某個 Team 沒人後，要從 Team Queue 移除。
5. 題目直到：

```text
STOP
```

結束該 Scenario。

---

## 總結（Takeaway）

這題是 Queue 模擬的經典題。

解題流程如下：

1. 建立 member → team 對照表。
2. 每個 Team 建立自己的 Queue。
3. 再建立一個 Team Queue。
4. ENQUEUE 時維護 Team Queue。
5. DEQUEUE 時從 Team Queue 前端取人。

**Time Complexity：** `O(1)`（每次操作）

**Space Complexity：** `O(n)`
