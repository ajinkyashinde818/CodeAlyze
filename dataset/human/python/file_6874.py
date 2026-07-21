import collections

S = input()
Q = int(input())

rev = False
deque = collections.deque()
for c in S:
    deque.append(c)
for _ in range(Q):
    read = input()
    if read == '1':
        rev = not rev
    else:
        _, f, c = read.split()
        if not rev:
            if f == '1':
                deque.appendleft(c)
            else:
                deque.append(c)
        else:
            if f == '1':
                deque.append(c)
            else:
                deque.appendleft(c)

ret = ''.join(deque if not rev else reversed(deque))
print(ret)
