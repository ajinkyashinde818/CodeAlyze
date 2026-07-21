n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))

def tarou(n,a,b,c):
	manzoku = b[a[0]-1]
	for i in range (1,n):
		manzoku += b[a[i]-1]
		if a[i]-a[i-1] == 1:
				manzoku += c[a[i]-2]
	print (manzoku)
tarou (n,a,b,c)
