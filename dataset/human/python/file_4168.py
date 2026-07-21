n = int(input())

def factorization(n):
    arr = []
    tmp = n
    for i in range(2, int(n**0.5)+1):
        if tmp % i == 0:
            cnt = 0
            while tmp % i == 0:
                cnt += 1
                tmp //= i
            arr.append([i, cnt])

    if tmp != 1:
        arr.append([tmp, 1])

    if arr == []:
        arr.append([n, 1])

    return arr

if n == 1:
    print(0)
    exit()

arr = factorization(n)
#print(arr)

ans = 0
for x, cnt in arr:
    for i in range(100):
        if i * (i - 1) // 2 <= cnt < i * (i + 1) // 2:
            ans += i - 1
            break

print(ans)
