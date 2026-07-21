import sys

def main():
    sum=0
    ans=0
    ansc=0
    D,G = map(int,input().split())

    lis=[]
    for x in range(D):
        P,C = map(int,input().split())
        lis.append([P,C])

    op_cnt = D

    for i in range(2 ** op_cnt):
        for j in range(op_cnt):
            if((i>>j) & 1 and i!=0):
                for k in range(1, lis[j][0]+1):
                    sum+=(100*(j+1))
                    ansc+=1
                    if(k==lis[j][0]):
                        sum+=lis[j][1]
                    if(sum>=G):
                        break


        if(sum<G):
            for lef in reversed(range(0, op_cnt)):
                if(~(i>>lef) & 1 and lis[lef][0] != 1):
                    for l in range(1,lis[lef][0]+1):
                        if(sum>=G):
                            break
                        sum+=(100*(lef+1))
                        ansc+=1


        if(ans>=ansc or ans==0):
            ans=ansc

        ansc=0
        sum=0

    print(ans)
main()
