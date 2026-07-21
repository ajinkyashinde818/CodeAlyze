from sys import exit
N,K = map(int,input().split())
town = [None]+list(map(int,input().split()))

flag = [None]+[0]*N
remain = K
piece = 1
cnt = 1
while remain > 0:
    if flag[town[piece]] != 0:
        q = cnt-flag[town[piece]]
        piece = town[piece]
        remain -= 1
        break
    else:
        piece = town[piece]
        flag[piece] = cnt
        remain -= 1
        cnt += 1

if remain == 0:
    print(piece)
    exit(0)

remain %= q

while remain > 0:
    piece = town[piece]
    remain -= 1

print(piece)
