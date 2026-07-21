N=list(range(int(input())))
S=list(input())
S=sorted(S)
answer=0

prev=S[0]
counts = []
counter=0

for k in S:
    if k==prev:
        counter+=1
    else:
        prev=k
        if counter!=0:
            counts.append(1+counter)
        counter=1
if counter!=0:
    counts.append(1+counter)

def soujou(li):
    atai=1
    for j in li:
        atai=j*atai
    return atai

answer=soujou(counts)-1
print(answer%(7+10**9))
