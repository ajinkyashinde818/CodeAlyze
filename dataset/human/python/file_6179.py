import math



def nCast(number):
    if type(number)==str:
        return int(number)
    for idx in range(0,len(number)):
        if type(number[idx])==str:

            number[idx]=int(number[idx])
        else:
            nCast(number[idx])
    return number
    
def inputArr(w):
    l=list()
    for idx in range(0,w):
        l.append(input().split())
    return l

a=nCast(input().split())
if a[2]>a[0]+a[1]:
    a[2]=a[0]+a[1]+1

print(a[1]+a[2])
