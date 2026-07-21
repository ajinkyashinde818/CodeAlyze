n=int(input())
 
def make_divisors(n):#約数列挙
    lower_divisors , upper_divisors = [], []
    i = 1
    while i*i <= n:
        if n % i == 0:
            lower_divisors.append(i)
            if i != n // i:
                upper_divisors.append(n//i)
        i += 1
    return lower_divisors + upper_divisors[::-1]

def factorization(n):#素因数分解
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

def is_prime(q):#素数判定
    q = abs(q)
    if q == 2: return True
    if q < 2 or q&1 == 0: return False
    return pow(2, q-1, q) == 1

k=make_divisors(n)#nの約数のリスト
c=0#操作回数
#2つ目の条件よりnの約数を全て探索する・
#最大回数割るためには小さい約数から順に行うのがベスト
for i in range(len(k)):
    if i==0:pass #約数1をpass
    else:
        l1=factorization(k[i])#i-1番目に小さい約数を素因数分解してn乗数かどうかの確認
        seigo=is_prime(l1[0][0])#そのn乗数が素べきかどうかチェック
        #条件1~3を満たす場合のみ操作を行う
        if len(l1)==1 and seigo==True and n%k[i]==0:#最後に割り切れるかどうかのチェック
            n//=k[i]
            c+=1
        
print(c)
