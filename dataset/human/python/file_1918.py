import sys
n, m = map(int, input().split())
a_list = [input() for _ in range(n)]
b_list = [input() for _ in range(m)]

for i in range(n-m+1):
    for j in range(n-m+1):
        new_list = [a_list[k][j:j+m] for k in range(i,i+m)]
        if(new_list == b_list):
            print('Yes')
            sys.exit()
print('No')
