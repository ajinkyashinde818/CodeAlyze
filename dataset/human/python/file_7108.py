import sys

S = input()

Q = int(input())
flag=0
mae = ''
matsu = ''

for i in range(Q):
    r = sys.stdin.readline().rstrip('\n')
    if r == '1':
        flag = 1 - flag
    else:
        ni, f, c = r.split()
        if f=='1':
            if flag == 0:
                mae += c
            else:
                matsu += c
        else:
            if flag == 0:
                matsu += c
            else:
                mae += c


if flag ==0:
    print(mae[::-1]+S+matsu)
else:
    print(matsu[::-1]+S[::-1]+mae)
