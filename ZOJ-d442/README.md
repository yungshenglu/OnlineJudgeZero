# ZOJ-d442 - Happy Number

讓我們定義正整數 $S_0$ 中每個數字的平方和為 $S_1$。以相同的方法我們定義 $S_1$ 中每個數字的平方和為 $S_2$，並依此類推。假如有某個 $S_i = 1$ ($i \ge 1$) 則我們說 $S_04 是一個 Happy number。如果某一個數不是 Happy number，那他就是一個 Unhappy number。例如：$7$ 是一個 Happy number，因為 7 → 49 → 97 → 130 → 10 → 1。但是 $4$ 是一個 Unhappy number，因為 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4，永遠也無法產生 $1$。

> * 題目來源：**UVA-10591**
> * 記憶體限制：512 MB
> * 公開測資點#0 (100%): 3.0s , < 1M

---
## Input

輸入的第一列有一個整數代表以下有多少組測試資料，每組測試資料一列含有 $1$ 個正整數 $N$ ($N < 10^9$)

---
## Output

對每組測試資料輸出一列，輸出 $N$ 為 Happy number 或 Unhappy number，請參考 Sample Output。

---
## Sample Input

```
3
7
4
13
```

---
## Sample Output

```
Case #1: 7 is a Happy number.
Case #2: 4 is an Unhappy number.
Case #3: 13 is a Happy number. 
```