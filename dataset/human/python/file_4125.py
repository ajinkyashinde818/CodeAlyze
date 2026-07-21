import math
n = int(input())
n1 = n
if n == 1:
    print(0)
else:
    a = [0]*(int(math.sqrt(n)) + 1)
    a[1] = 1
    ans = 0
    for i in range(2, int(math.sqrt(n)) + 1):
        if a[i] == 0:
            for j in range(i+i, int(math.sqrt(n)) + 1, i):
                a[j] = 1
    for i in range(2, len(a)):
        if a[i] == 0:
            k = 1
            s = i
            while n % s == 0:
                # print(s)
                ans += 1
                n //= s
                s *= i
            while n % i == 0:
                n //= i
    # print(n)
    f = 1
    for j in range(2, int(math.sqrt(n)) + 2):
        if n % j == 0:
            f = 0
            break
    if f and n != 1:
        ans += f
    # print(n1 // i)

    if ans == 0:
        print(1)
    else:
        print(ans)
    # print(len('997764507000'))
