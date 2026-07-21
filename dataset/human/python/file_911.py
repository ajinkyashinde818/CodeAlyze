n, c = map(int, input().split())
sushi = []
for i in range(n):
    x, v = map(int, input().split())
    sushi.append((x, v))
sushi.sort()
sushi_reversed = list(reversed([(c - x, v) for x, v in sushi]))


def accum_max(s):
    v = 0
    res = [(0, 0)]
    for x_i, v_i in s:
        v += v_i
        res.append(max(res[-1], (v-x_i, x_i)))
    return res[1:]


max_sushi = accum_max(sushi)
max_sushi_reversed = accum_max(sushi_reversed)


def solve(s, msr):
    v_max = 0
    v_2d_max = 0
    v = 0
    n = len(s)
    for i in range(n-1):
        x_i, v_i = s[i]
        v += v_i
        if v - x_i*2 > v_2d_max:
            v_2d_max = v - x_i*2
            v_sub = msr[n - 2 - i][0]
            v_max = max(v_max, v_2d_max + v_sub)
    return v_max


l = solve(sushi, max_sushi_reversed)
r = solve(sushi_reversed, max_sushi)
print(max(l, r, max_sushi[-1][0], max_sushi_reversed[-1][0]))
