def calc(i):
    sum_problems = 0
    for j in range(D):
        if i & (1 << j):
            sum_problems += p[j]
    num_problems[i] = sum_problems

nums=list(map(int,input().split()))
D = nums[0]
G = nums[1]
p = []
c = []

num_problems = [1000] * (1 << D)

for i in range(D):
    nums=list(map(int,input().split()))
    p.append(nums[0])
    c.append(nums[1])


for i in range(1 << D):
    sum_tmp = 0
    
    for j in range(D):
        if i & (1 << j):
            sum_tmp += p[j] * (j + 1) * 100 + c[j]
    
    if sum_tmp >= G:
        calc(i)
        
    else:
        j = D-1
        sum_res = 0
        while j > -1:
            if not (i & (1 << j)):
                for k in range(p[j]):
                    sum_tmp += 100 * (j + 1)
                    sum_res += 1
                    if sum_tmp >= G:
                        break
            j -= 1
            if sum_tmp >= G:
                calc(i)
                num_problems[i] += sum_res
                break
            
print(min(num_problems))
