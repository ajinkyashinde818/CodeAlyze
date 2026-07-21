from collections import deque

def main():
    N,K=map(int,input().split())

    A=list(map(lambda x:int(x)-1,input().split()))
    FootPrintA=A[:]

    loop=[]

    slack_que=deque([])
    flag=0
    t=0
    start=0
    while flag==0:
        slack_que.append(t)
        t_ = FootPrintA[t]
        FootPrintA[t]=-1
        if t_==-1:
            start=slack_que.index(t)
            flag=1
            slack_que.pop()
        t = A[t]

    slack=list(slack_que)
    slack_num=start
    loop_num=len(slack)-slack_num

    # print(slack)
    # print(start)
    # print(slack_num)
    # print(loop_num)
    #
    loop=slack[start:]
    # print(loop)
    if (K-slack_num)<0:
        res=slack[K]+1
    else:
        tele_num=((K-slack_num)%loop_num)
        town=loop[tele_num]
        res=town+1

    print(res)

if __name__=="__main__":
    main()
