n = int(input())
A = list(map(int, input().split()))
ans = sum([abs(item) for item in A])
def flip(a):
    res = [a[0]]
    for i in range(len(a) - 2):
        if a[i] < 0:
            a[i+1] = - a[i+1]
        res.append(a[i+1])
    return(res)
r = flip(A[:])
l = flip(A[::-1])[::-1]
costs = []
for ri, li in  zip(r, l):
    if ri * li >= 0:
        costs = [0]
        break
    else:
        costs.append(min(abs(ri), abs(li)))
print(ans - 2 * min(costs))
