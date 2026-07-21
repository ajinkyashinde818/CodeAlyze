import itertools
S = input()
L = ["dreamer", "eraser", "erase", "dream"]
R = list(itertools.permutations(L))
flag=0
for sg in R:
    T=S
    for i in range(4):
        T=T.replace(sg[i], "")
    if T=="":
        flag=1
        break
if flag==1:
    print("YES")
else:
    print("NO")
