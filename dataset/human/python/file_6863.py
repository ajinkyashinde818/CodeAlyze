from collections import deque

def iin(): return int(input())
def iln(): return list(map(int, input().split()))


S = input()

queue = deque()
for c in S:
    queue.append(c)

is_reversed = False

QN = iin()

for i in range(QN):
    operation = input().split()
    if len(operation) == 1:
        is_reversed = not is_reversed
    else:
        _, op, new_char = operation
        if op == "1":
            # append to head
            if is_reversed:
                queue.append(new_char)
            else:
                queue.appendleft(new_char)
        else:
            # append to tail
            if is_reversed:
                queue.appendleft(new_char)
            else:
                queue.append(new_char)

if is_reversed:
    print("".join(reversed(queue)))
else:
    print("".join(queue))
