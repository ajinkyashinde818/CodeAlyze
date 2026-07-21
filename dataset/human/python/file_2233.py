import numpy as np

D, G, *pc = map(int, open(0).read().split())
pc = list(zip(*[iter(pc)]*2))
p, c = np.array([]), np.array([])
for (x,y) in pc:
    p = np.append(p, x)
    c = np.append(c, y)
    
import numpy as np
import math

base_points = np.array([i*100 for i in range(1, D+1)])

ans = []

for i in range(2**D):
    bit_flag = np.array(list(map(int, format(i, '0%db' %D))))
    points = sum(bit_flag * (c + p*base_points))
    solved_num = sum(bit_flag * p)
    
    if points >= G:
        ans.append(solved_num)

    else:
        remained = G - points
        remained_problems = sorted((bit_flag==False) * np.array(range(1, D+1)), reverse=True)
        i = 0

        while True:
            if remained <= 0:
                break
                
            highest_p = remained_problems[i]

            if math.ceil(remained / (highest_p * 100)) <= p[highest_p - 1]:
                solved_num += math.ceil(remained / (highest_p * 100))
                remained -= (math.ceil(remained / (highest_p * 100)) * highest_p * 100)
            else:
                solved_num += p[highest_p - 1]
                remained -= (highest_p * 100 * p[highest_p - 1] + c[highest_p - 1])
                i += 1

        ans.append(solved_num)
        
print(int(min(ans)))
