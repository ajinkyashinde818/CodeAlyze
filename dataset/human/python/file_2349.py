D,G=map(int,input().strip().split())
pc=[]
for _ in range(D):
    pc.append(list(map(int,input().strip().split())))
    
min_num=0
for i in range(D):
    min_num+=pc[i][0]

def dfs(l,D,G):
    global min_num
    score=0
    num=0
    if len(l)==D:
        for n in range(len(l)):
            if l[n]==1:
                score+=pc[n][0]*100*(n+1)+pc[n][1]
                num+=pc[n][0]
        if score>=G:
            min_num=min(min_num,num)
        else:
            for n in reversed(range(len(l))):
                if l[n]==0:
                    i=0
                    while i<=pc[n][0]-1 and score<G:
                        score+=100*(n+1)
                        num+=1
                        i+=1
                    if score>=G:
                        break
            min_num=min(min_num,num)
        return
    else:
        for n in range(2):
            l.append(n)
            dfs(l,D,G)
            l.pop()
dfs([],D,G)
print(min_num)
