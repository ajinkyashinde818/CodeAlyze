n = int(input())

def factorization(n):
    d = {}
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            d[i] = cnt

    if temp!=1:
        d[temp] = 1

    if d.keys()==[]:
        d[n] = 1

    return d

def get_a(n):
    N = n
    if n == 1:
        return [1]
    elif n==2:
        return [2]
    else:
        a = [1]

    while 1:
        n_temp = n - a[-1]
        #print(n_temp, a)
        if n_temp<0:
            a.pop()
            a[-1] = N - sum(a[:-1])
            break
        elif n_temp == 0:
            break
        else:
            n = n_temp
        a.append(a[-1]+1)
    #print(n_temp, a)
    return a

ans = 0
fact_dict = factorization(n)
#print(fact_dict)

for key, val in fact_dict.items():
    #print(key, val, get_a(val))
    ans += len(get_a(val))

if ans>0:
    print(ans)
else:
    print(0)
