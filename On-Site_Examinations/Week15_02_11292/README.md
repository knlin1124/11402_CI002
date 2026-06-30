# UVa 11292 - Dragon of Loowater

## 解題思路

這題要幫騎士砍掉所有龍頭。

題目給定：

- `n` 個龍頭，每個龍頭有一個直徑。
- `m` 位騎士，每位騎士有一個身高。

規則：

- 一位騎士只能砍一個龍頭。
- 騎士的身高必須 **大於等於** 龍頭直徑才能砍。
- 僱用騎士的花費就是他的身高。

目標是：

> **用最少的總花費砍掉所有龍頭。**

如果沒有足夠的騎士，就輸出：

```text
Loowater is doomed!
```

這題使用 **Greedy（貪心法）** 即可解決。

---

## 關鍵邏輯

### 1. 排序

先排序：

```cpp
sort(dragon.begin(), dragon.end());
sort(knight.begin(), knight.end());
```

讓龍頭和騎士都由小到大排列。

---

### 2. 使用兩個指標

建立：

```text
i → 目前龍頭

j → 目前騎士
```

依序尋找。

---

### 3. 找第一位可以砍的騎士

如果：

```text
knight[j] >= dragon[i]
```

代表：

```text
這位騎士可以砍這顆龍頭
```

花費增加：

```cpp
cost += knight[j];
```

接著：

```text
i++
j++
```

處理下一顆龍頭。

---

若：

```text
knight[j] < dragon[i]
```

代表：

```text
騎士太矮
```

直接：

```text
j++
```

找下一位。

---

## 範例推導

假設：

```text
Dragon：

5 4
```

```text
Knight：

7 8 4
```

排序：

```text
Dragon：

4 5
```

```text
Knight：

4 7 8
```

第一顆：

```text
4 ← 4

Cost = 4
```

第二顆：

```text
5 ← 7

Cost = 11
```

答案：

```text
11
```

---

## 語言差異與踩坑紀錄

這題容易犯的錯誤：

1. 一定要排序。
2. 每位騎士只能使用一次。
3. 每顆龍頭只能被砍一次。
4. 若龍頭沒砍完，就輸出：

```text
Loowater is doomed!
```

5. 不需要 DP，Greedy 即可。

---

## 總結（Takeaway）

這題是 Greedy 配對問題。

解題流程如下：

1. 排序龍頭。
2. 排序騎士。
3. 每顆龍頭找第一位可以砍它的騎士。
4. 花費累加。
5. 若所有龍頭都成功配對，輸出花費；否則輸出 `Loowater is doomed!`。

**Time Complexity：** `O((n + m) log(n + m))`

**Space Complexity：** `O(n + m)`
