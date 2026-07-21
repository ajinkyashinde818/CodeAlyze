import numpy as np
row = list(map(int, input().split()))
row2 = [input().split() for i in range(row[0])]
f = np.vectorize(int)
p = f(row2)
ans = 10*100
for bit in range(1<<row[0]):
    sum = 0
    max_rest = 0
    num = 0
    for i in range(row[0]):
        if bit & (1<<i):
            
            sum += 100*(i+1) * p[i][0] + p[i][1]
            num += p[i][0]
        else:
            max_rest = i
    for j in range(p[max_rest][0]):
        if sum < row[1]:
            sum += 100*(max_rest+1)
            num += 1
        else:
            if num < ans:
                ans = num
            break
    
print(ans)
