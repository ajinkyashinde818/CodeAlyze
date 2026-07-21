ini = lambda : int(input())
inm = lambda : map(int,input().split())
inl = lambda : list(map(int,input().split()))
gcd = lambda x,y : gcd(y,x%y) if x%y else y
def factorization(n):
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
def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)
    divisors.sort()
    return divisors

#maincode-------------------------------------------------
s = input()
q = ini()
mae = ''
bac = s
for i in range(q):
    a = input()
    if a[0] == '1':
        temp = mae
        mae = bac
        bac = temp
    else:
        if a[2] == '1':
            mae = mae + a[4]
        else:
            bac = bac + a[4]
mae = mae[::-1]
print(mae + bac)
