history = set([])

def make_divisors(n):
    lower_divisors , upper_divisors = [], []
    i = 1
    while i*i <= n:
        if n % i == 0:
            lower_divisors.append(i)
            if i != n // i:
                upper_divisors.append(n//i)
        i += 1
    return lower_divisors + upper_divisors[::-1]

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

def func(n):
    if n == 1:
        return 
    l = make_divisors(n)
    for i in sorted(l[1:]):
        if i in history:
            continue
        if len(factorization(i)) > 1:
            continue
        history.add(i)
        _ = n // i
        func(_)
        break
    return

N = int(input())
if N == 0:
    print(0)
elif N == 1:
    print(0)
else:
    func(N)
    print(len(history))
