import math

def main3():
    ans = float("inf")
    d, g = map(int, input().split())
    pc = [list(map(int, input().split())) for _ in range(d)]

    for bit in range(1 << d):
        count = 0
        sum = 0
        remain = set(range(d))
        for i in range(d):
            if bit & (1 << i):
                sum += (i + 1) * 100 * pc[i][0] + pc[i][1]
                count += pc[i][0]
                remain -= {i}
        if sum < g:
            q = max(remain)
            n = min(pc[q][0] - 1, math.ceil((g - sum) / (100 * (q + 1))))
            count += n
            sum += 100 * (q + 1) * n
        if sum >= g:
            ans = min(ans, count)
    print(ans)

if __name__ == '__main__':
    main3()
