def p_f(n):
    res = []
    a = 2
    while a**2 <= n:
        if n % a == 0:
            ex = 0
            while n % a == 0:
                n //= a
                ex += 1
            
            res.append([a, ex]) #割り終わったら素因数と指数を格納
        
        a += 1
    if n > 1: res.append([n, 1]) #最後が素数ならそれも格納
    
    return res

n = int(input())
p_f_l = p_f(n) #素因数分解した結果リスト
ans = 0
for i in p_f_l:
    p = i[0] #素数
    ex = i[1] #指数上限
    for j in range(1,ex+1):
        if n % p**j == 0:
            n //= p**j
            ans += 1
print(ans)
