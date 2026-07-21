import sys
input = sys.stdin.readline

def solve(N):
    res = 0
    flg = 0
    for n in reversed(N):
        if flg == 2:
            if n >= 5:
                flg = 1
            else:
                flg = 0
        m = flg + n
        if m == 5:
            res += 5
            flg = 2
        elif m < 5:
            res += m
            flg = 0
        else:
            res += (10 - m)
            flg = 1
    return res + flg%2


N = list(map(int, input().strip()))
print(solve(N))

# N = 1
# q = 0
# while True:
#     p = solve(list(map(int, str(N))))
#     if abs(p-q) > 1:
#         print(N, "OK")
#         exit()
#     q = p
#     N += 1
