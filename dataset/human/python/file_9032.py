import itertools

s = input()
t_list = ['dreamer', 'dream', 'eraser', 'erase']

flg = False
for t in list(itertools.permutations(t_list)):
    s_tmp = s
    for _t in t:
        s_tmp = s_tmp.replace(_t, '')
    if len(s_tmp) == 0:
        print('YES')
        flg = True
        break

if not flg:
    print('NO')
