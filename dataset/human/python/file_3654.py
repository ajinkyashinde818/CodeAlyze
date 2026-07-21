def factoring(k): #kを因数分解し、素因数とその個数を辞書に入れて返す。
    import math
    dic = dict()
    n = int(math.sqrt(k))+2
    for i in range(2, n):
        count = 0
        while k%i == 0:
            count += 1
            k = k//i
        if count != 0:
            dic[i] = count
    if k != 1: #sqrt(k)までチェックしてもkが1になっていない --> kが素因数
        dic[k] = 1
    return dic

N = int(input())

dic = factoring(N)

def calc(x):
    k = 0
    while True:
        if k * (k + 1) // 2 > x:
            return k - 1
        k += 1


ans = 0
for i in dic:
    tmp = dic[i]
    ans += calc(tmp)

print (ans)
