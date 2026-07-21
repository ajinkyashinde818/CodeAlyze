D,G=list(map(int,input().split()))
l=[list(map(int,input().split())) for i in range(D)]
cnt=0
tmp=0
dep=0
import math
m=set(range(D))
def main(cnt,tmp,dep,m):
   if dep==D:
      if tmp>=G:
         return cnt
      else:
         tmp=G-tmp
         if tmp <= (max(m)+1)*l[max(m)][0]*100:
            cnt+=math.ceil(tmp/((max(m)+1)*100))
            return cnt
         else:
            return float("Inf")
   return(min(main(cnt+l[dep][0],tmp+100*(dep+1)*l[dep][0]+l[dep][1],dep+1,m-{dep}),main(cnt,tmp,dep+1,m))) 
print(main(0,0,0,m))
