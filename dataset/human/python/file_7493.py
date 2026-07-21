from collections import deque

s = input()
q = int(input())

ans = deque(s)
rev = False

for _ in range(q):
    t = list(input().split())
    if t[0] == '1':
        rev = not rev
    elif t[0] == '2':
        if rev == False:
            if t[1] == '1':
                ans.appendleft(t[2])
            else:
                ans.append(t[2])
        else: # rev = Trueのとき
            if t[1] == '1':
                ans.append(t[2])
            else:
                ans.appendleft(t[2])

result = ''.join(ans)
if rev == True:
    result = result[::-1]

print(result)
