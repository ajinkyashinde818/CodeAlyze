from sys import stdin

N = stdin.readline().rstrip()
ans = 0

N = N[::-1]
N = N + '0'
kuriagari = 0

for i in range(len(N)):
    r = int(N[i])
    if kuriagari == 1:
        r += 1
    if 10 - r < r:
        kuriagari = 1
    else:
        kuriagari = 0
    if r == 5 and int(N[i + 1]) > 4:
        kuriagari = 1
    if r == 10:
        r = 0
    ans += min(r, 10 - r)

print(ans)
