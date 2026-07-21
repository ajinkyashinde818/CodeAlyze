import sys
from collections import deque
s = input()

queue = deque()
queue.append(0)
candidates = ['dream', 'dreamer', 'erase', 'eraser']

index = 0
while queue:
    index = queue.popleft()
    match = False
    for candidate in candidates:
        if s[index:index + len(candidate)] == candidate:
            match = True
            if index + len(candidate) == len(s):
                print('YES')
                sys.exit(0)
            queue.append(index + len(candidate))
print('NO')
