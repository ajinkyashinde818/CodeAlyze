K, S = 5, 15
K, S = map(int,input().split())


def calculate(k, s):
    result = 0
    for x in range(k, -1, -1):
        if x > s:
            continue

        for y in range(k, -1, -1):
            if y > s:
                continue
            z = s - x - y

            if z > k:
                continue

            if z < 0:
                continue

            result = result + 1


    print(result)


calculate(K, S)
