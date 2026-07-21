N = int(input())


def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n ** 0.5 // 1)) + 1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr.append([i, cnt])

    if temp != 1:
        arr.append([temp, 1])

    return arr


res = factorization(N)
sum = 0

steps = [1]

for i in range(2, 300):
    steps.append(steps[-1] + i)

if len(res) == 0:
    print(0)
else:
    for fact in res:
        num = fact[-1]
        count = 0
        for s in steps:
            if s > num:
                break
            count += 1
            
        sum += count

    print(sum)
