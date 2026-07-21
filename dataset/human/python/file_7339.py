import sys
input = sys.stdin.readline
S = input().strip()
Q = int(input())
f = 0
add = ['', '']
for q in range(Q):
    query = input().strip()
    if query == '1':
        f ^= 1 
    else:
        _, F, C = query.split(' ')
        add[int(F)-1^f] += C
print(''.join([add[f][::-1], S[::(f*-1*2)+1], add[f*-1+1]]))
