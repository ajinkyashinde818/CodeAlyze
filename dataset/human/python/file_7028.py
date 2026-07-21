from collections import deque
s = list(input())
moji = deque(s)

is_forward = True

q = int(input())
for i in range(q):
    query = input()
    if query[0] == "1":
        is_forward = is_forward ^ 1
    elif query[0] == "2":
        _, f, c = query.split()
        f = int(f)
        f %= 2
        is_end = f ^ is_forward
        if is_end:
            moji.append(c)
        else:
            moji.appendleft(c)

if is_forward == False:
    moji = list(moji)[::-1]
print("".join(moji))
