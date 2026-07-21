from sys import stdin

S = list(stdin.readline().rstrip())
Q = int(stdin.readline().rstrip())

b = [""]
f = [""]

t = 0

for i in range(Q):
    T = stdin.readline().rstrip().split()
    if(len(T) == 1):
        t += 1
        continue
    else :
        F,C = int(T[1]),T[2]

    if t%2 == 0: #反転なし
        if F == 1:
            b.append(C)
        else :
            f.append(C)
    else: #反転あり
        if F == 1:
            f.append(C)
        else :
            b.append(C)



if(t%2 == 0):
    print(''.join(b[::-1] + S + f))
else:
    print(''.join(f[::-1] + S[::-1] + b))
