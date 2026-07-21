from collections import deque
s = input()
q = int(input())

li = [input() for i in range(q)]
k = 0
ans = [s]
ans = deque(ans)

for i in li:
    if i == "1":
        k += 1
    else:
        if (int(i[2]) + k) % 2 == 0:
            ans.append(i[4])
        else:
            ans.appendleft(i[4])

ans = list(ans)
s = "".join(ans)
if k % 2 == 0:
    print(s)
else:
    print(s[::-1])
