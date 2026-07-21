N = int(input())

cnt = 0
result = 0

num = [1,3,6,10,15,21,28,36,45,55,66]

def prime_factorize(n):
    """[summary]
    素因数分解の関数、整数を入力して配列を返す
    計算量はO(√N)
    Arguments:
        n {[int]} -- 素進数分解するための整数

    Returns:
        list -- 素因数分解した後の数字の配列
    """    
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a

def factorization(n):
    """[summary]
    素因数分解して、素数の種類とその素数の個数を二次元配列に入れる
    Arguments:
        n {int} -- 素因数分解する整数

    Returns:
        [arr] -- [[素数, 個数], [素数, 個数], ... ]
    """    
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])
 
    if temp!=1:
        arr.append([temp, 1])
 
    if arr==[]:
        arr.append([n, 1])
 
    return arr


L = factorization(N)

if N == 1:
    print(0)
else:
    for p,e in L:
        cnt = 1
        for i in range(2,100):
            cnt += i
            if e < cnt:
                result += i-1
                break
                
    print(result)
