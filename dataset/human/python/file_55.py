def gcd_core(a, b):
    if b == 0:
        return a
    else:
        return gcd_core(b, a % b)


def gcd(arr):
    g = gcd_core(arr[0], arr[1])
    for i in range(2, len(arr)):
        g = gcd_core(g, arr[i])
    return g

r,g,b,n = map(int,input().split())
count = 0


for i in range(n//r + 1):
    tempn = n-r*i
    for j in range(tempn//g + 1):
        if (tempn-g*j) % b == 0:
            count += 1

print(count)
