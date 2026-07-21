from itertools import chain

def swap(head, tail):
    return (tail, head)

s = list(input())
q = int(input())

head = []
tail = []
count = 0

for _i in range(q):
    query = input()
    if query == "1":
        count += 1
        head, tail = swap(head, tail)
    else:
        _n, f, c = tuple(query.split())
        if f == "1":
            head.append(c)
        else:
            tail.append(c)

s = s if count % 2 == 0 else reversed(s)
print("".join(tuple(chain(reversed(head), s, tail))))
