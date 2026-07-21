D, G= map(int, input().split())
p=[]
c=[]
for i in range(D):
    pi, ci= map(int, input().split())
    p.append(pi)
    c.append(ci)

ans=10000000000
slis=[]
def dfs(i,point,pr):
    global ans
    global slis
    if i==D:
#        print(point)
#        print(slis)
        if G<=point:
            ans=min(ans,pr)
        else:
            for j in range(D-1,-1,-1):
                if slis[j]==0:
                    k=j
                    break
            
#            print('G-point:',G-point)
#            print('(100*(k+1)*(p[k]-1)):',(100*(k+1)*(p[k]-1)))
            if (G-point)<=(100*(k+1)*(p[k]-1)):
                pr+=-(-(G-point)//(100*(k+1)))
                ans=min(ans,pr)
#                print('ans:',ans)


#            if umax!=-1 and (G-point)<(100*(umax+1)*(p[umax]-1)):
        
        return
    #全て解かない
    slis.append(0)
    dfs(i+1,point,pr)
    slis.pop(-1)
    #全て解く
    slis.append(1)
    dfs(i+1,point+(100*(i+1)*p[i]+c[i]),pr+p[i])
    slis.pop(-1)
dfs(0,0,0)
print(ans)
