from collections import deque

s = input()
q = int(input())
d = deque(s)
reverseFlag = False


def getQuery():
    yield input().split()


for _ in range(q):
    for query in getQuery():
        if query[0] == "1":
            reverseFlag = not reverseFlag
        else:
            if query[1] == "1":
                if reverseFlag:
                    d.append(query[2])
                else:
                    d.appendleft(query[2])
            else:
                if reverseFlag:
                    d.appendleft(query[2])
                else:
                    d.append(query[2])

ans = "".join(d)
if reverseFlag:
    ans = ans[::-1]

print(ans)
