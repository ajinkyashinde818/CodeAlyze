from collections import deque
import sys

input=sys.stdin.readline

S=input().rstrip()

string = deque([S[i] for i in range(len(S))])

reverse = False

for _ in range(int(input())):
    q = input().rstrip().split()

    if q[0] == "1":
        reverse = not reverse

    else:
        if q[1] == "1":
            if reverse:
                string.append(q[2])
            else:
                string.appendleft(q[2])

        else:
            if reverse:
                string.appendleft(q[2])
            else:
                string.append(q[2])

string = list(string)

if reverse:
    string = string[::-1]

print("".join(string))
