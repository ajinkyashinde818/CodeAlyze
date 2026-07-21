def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr.append([i, cnt])
    if temp != 1:
        arr.append([temp, 1])
    if not arr:
        arr.append([n, 1])
    return arr


N = int(input())

l = [2]
for i in range(1, 9):
    l.append(l[i-1] + 2 + i)

l_N = factorization(N)
ans = []
for j in l_N:
    for k in range(len(l)):
        if j[0] == 1:
            continue
        if j[1] <= l[k]:
            ans.append(len(l[:k+1]))
            break
print(sum(ans))
