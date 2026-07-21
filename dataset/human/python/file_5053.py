N, M = map(int, input().split())
land = [[] for i in range(N)]
for _ in range(M):
    i, j = map(int, input().split())
    land[i - 1].append(j)
def landNumber(i,path):
    for j in range(len(land[i])):
        number=land[i][j]
        if path == 2:
            if number==N:
                print('POSSIBLE')
                exit()
            else:
                continue
        else:
            if len(land[number-1]) == 0:
                continue
            else:
                landNumber(number - 1, path + 1)
    return True

if M == 1:
    print('IMPOSSIBLE')
    exit()
if landNumber(0, 1):
    print('IMPOSSIBLE')
    exit()
