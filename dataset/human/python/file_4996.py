import sys
for line in sys.stdin:
    p = list(map(int, line.split()))
    car = [4, 1, 4, 1, 2, 1, 2, 1, 4, 1, 4, 1, 2, 1, 2, 1]
    ans_d = 10**9
    ans = -1
    for i in range(8):
        now_d = 0
        for j in range(8):
            now_d += abs(p[j] - car[i+j])
        if ans_d > now_d:
            ans_d = now_d
            ans = car[i:i+8]
        elif ans_d == now_d:
            ans_s, now_s = '', ''
            for k in ans:
                ans_s += str(k)
            for k in car[i:i+8]:
                now_s += str(k)
            if int(ans_s) > int(now_s):
                ans_d = now_d
                ans = car[i:i+8]
    t = ''
    for i in ans:
        t += str(i) + ' '
    print(t[:-1])
