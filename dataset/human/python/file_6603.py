from collections import deque
s = input()
q = int(input())
S = [c for c in s]
deque = deque(S)
reversed = 0
for i in range(q):
    line = input()
    if line[0] == '1':
        reversed = reversed ^ 1
    else:
        op, f, c = line.split()
        f = int(f)
        if reversed == 0:
            if f == 1:
                deque.appendleft(c)
            else:
                deque.append(c)
        else:
            if f == 1:
                deque.append(c)
            else:
                deque.appendleft(c)
if reversed:
    deque.reverse()
result = "".join(deque)
print(result)
