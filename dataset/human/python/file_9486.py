N,K=map(int,input().split())
A=list(map(int,input().split()))

flag=0
def woap(current_city,li,K):
    global flag
    next_city=li[current_city]-1
    if trace[next_city]!=-1 and trace[next_city]!=K:
        flag=1
        return current_city
    else:
        trace[next_city]=K
        return next_city

def woap2(current_city,li):
    next_city=li[current_city]-1
    return next_city

trace=[-1]*N
trace[0]=0
rest=K
current_city=0
for i in range(1,K+1):
    current_city=woap(current_city,A,i)
    if flag==1:
        break
    else:
        rest-=1


loop_length=K-rest-trace[A[current_city]-1]+1
amari=rest%loop_length
for i in range(amari):
    current_city=woap2(current_city,A)

print(current_city+1)
