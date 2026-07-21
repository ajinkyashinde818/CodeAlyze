import sys

n, m = map(int, input().split())
a_array = [input() for i in range(n)]
b_array = [input() for i in range(m)]

for ai in range(n-m+1):
    for aj in range(n-m+1):
        can = True
        for bi in range(m):
            if a_array[ai+bi][aj:aj+m] != b_array[bi]:
                can = False
                break
        if can:
            print('Yes')
            sys.exit()

print('No')
