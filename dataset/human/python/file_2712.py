D,G=map(int,input().split())
problem=[]
compscore=[]
for i in range(0,D):
    p,c=map(int,input().split())
    problem.append(p)
    compscore.append(c)

def condition(num):
    for i in range(0,2**D):
        complete=set([])
        score=0
        solve=0
        for j in range(0,D):
            if i>>j &1 ==1:
                complete.add(j)
                score+=compscore[j]+100*(j+1)*problem[j]
                solve+=problem[j]

        if solve>num:
            continue
        else:
            x=num-solve
            full=set([i for i in range(0,D)])
            nokori=full-complete
            nokori=list(nokori)
            if not nokori:
                return score>=G
            else:
                m=max(nokori)
                if x>=problem[m]:
                    continue
                else:
                    score+=x*100*(m+1)
                    if score>=G:
                        return True

    return False

start=1
end=sum(problem)
while end-start>1:
    test=(end+start)//2
    if condition(test):
        end=test
    else:
        start=test

if condition(start):
    print(start)
else:
    print(end)
