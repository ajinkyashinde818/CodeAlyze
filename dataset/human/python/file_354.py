N = int(input())
A = list(map(int, input().split()))

nums = A[:]
import math

gcd_queue = [
    (0, nums[0]),
]
for n in nums[1:]:
    tmp_queue = []
    for q in gcd_queue:
        tmp_queue.append((q[0] + q[1], n))
        tmp_queue.append((q[0] + q[1]*-1, n*-1))
    gcd_queue = set(tmp_queue[:])
    #print(gcd_queue)
    tmp = {}
    for q in gcd_queue:
        if str(q[1]) in tmp:
            tmp[str(q[1])] = max(q[0], tmp[str(q[1])])
        else:
            tmp[str(q[1])] = q[0]
    #print(tmp)
    gcd_queue = []
    for k, v in tmp.items():
        #print(k, v)
        gcd_queue.append((v, int(k)))
    

gcd_queue = list(gcd_queue)
ans = gcd_queue[0][0] + gcd_queue[0][1]
for q in gcd_queue:
    ans = max(ans, q[0]+q[1])
print(ans)
