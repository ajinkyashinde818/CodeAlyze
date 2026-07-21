import math

n = int(input())
s = input()
s2 = list(s)

if s[0] == 'B':
    s2[0] = 'L'
else:
    s2[0] = 'R'

for i in range(1,2*n): 
    if s[i-1] == s[i]:
        if s2[i-1] == 'L':
            s2[i] = 'R'
        else:
            s2[i] = 'L'
    else:
        if s2[i-1] == 'L':
            s2[i] = 'L'
        else:
            s2[i] = 'R'
        
if s2[0] == 'R' or s2[2*n-1] == 'L' or s2.count('L') != s2.count('R'):
    print(0)
    exit()
            
ans = 1
count_l = 0
for s2_str in s2: 
    if s2_str == 'L':
        count_l += 1
    else:
        ans *= count_l
        ans %= 10**9 + 7
        count_l -= 1
    
print(ans * math.factorial(n) % (10**9 + 7))
