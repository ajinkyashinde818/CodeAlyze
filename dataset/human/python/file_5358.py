import sys
N, M = map(int, input().split())

start = [0] * M
end = [0] * M

s_middle = []
middle_e = []

for m in range(M):
    line = list(map(int, input().split()))
    start[m] = line[0]
    end[m] = line[1]
    
    if start[m] == 1:
        s_middle.append(end[m])
    if end[m] == N:
        middle_e.append(start[m])
        
if not s_middle or not middle_e:
    print('IMPOSSIBLE')
    sys.exit()

if set(s_middle) & set(middle_e):
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
