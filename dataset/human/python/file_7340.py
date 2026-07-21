import sys
import math

s = input()
Q = int(input())
query = []
[query.append(input().split()) for _ in range(Q)]

inversion = -1

if len(s) >= 3:
    head = s[0]
    tail = s[-1]
    body = s[1:-1]
    for i in range(Q):
        if query[i][0] == "1":
            inversion *= -1
            continue

        c = str(query[i][2])
        if query[i][1] == "1" and inversion == -1:
            head = c + head
        elif query[i][1] == "1" and inversion == 1:
            tail = tail + c
        elif query[i][1] == "2" and inversion == -1:
            tail = tail + c
        else:
            head = c + head
        
    if inversion == -1:
        print(head + body + tail)
    else:
        print(tail[::-1] + body[::-1] + head[::-1])

else:
        for i in range(Q):
            if query[i][0] == "1":
                inversion *= -1
                continue

            c = str(query[i][2])
            if query[i][1] == "1" and inversion == -1:
                s = c + s
            elif query[i][1] == "1" and inversion == 1:
                s = s + c
            elif query[i][1] == "2" and inversion == -1:
                s = s + c
            else:
                s = c + s
        
        if inversion == -1 :
            print(s)
        else:
            print(s[::-1])
