ii = lambda : int(input())
mi = lambda : map(int,input().split())
li = lambda : list(map(int,input().split()))

n = ii()

def factor(x):
    i = 2
    l = []
    while i**2 <= x:
        y = 0
        while x%i == 0:
            x/=i
            y+=1
        if y != 0:
            l.append([i,y])
        i+=1
    
    if x != 1:
        l.append([x,1])
    return l

l = factor(n)
# print(l)

ans = 0
for i in l:
    p = i[0]
    c = i[1]
    b = 1
    while c >= b:
        ans += 1
        c -= b
        b += 1

print(ans)
