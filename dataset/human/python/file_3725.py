def factor(n):
    arr = []
    temp = n
    for i in range(2, int(n**0.5)+1):
        if temp%i == 0:
            cnt = 0
            while temp%i == 0:
                cnt += 1
                temp //= i
            arr.append([i, cnt])
    if temp != 1:
        arr.append([temp, 1])
    if arr == [] and n != 1:
        arr.append([n, 1])
    return arr

n = int(input())
fact_n = factor(n)
cnt = 0
for _, e in fact_n:
    i = 1
    while i <= e:
        e -= i
        i += 1
    cnt += i - 1
print(cnt)
