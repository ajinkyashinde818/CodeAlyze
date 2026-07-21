import collections
s = input()
head = []
tail = []
is_reveresed = False
q = int(input())
for i in range(q):
    query = input()
    if query[0] == '1':
        is_reveresed = not is_reveresed
    else:
        f = query[2]
        c = query[4]
        if is_reveresed:
            if f == '1':
                tail.append(c)
            else:
                head.append(c)
        else:
            if f == '1':
                head.append(c)
            else:
                tail.append(c)
if is_reveresed:
    print('{}{}{}'.format(''.join(tail[::-1]), s[::-1], ''.join(head)))
else:
    print('{}{}{}'.format(''.join(head[::-1]), s, ''.join(tail)))
