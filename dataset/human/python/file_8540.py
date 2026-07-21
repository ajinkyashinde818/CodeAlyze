def II():return int(input())
def MI():return map(int,input().split())
def LI():return list(MI())
def ok():print("Yes")
def ng():print("No");exit()

import numpy
k,n=MI()
a=LI()
a+=(a[0]+k),
a=numpy.diff(a)
print(k-max(a))
