from sys import stdin, setrecursionlimit
from bisect import bisect_right


def factorization(n):
    arr = {}
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr[i] = cnt

    if temp != 1:
        arr[temp] = 1

    if arr == []:
        arr[n] = 1

    return arr


def main():
    input = stdin.buffer.readline
    n = int(input())

    a1 = [0]
    for i in range(10 ** 4):
        a1.append(a1[i] + i + 1)

    ans = 0
    a2 = factorization(n)
    for k in a2:
        ans += bisect_right(a1, a2[k]) - 1

    print(ans)


if __name__ == "__main__":
    setrecursionlimit(10000)
    main()
