INT_MAX=10**18+7
x=10**9+7
def INPUT():return list(int(i) for i in input().split())
def LIST_1D_ARRAY(n):return [0 for _ in range(n)]
def LIST_2D_ARRAY(m,n):return [[0 for _ in range(n)]for _ in range(m)]
GETA=123
###############################################################################
n,r=INPUT()
if n>=10:
    print(r)
else:
    print(r+100*(10-n))
