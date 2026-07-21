from collections import deque
s = input()
li = ['dream', 'dreamer', 'erase', 'eraser']

ans = 'NO'
Q = deque()
Q.append(0)
while True:
    try:
        k = Q.popleft()
    except:
        break
    if k == len(s):
        ans = 'YES'
        break
    for a in li:
        if a == s[k: k + len(a)]:
            Q.append(k + len(a))

print(ans)
