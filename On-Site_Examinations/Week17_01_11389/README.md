# UVa 11389 - The Bus Driver Problem

## 解題思路

這題有 `n` 位公車司機，每位司機每天都要跑：

- 一條早班路線（Morning Route）
- 一條晚班路線（Evening Route）

若一天總工作時間超過：

```text
d
```

超出的部分就算加班，每小時加班費為：

```text
r
```

目標是：

> **安排早班與晚班的配對，使總加班費最少。**

這題使用 **Greedy（貪心法）**。

---

## 關鍵邏輯

### 1. 排序

將：

- Morning 由小到大排序。
- Evening 由大到小排序。

```cpp
sort(morning.begin(), morning.end());
sort(evening.begin(), evening.end(), greater<int>());
```

這樣可以讓最長的晚班搭配最短的早班，降低總工時。

---

### 2. 計算每天工作時間

每位司機：

```text
work = morning[i] + evening[i]
```

如果：

```text
work > d
```

就需要加班：

```text
overtime = work - d
```

加班費：

```text
overtime × r
```

---

### 3. 累加所有司機

把每位司機的加班費累加，就是答案。

---

## 範例推導

假設：

```text
Morning：

2 4 6
```

```text
Evening：

8 6 4
```

排序後：

```text
Morning：

2 4 6
```

```text
Evening：

8 6 4
```

若：

```text
d = 8

r = 2
```

工作時間：

```text
2 + 8 = 10

加班：

2
```

```text
4 + 6 = 10

加班：

2
```

```text
6 + 4 = 10

加班：

2
```

總加班：

```text
6
```

加班費：

```text
12
```

---

## 語言差異與踩坑紀錄

這題容易犯的錯誤：

1. Morning 要升序排序。
2. Evening 要降序排序。
3. 超過 `d` 才需要加班。
4. 不超過 `d` 不用加班。
5. 輸入：

```text
0 0 0
```

代表結束。

---

## 總結（Takeaway）

這題是 Greedy 配對問題。

解題流程如下：

1. 將 Morning 升序排序。
2. 將 Evening 降序排序。
3. 一一配對。
4. 超過 `d` 的部分計算加班費。
5. 輸出總加班費。

**Time Complexity：** `O(n log n)`

**Space Complexity：** `O(n)`
