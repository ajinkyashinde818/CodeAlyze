from collections import Counter

N = int(input())

if N == 1:
    print(0)
else:
    factors = []

    tmp = N
    for i in range(2, int((N+1)**(1/2))+1):
        while tmp % i == 0:
            factors.append(i)
            tmp //= i
    if tmp != 1:
        factors.append(tmp)
    # print(factors)

    counter = Counter(factors)
    # print(counter)

    remains = []
    ans = 0
    for i, item in enumerate(counter.items()):
        # print(item)
        key = item[0]
        val = item[1]
        for j in range(1, val+1):
            if val-j >= 0:
                val -= j
                ans += 1
            else:
                break
            # print("val: {}".format(val))
        if val > 0:
            remains.append([key, val])

    # print(remains)

    print(ans)
