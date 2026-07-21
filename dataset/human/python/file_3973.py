import sys
input = sys.stdin.buffer.readline


def fctr1(n): 
    f=[]
    c=0
    r=int(n**0.5)
    for i in range(2,r+2):
        while n%i==0:
            c+=1
            n=n//i
        if c!=0:
            f.append(c)
            c=0
    if n!=1:
        f.append(1)
    return f


n = int(input())

if n == 1:
    print(0)
    exit()

a = fctr1(n)

res = 0
d = dict()

for e in a:
    c = 1
    while e:
        if e >= c:
            res += 1
            e -= c
            c += 1
        else:
            break
print(res)
