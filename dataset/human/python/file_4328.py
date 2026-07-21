import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines


def prime_factorize(n):
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
    if arr == []:
        arr.append([n, 1])
    return arr


n = int(readline())

p = prime_factorize(n)

if n == 1:
    print(0)
    exit()

ans = 0
for f, c in p:
    cnt = 0
    while c >= cnt+1:
        c -= cnt+1
        cnt += 1
    ans += cnt
print(ans)
