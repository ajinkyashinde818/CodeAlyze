import sys

input = sys.stdin.readline
N = int(input().strip())
alist = list(map(int,input().strip().split()))
blist = list(map(int,input().strip().split()))
clist = list(map(int,input().strip().split()))

sat = 0
prenum = 10000
for i in range(N):
	num = alist[i]-1
	sat = sat+blist[num]
	if num==prenum+1:
		sat = sat+clist[prenum]

	prenum = num


print(sat)
