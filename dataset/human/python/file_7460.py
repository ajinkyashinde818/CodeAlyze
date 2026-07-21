from collections import deque
S = deque(input())
Q = int(input())
reverse_count = 0
for i in range(Q):
    Q_i = list(input().split())
    if Q_i[0] == "1":
        reverse_count += 1
    elif ((Q_i[1] == "1" and reverse_count % 2 == 0) or
          (Q_i[1] == "2" and reverse_count % 2 == 1)):
        S.appendleft(Q_i[2])
    else:
        S.append(Q_i[2])
if reverse_count%2==1:
    S.reverse()
print("".join(S))
