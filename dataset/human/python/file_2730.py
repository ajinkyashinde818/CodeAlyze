D, G = map(int, input().split())
grid = [[0,0]]#インデックス合わせとく
for i in range(D):
    p,c = map(int, input().split())
    grid.append([p,c])

import itertools
kumi = list(itertools.product([0,1], repeat=D))
anls = []
fans = float('inf')
for item in kumi:
    count = 0
    ans = 0
    k = 0
    score = 0
    for i in item:
        count += 1
        if i == 1:
            score += grid[count][0]*100*count + grid[count][1]
            ans += grid[count][0]
        else:
            k = count

    if G <= score :
        fans = min(fans,ans)
    elif score+(k*100)*(grid[k][0]-1) >= G :
        a = int((G-score)/(k*100))
        if score+a*k*100==G:
            ans += a
        else:
            ans += (a+1)
        fans = min(fans,ans)
if fans != float('inf'):
    fans = int(fans)
print(fans)
