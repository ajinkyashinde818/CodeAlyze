from collections import deque
s = input()
q = int(input())
result_q = deque(s)
t = False
for _ in range(q):
    List=[i for i in input().split()]
    if List[0] == '1':
        if t:
            t = False
        else:
            t = True
    else:
        if List[1] == '1': # F=1
            if t: # 反転時
                result_q.append(List[2])
            else:
                result_q.appendleft(List[2])
        else:
            if t: # 反転時
                result_q.appendleft(List[2])
            else:
                result_q.append(List[2])
if t:
    result_q.reverse()
for s in list(result_q):
    print(s, end="")
