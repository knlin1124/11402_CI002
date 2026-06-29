# UVa 12250 - Language Detection

## 解題思路

這題會輸入一句問候語（Greeting），要求判斷它屬於哪一種語言。

每個問候語都唯一對應一種語言，例如：

```text
HELLO → ENGLISH
HOLA → SPANISH
HALLO → GERMAN
```

如果輸入的字串沒有出現在題目提供的對照表中，就輸出：

```text
UNKNOWN
```

輸入會一直持續，直到讀到 `#` 為止。

---

## 關鍵邏輯

### 1. 建立對照表

因為每個問候語都有固定答案，所以可以使用 `map`：

```cpp
map<string, string> language;
```

例如：

```cpp
language["HELLO"] = "ENGLISH";
language["HOLA"] = "SPANISH";
```

---

### 2. 查詢輸入

每讀入一個字串：

先判斷是否存在於 map 中：

```cpp
language.count(word)
```

如果存在，就輸出對應語言。

否則輸出：

```text
UNKNOWN
```

---

### 3. Case 編號

題目要求：

```text
Case 1: ENGLISH
Case 2: FRENCH
...
```

因此每輸入一次，就把 Case 編號加一。

---

## 範例推導

假設輸入：

```text
HELLO
BONJOUR
ABC
#
```

查詢結果：

```text
HELLO → ENGLISH
BONJOUR → FRENCH
ABC → UNKNOWN
```

輸出：

```text
Case 1: ENGLISH
Case 2: FRENCH
Case 3: UNKNOWN
```

---

## 語言差異與踩坑紀錄

這題容易犯的錯誤：

1. 結束條件是 `#`。
2. 輸出格式一定要：

```text
Case X: 語言
```

3. 拼字必須完全符合題目。
4. 使用 `map` 可以讓查詢更方便。

---

## 總結（Takeaway）

這題主要練習：

1. `map` 的建立。
2. 字串查詢。
3. 固定格式輸出。

整體流程如下：

1. 建立問候語與語言的對照表。
2. 不斷讀入字串。
3. 若為 `#` 則結束。
4. 查詢 map 並輸出對應語言。

**Time Complexity：** `O(n log 6)`（可視為 `O(n)`）

**Space Complexity：** `O(1)`
