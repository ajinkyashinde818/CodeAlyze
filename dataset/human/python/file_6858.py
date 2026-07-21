s = input()
q = int(input())
left = ""
right = ""


def s_add(r, f):
    if r % 2 == 0:
        if f == 1:
            return True
        else:
            return False
    else:
        if f == 1:
            return False
        else:
            return True


cnt = 0
for _ in range(q):
    query = input()
    if query == "1":
        cnt += 1
    else:
        z, f, c = query.split()
        if s_add(cnt, int(f)):
            left += c
        else:
            right += c

if cnt % 2 == 0:
    print(left[::-1] + s + right)
else:
    print(right[::-1] + s[::-1] + left)
