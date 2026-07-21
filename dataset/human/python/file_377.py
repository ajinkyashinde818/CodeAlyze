import numpy as np

def spaceinput():
    return list(map(int,input().split(" ")))
    
N=int(input())
a=np.array(spaceinput())


cnt_minus=0
cnt_zero=0
for sa in a:
    if sa==0:
        cnt_zero+=1
    if sa<0:
        cnt_minus+=1


a_abs=np.abs(a)
suma=np.sum(a_abs)


if cnt_minus%2==0 or cnt_zero>0:
    res=suma
else:
    res=suma-2*np.min(a_abs)

print(res)
