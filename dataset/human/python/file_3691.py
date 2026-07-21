import sys


def input():
    return sys.stdin.readline().strip()


sys.setrecursionlimit(20000000)

MOD = 10 ** 9 + 7
INF = float("inf")


def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-(n ** 0.5) // 1)) + 1):
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


def main():
    N = int(input())
    if N == 1:
        print(0)
        return
    fact = factorization(N)
    counter = []
    cnt = 0
    for i in range(1, 41):
        cnt += i
        counter.append(cnt)
    answer = 0
    for f in fact:
        for j in range(40):
            c = counter[j]
            if c > f[1]:
                answer += j
                break
            else:
                continue
    print(answer)


if __name__ == "__main__":
    main()
