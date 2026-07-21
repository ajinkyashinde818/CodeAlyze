import sys
sys.setrecursionlimit(10**6)


def factorization(n):
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


def main(input, print):
    n = int(input())
    ans = 0
    ret = factorization(n)
    if ret[0][0] == 1:
        print('0')
        return
    for i in range(len(ret)):
        cnt = 0
        while ret[i][1] > 0:
            cnt += 1
            ret[i][1] -= cnt
            ans += 1
        if ret[i][1] < 0:
            ans -= 1

    print(ans)


if __name__ == '__main__':
    main(sys.stdin.readline, print)
