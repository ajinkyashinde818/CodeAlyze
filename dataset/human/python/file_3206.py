import math
import collections


def main():
    N = int(input())
    if N == 1:
        print(0)
        exit()
    limit = math.sqrt(N)
    vals = []
    i = 2
    while True:
        if i > limit:
            break
        if N % i == 0:
            vals.append(i)
            N //= i
        else:
            i += 1
    if N != 1:
        vals.append(N)
    c = collections.Counter(vals)
    ans = 0
    for v, freq in c.items():
        i = 0
        while True:
            i += 1
            freq -= i
            if freq < 0:
                break
            ans += 1
    print(ans)


if __name__ == '__main__':
    main()
