import itertools

s = str(input())
a = list(itertools.permutations(['dream', 'dreamer', 'erase', 'eraser']))

for i in a:
    t = s.replace(i[0], '')
    t = t.replace(i[1], '')
    t = t.replace(i[2], '')
    t = t.replace(i[3], '')
    if not t:
        print('YES')
        exit()

print('NO')
