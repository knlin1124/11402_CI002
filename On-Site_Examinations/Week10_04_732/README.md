# UVa 732 - Anagrams by Stack

## 解題思路

這題給兩個字串：

- 第一個字串：輸入字串（Input）
- 第二個字串：目標字串（Output）

只能利用一個 **Stack（堆疊）** 完成轉換。

Stack 有兩種操作：

```text
i → push（放入 Stack）
o → pop（從 Stack 取出）
```

要求輸出所有可能的操作序列，使第一個字串可以變成第二個字串。

由於需要列舉所有可能答案，因此最適合使用 **DFS（Depth First Search）+ Stack 模擬**。

---

## 關鍵邏輯

### 1. i（Push）

如果還有字元尚未放入 Stack：

```cpp
stack.push(input[inIndex]);
```

操作序列加入：

```text
i
```

然後繼續 DFS。

---

### 2. o（Pop）

若：

```text
Stack 不為空
```

且：

```text
stack.top() == output[outIndex]
```

表示目前可以彈出。

```cpp
stack.pop();
```

操作序列加入：

```text
o
```

然後繼續 DFS。

---

### 3. DFS 搜尋所有可能

每一步都有可能：

```text
Push
Pop
```

因此利用 DFS 遞迴搜尋。

當：

```text
outIndex == output.length()
```

表示成功完成轉換。

輸出目前操作序列。

---

## 範例推導

假設：

```text
Input

madam

Output

adamm
```

其中一種合法操作：

```text
i i o i o o i i o o
```

代表：

```text
push
push
pop
push
pop
pop
push
push
pop
pop
```

最後成功得到：

```text
adamm
```

---

## 語言差異與踩坑紀錄

這題容易犯的錯誤：

1. 不是求一組答案，而是列舉所有答案。
2. 每次 DFS 都要恢復 Stack 狀態（Backtracking）。
3. Push、Pop 的順序都可能不同。
4. 若兩字串長度不同，一定沒有答案。
5. 每組答案都必須輸出在：

```text
[
...
]
```

之間。

---

## 總結（Takeaway）

這題是 DFS + Stack + Backtracking 的經典題。

解題流程如下：

1. 判斷兩字串長度是否相同。
2. 使用 DFS 嘗試 Push 或 Pop。
3. 每一步恢復 Stack 狀態。
4. 成功時輸出操作序列。
5. 枚舉所有可能答案。

**Time Complexity：** 約 `O(2^n)`（最壞情況需枚舉所有合法操作）

**Space Complexity：** `O(n)`
