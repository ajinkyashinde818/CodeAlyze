import re
n,m=map(int,input().split())
a=" ".join([input().replace(".","o") for i in [0]*n])
b=("."*(n-m+1)).join([input().replace(".","o") for i in [0]*m])
if re.search(b,a):
    print("Yes")
else:
    print("No")
