# ZOJ-a009 - 解碼器

在密碼學裡面有一種很簡單的加密方式，就是把明碼的每個字元加上某一個整數 $K$ 而得到密碼的字元 (明碼及密碼字元一定都在 ASCII 碼中可列印的範圍內)。例如若 $K = 2$，那麼 apple 經過加密後就變成 crrng 了。解密則是反過來做。這個問題是給你一個密碼字串，請你依照上述的解密方式輸出明碼。至於在本任務中 $K$ 到底是多少，請自行參照 Sample Input 及 Sample Output 推出來吧！相當簡單的。

> * 記憶體限制： 512 MB
> * 公開 測資點#0 (100%): 1.0s , < 1K

---
## Input

每筆測試資料一列。每列有 $1$ 個字串，就是需要解密的明碼。

---
## Output

對每一測試資料，請輸出解密後的密碼。

---
## Sample Input

```
1JKJ'pz'{ol'{yhklthyr'vm'{ol'Jvu{yvs'Kh{h'Jvywvyh{pvu5
1PIT'pz'h'{yhklthyr'vm'{ol'Pu{lyuh{pvuhs'I|zpulzz'Thjopul'Jvywvyh{pvu5
```

---
## Sample Output

```
*CDC is the trademark of the Control Data Corporation.
*IBM is a trademark of the International Business Machine Corporation.
```