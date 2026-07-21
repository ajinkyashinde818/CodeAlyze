from collections import deque
s = input()
Q = int(input())

SS =deque(list(s))
rev_count = 0

for i in range(Q):
    que = input()
    if que[0] == '1':
        rev_count +=1
    elif que[0] == '2':
        if (rev_count + int(que[2]))%2 == 0:
            SS.append(que[4])
        else:
            SS.appendleft(que[4])

print("".join(SS) if rev_count %2 == 0 else ("".join(SS))[-1::-1])
