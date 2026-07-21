def ii():return int(input())
def iim():return map(int,input().split())
def iil():return list(map(int,input().split()))
def ism():return map(str,input().split())
def isl():return list(map(str,input().split()))

#pythonだとTLE/pypyだとAC
'''
r,g,b,n = iim()
ans = 0
for i in range(n//r+1):
    for j in range(n//g+1):
        num = n-i*r-j*g
        if num%b == 0 and num//b >= 0:
#            print(i,j,num//b)
            ans += 1
print(ans)
'''

#上を受けてpythonでも通るように改良
*num,n = iim()
a,b,c = map(int,sorted(num))
ans = 0
for i in range(n//c+1):
    if a!= 1:
        for j in range(n//b+1):
            num = n-i*c-j*b
            if num%a == 0 and num//a >= 0:
                ans += 1
    else:
        ret = n - i*c
        ans += ret//b+1
print(ans)
