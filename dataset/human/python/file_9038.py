import sys

s = input()

cand = ['dream', 'dreamer', 'erase', 'eraser']

q = ['']

while len(q) != 0:
    front = q.pop(0)

    for c in cand:
        start = len(front)
        end = len(front) + len(c)
        if end <= len(s) and s[len(front):len(front) + len(c)] == c:
            next_elm = front + c
            if next_elm == s:
                print('YES')
                sys.exit(0)
            q.append(next_elm)

print('NO')
