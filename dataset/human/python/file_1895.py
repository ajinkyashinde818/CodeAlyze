import sys

n,m = map(int,input().split())

a_list = [[l for l in input()] for _ in range(n)]
b_list = [[l for l in input()] for _ in range(m)]

if n == m:
    if a_list == b_list:
        print('Yes')
        sys.exit()

for i in range(n-m):
    for j in range(n-m):
        a_list_sub = a_list.copy()
        a_list_sub = a_list[i:i+m]
        a_list2 = [row[j:j+m] for row in a_list_sub]
        if a_list2 == b_list:
            print('Yes')
            sys.exit()

print('No')
