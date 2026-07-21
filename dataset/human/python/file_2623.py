import sys
def input(): return sys.stdin.readline().rstrip()

def main():
    D, G = map(int, input().split())
    pc = [tuple(map(int, input().split())) for _ in range(D)]

    ans = 10 ** 9
    for i in range(2 ** D):
        sum_v = 0
        cnt = 0
        for j, (p, c) in enumerate(pc):
            if i & 1 << j:
                sum_v += (j+1) * 100 * p + c
                cnt += p
        if sum_v >= G:
            if cnt < ans:
                ans = cnt
            continue
        for j, (p, c) in enumerate(pc[::-1]):
            k = D - j
            if (i & 1 << k-1) == 0:
                for _ in range(p):
                    sum_v += k * 100
                    cnt += 1
                    if sum_v >= G:
                        if cnt < ans:
                            ans = cnt
                        break
    print(ans)

if __name__ == '__main__':
    main()
