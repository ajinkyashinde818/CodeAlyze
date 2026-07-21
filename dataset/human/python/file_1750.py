import sys
n, m = map(int, input().split())
a_list = sum([input().split() for i in range(n)], [])
b_list = sum([input().split() for i in range(m)], [])
for b in b_list:
    for a in a_list:
        if b not in a:
            print('No')
            sys.exit()
print('Yes')
