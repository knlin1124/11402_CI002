# UVa 12250 - Language Detection

## 解題思路

這題要根據輸入的問候語（Greeting），判斷它屬於哪一種語言。

例如：

```text
HELLO
```

代表：

```text
ENGLISH
```

如果輸入的字串不在題目提供的對照表中，就輸出：

```text
UNKNOWN
```

由於每個問候語都對應唯一的語言，因此最適合使用 **Map（映射）**。

---

## 關鍵邏輯

### 1. 建立對照表

建立：

```cpp
map<string, string> language;
```

內容如下：

```text
HELLO → ENGLISH
HOLA → SPANISH
HALLO → GERMAN
BONJOUR → FRENCH
CIAO → ITALIAN
ZDRAVSTVUJTE → RUSSIAN
```

---

### 2. 查詢

每讀入一個字串：

如果存在：

```cpp
language.count(word)
```

就輸出：

```cpp
language[word]
```

否則：

```text
UNKNOWN
```

---

### 3. 結束條件

輸入：

```text
#
```

代表測資結束。

---

## 範例推導

輸入：

```text
HELLO
```

查表：

```text
HELLO → ENGLISH
```

輸出：

```text
Case 1: ENGLISH
```

---

輸入：

```text
ABC
```

查不到：

```text
UNKNOWN
```

輸出：

```text
Case 2: UNKNOWN
```

---

## 語言差異與踩坑紀錄

這題容易犯的錯誤：

1. 大小寫必須完全一致。
2. 查不到輸出 `UNKNOWN`。
3. 每筆輸出都要加上：

```text
Case X:
```

4. 輸入 `#` 結束。
5. 使用 `map` 查詢最快也最簡單。

---

## 總結（Takeaway）

這題是 Map 查表的基本題。

解題流程如下：

1. 建立問候語與語言的對照表。
2. 讀入每個問候語。
3. 使用 `map` 查詢。
4. 找到就輸出語言。
5. 找不到輸出 `UNKNOWN`。

**Time Complexity：** `O(n log m)`

- `n`：查詢次數
- `m`：對照表大小（固定只有 6 筆）

**Space Complexity：** `O(m)`
