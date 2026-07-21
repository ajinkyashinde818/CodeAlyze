N=int(input())
A=[int(i) for i in input().split()]
def CountMinusAndZeroAndMin(lis):#マイナスの個数とabs挿話とabs最小の値を返す
    curmin=1000000000000000
    plussum=0
    minus=0
    for i in lis:
        j=abs(i)
        plussum+=j
        curmin=min(j,curmin)
        if i<0:
           minus+=1
    return(minus,plussum,curmin)
minus,plussum,minabs=CountMinusAndZeroAndMin(A)
if minabs==0 or minus%2==0:
    print(plussum)
else:
    print(plussum-2*minabs)
