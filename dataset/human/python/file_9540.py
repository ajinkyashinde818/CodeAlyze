import sys


def input():
    return sys.stdin.readline().strip()


def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    went = [0] * N
    went[0] = 1
    Flag = True
    check = [0]
    cnt = 1
    now = 0
    while Flag and (cnt <= K + 1):
        now = A[now] - 1
        if went[now] == 1:
            ind = check.index(now)
            if ind == 0:
                cnt = len(check)
            else:
                cnt = len(check) - ind

            Flag = False
        else:
            check.append(now)
            went[now] = 1
            cnt += 1
            continue

    if len(check) > K:
        print(check[K] + 1)
    else:
        if ind == 0:
            K = K % cnt
            print(check[K] + 1)
        else:
            ind -= 1
            K = (K - ind - 1) % cnt
            print(check[ind + K + 1] + 1)


if __name__ == "__main__":
    main()
