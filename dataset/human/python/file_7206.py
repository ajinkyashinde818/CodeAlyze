from collections import deque
s = input()
n = int(input())
query = []
for i in range(n):
    query.append(input().split())
cond = 1
word = deque(s)
for i in range(n):
    if query[i] == ['1']:
        cond *= -1
    else:
        if cond == 1:
            if query[i][1] == '1':
                word.appendleft(query[i][2])
            else:
                word.append(query[i][2])
        else:
            if query[i][1] == '2':
                word.appendleft(query[i][2])
            else:
                word.append(query[i][2])

result = ''.join(word)
if cond == -1:
    result = result[::-1]
print(result)
