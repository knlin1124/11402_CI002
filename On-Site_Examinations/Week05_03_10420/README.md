# UVa 10420 - List of Conquests

## 解題思路

這題要統計每個國家出現的次數。

輸入的每一行代表一個女生的資料，格式大致是：

```text
Country Name
```

其中第一個字是國家名稱，後面的名字其實不重要。

所以我們只需要讀取每一行的第一個字，也就是國家名稱，然後統計每個國家出現幾次。

---

## 關鍵邏輯

### 1. 使用 map 統計國家次數

因為題目最後要求按照國家名稱字母順序輸出，所以可以使用 `map`。

`map` 會自動依照 key 由小到大排序。

```cpp
map<string, int> countryCount;
```

每讀到一個國家，就讓它的次數加一：

```cpp
countryCount[country]++;
```

---

### 2. 忽略後面的名字

每一行只有第一個單字是國家，後面的名字不需要處理。

所以可以先用：

```cpp
cin >> country;
```

讀取國家名稱。

再用：

```cpp
getline(cin, name);
```

把後面整行名字讀掉。

---

## 範例推導

假設輸入：

```text
Spain Donna
England Jane
Spain Alice
Brazil Maria
England Amy
```

統計結果：

```text
Spain 2
England 2
Brazil 1
```

因為要依照國家名稱排序，所以輸出：

```text
Brazil 1
England 2
Spain 2
```

---

## 語言差異與踩坑紀錄

這題容易錯的地方：

1. 國家名稱只會是第一個單字。
2. 後面的名字可能包含空白，要用 `getline()` 讀掉。
3. 輸出要按照國家名稱字母順序。
4. 使用 `map` 可以自動完成排序。
5. 每行輸出格式是：

```text
Country count
```

---

## 總結（Takeaway）

這題是字串處理與 map 統計的基本題。

解題步驟如下：

1. 讀入資料筆數。
2. 每筆資料先讀取國家名稱。
3. 忽略後面的名字。
4. 使用 `map` 統計國家出現次數。
5. 依照國家名稱排序輸出結果。

**Time Complexity：** `O(n log n)`

**Space Complexity：** `O(n)`
