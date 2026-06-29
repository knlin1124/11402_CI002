# UVa 12347 - Binary Search Tree

## 解題思路

這題會給一棵 Binary Search Tree（BST）的 **Preorder Traversal（前序走訪）**。

要求輸出它的 **Postorder Traversal（後序走訪）**。

如果真的建立整棵 BST，再做後序走訪也可以，但效率較差。

更好的方法是利用 BST 的性質，直接利用 Preorder 遞迴分割左右子樹。

---

## 關鍵邏輯

### 1. Preorder 的第一個節點一定是 Root

例如：

```text
Preorder：

8 5 1 7 10 12
```

第一個：

```text
8
```

一定是 Root。

---

### 2. BST 的左右子樹

BST 的性質：

```text
左子樹 < Root
右子樹 > Root
```

因此：

```text
5 1 7
```

都是左子樹。

而：

```text
10 12
```

都是右子樹。

---

### 3. 遞迴建立

每次遞迴：

```text
Root
Left
Right
```

依照 BST 範圍：

```text
(minValue, maxValue)
```

判斷目前節點是否屬於此子樹。

最後：

```text
Left
Right
Root
```

即可得到 Postorder。

---

## 範例推導

Preorder：

```text
8 5 1 7 10 12
```

BST：

```text
        8
      /   \
     5     10
    / \      \
   1   7      12
```

Postorder：

```text
1
7
5
12
10
8
```

---

## 語言差異與踩坑紀錄

這題容易犯的錯誤：

1. 不需要真的建立 Tree。
2. 利用 BST 範圍即可完成遞迴。
3. 要一直讀到 EOF。
4. Postorder 是：

```text
Left
Right
Root
```

5. Root 一定是目前 Preorder 第一個尚未使用的節點。

---

## 總結（Takeaway）

這題利用 BST 的性質，不需要建立整棵樹。

解題流程如下：

1. 讀入所有 Preorder。
2. 利用 BST 範圍遞迴分割左右子樹。
3. 遞迴完成後輸出 Root。
4. 即可得到 Postorder。

**Time Complexity：** `O(n)`

**Space Complexity：** `O(n)`
