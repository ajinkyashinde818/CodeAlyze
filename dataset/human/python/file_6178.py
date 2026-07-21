def ii():return int(input())
def iim():return map(int,input().split())
def iil():return list(map(int,input().split()))
def ism():return map(str,input().split())
def isl():return list(map(str,input().split()))

a,b,c = iim()

if c <= a+b :
    print(b+c)
else:
    print(a+2*b+1)
