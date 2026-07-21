import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

def myinput():
    return map(int,readline().split())

d,g = myinput()

pc = [ list(myinput()) for _ in range(d) ]

import copy
pc2 = copy.deepcopy(pc)

# print(d,g)
# print(pc)
# print(pc2)

ls_count = []

for i in range(2**d):
    pt = 0
    count = 0
    ls = []
    # print("\ni={}".format(i))
    for j in range(d):
        if i & (2**j):
            pt = pt + 100*(j+1)*pc[j][0] + pc[j][1]
            count += pc[j][0]
        else:
            ls.append(j)
    # print(ls)
    if pt>=g:
        ls_count.append(count)
    else:
        r = g - pt
        while r>0:
            if len(ls)!=0:
                j = max(ls)
                if pc2[j][0]>=1:
                    r -= 100*(j+1)
                    pc2[j][0] -= 1
                    count += 1
                else:
                    count += float("inf")
                    break
        ls_count.append(count)
# print(ls_count)
ans = min(ls_count)
print(ans)
