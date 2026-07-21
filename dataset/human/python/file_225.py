import math


def main():
    N = int(input())

    a = int(math.sqrt(2 * N))

    if N != a * (a + 1) / 2:
        print('No')
        return

    k = a + 1
    n = a

    S = [[] for i in range(k)]

    count = 0
    for i in range(k):
        for j in range(i+1, k):
            count += 1
            S[i].append(count)
            S[j].append(count)

    print('Yes')
    print(k)
    for Si in S:
        print(str(n) + ' ' + ' '.join(map(str, Si)))

if __name__ == '__main__':
    main()
