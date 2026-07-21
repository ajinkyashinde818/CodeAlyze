import sys

data=input().split(' ')
k=int(data[0])
data_1sub=k+1
s=int(data[1])
d=0
e=0
for i in range(data_1sub):
    for j in range(data_1sub):
        d=s-i-j
        if (0 <= d) and (d <= k):
            e=e+1
        else:
            pass
print(e)
