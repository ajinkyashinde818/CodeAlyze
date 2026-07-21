import sys
def factoring(n):
    if n == 0:
        return {0: 1}
    if n == 1:
        return {1: 1}
    nOrigin = n
    n = n**0.5
    numlist = [0 for i in range(int(n) + 1)]
    numlist[0] = -1
    numlist[1] = -1

    t = 2
    while t < (n**0.5):
        if numlist[t] == 0:
            numlist[t] = t
            k = 2
            while t * k <= n:
                numlist[t * k] = -1
                k += 1
        t += 1
    while t <= n:
        if numlist[t] == 0:
            numlist[t] = t
        t += 1

    result = {}
    for i in numlist:
        if i == -1:
            continue
        j = 0
        while nOrigin % i == 0:
            j += 1
            nOrigin = nOrigin / i
        if j == 0:
            continue
        else:
            result[i] = j

    if int(nOrigin) != 1:
        result[int(nOrigin)] = 1
    return result

def help(e):
    i=0
    while i*(i+1)//2<=e:
        i+=1
    return i-1


N=int(input())
if N==1:
    print(0)
    sys.exit(0)
d=factoring(N)

retval=0
for key,value in d.items():
    retval+=help(value)


print(retval)
