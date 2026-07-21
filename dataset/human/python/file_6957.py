from collections import deque

S = input()
Q = int(input())
ARR = []

for i in range(Q):
    arr = input().split(" ")
    ARR.append(arr)


def calculate(s,q,arr):
    s = deque(list(s))

    kk = 0
    for ar in arr:
        if int(ar[0]) == 1:
            kk = kk + 1
        if int(ar[0]) == 2:
            if int(ar[1]) == 1:
                if kk % 2 == 0:
                    s.appendleft(ar[2])
                else:
                    s.append(ar[2])
            else:
                if kk % 2 == 0:
                    s.append(ar[2])
                else:
                    s.appendleft(ar[2])

    if kk % 2 == 1:
        s.reverse()

    print("".join(list(s)))

calculate(S,Q,ARR)
