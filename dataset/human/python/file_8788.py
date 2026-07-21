k,n = list(map(int, input().split()))
a = list(map(int, input().split()))
"""
ans = max(a) - min(a)
for i, num in enumerate(a):
    if num>(k/2):
        a[i] = num - k

print(min(ans,max(a) - min(a)))

min
abs(ai-bi)
abs(ai-(bi-k))
"""
def saitan(num1,num2,k):
    return min(abs(num1 - num2), abs(num1-(num2-k)))

bb = saitan(a[0], a[n-1], k)
for i in range(1,n):
    bb = max(bb, saitan(a[i], a[i-1], k))

print(k-bb)
