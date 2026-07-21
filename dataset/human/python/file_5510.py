def ii():return int(input())
def iim():return map(int,input().split())
def iil():return list(map(int,input().split()))
def ism():return map(str,input().split())
def isl():return list(map(str,input().split()))

x,y = ism()

if x<y:
    print('<')
elif y<x:
    print('>')
else:
    print('=')
