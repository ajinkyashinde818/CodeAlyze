import sys
import random
input = sys.stdin.readline


def readstr():
    return input().strip()


def readint():
    return int(input())


def readnums():
    return map(int, input().split())


def readstrs():
    return input().split()


def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n // i)

    divisors.sort()
    return divisors


def is_prime(q, k=50):
    q = abs(q)
    # 計算するまでもなく判定できるものははじく
    if q == 2:
        return True
    if q < 2 or q & 1 == 0:
        return False

    # n-1=2^s*dとし（但しaは整数、dは奇数)、dを求める
    d = (q - 1) >> 1
    while d & 1 == 0:
        d >>= 1

    # 判定をk回繰り返す
    for i in range(k):
        a = random.randint(1, q - 1)
        t = d
        y = pow(a, t, q)
        # [0,s-1]の範囲すべてをチェック
        while t != q - 1 and y != 1 and y != q - 1:
            y = pow(y, 2, q)
            t <<= 1
        if y != q - 1 and t & 1 == 0:
            return False
    return True


def main():
    N = readint()
    if N == 1:
        print(0)
        exit()
    d = make_divisors(N)
    ans = 0
    # print(d)
    p = [i for i in d if is_prime(i)]
    # print(p)
    for i in range(1, 10):
        for z in [j ** i for j in p]:
            if z == 1:
                continue
            if not N % z:
                N //= z
                ans += 1

    print(ans)


if __name__ == "__main__":
    main()
