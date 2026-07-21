S = input()
Q = int(input())
query = []
for i in range(Q):
    query.append(list(map(str, input().split())))


def start(S, x):
    S = x + S
    return S


def end(S, x):
    S = S + x
    return S


front = ''
back = ''
flg = True
for q in query:
    if len(q) == 1:
        flg = not flg
    else:
        if flg == True:
            if q[1] == '1':
                front = start(front, q[2])
            else:
                back = end(back, q[2])
        else:
            if q[1] == '1':
                back = end(back, q[2])
            else:
                front = start(front, q[2])
else:
    if flg == True:
        print(front + S + back)
    else:
        print(back[::-1] + S[::-1] + front[::-1])
