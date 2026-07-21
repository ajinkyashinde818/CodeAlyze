tn = []
tm = []

def check(d):
    for h in range(d + 1):
        for w in range(d + 1):
            mw = len(tm)
            result = True
            for tmh in range(mw):
                row = tn[h + tmh][w:w + mw]
                if row != tm[tmh]:
                    result = False
                    break

            if result:
                return True

    return False

N, M = list(map(int, input().rstrip().split()))
for i in range(N):
    tn.append(list(input().rstrip()))

for i in range(M):
    tm.append(list(input().rstrip()))

d = N - M

print('Yes' if check(d) else 'No')
