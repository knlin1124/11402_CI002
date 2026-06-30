# UVa 10282 - Babelfish

## 解題思路

這題要建立一本簡單的字典。

前半部輸入許多資料：

```text
英文單字 外文單字
```

例如：

```text
dog perro
cat gato
apple manzana
```

表示：

```text
perro → dog

gato → cat

manzana → apple
```

接著輸入許多外文單字，每個都要查詢對應的英文。

如果找不到，就輸出：

```text
eh
```

這題最適合使用 **Map（字典）**。

---

## 關鍵邏輯

### 1. 建立 Dictionary

利用：

```cpp
map<string, string> dict;
```

存放：

```text
外文 → 英文
```

例如：

```text
perro → dog

gato → cat
```

---

### 2. 讀取字典

題目規定：

當遇到空白行時，代表字典建立完成。

例如：

```text
dog perro
cat gato

perro
gato
bird
```

空白行之後就是查詢。

---

### 3. 查詢

如果：

```cpp
dict.count(word)
```

存在：

```cpp
cout << dict[word];
```

否則：

```text
eh
```

---

## 範例推導

假設字典：

```text
dog perro

cat gato

apple manzana
```

查詢：

```text
gato
```

答案：

```text
cat
```

查詢：

```text
banana
```

不存在。

輸出：

```text
eh
```

---

## 語言差異與踩坑紀錄

這題容易犯的錯誤：

1. Key 是外文，不是英文。
2. Value 才是英文。
3. 使用 `getline()` 讀整行。
4. 空白行代表字典輸入結束。
5. 查不到輸出 `eh`。

---

## 總結（Takeaway）

這題是 Map 的基本應用。

解題流程如下：

1. 建立 `map<string,string>`。
2. 讀入字典。
3. 依序查詢。
4. 找到就輸出英文。
5. 找不到輸出 `eh`。

**Time Complexity：** `O((N + Q) log N)`

**Space Complexity：** `O(N)`
