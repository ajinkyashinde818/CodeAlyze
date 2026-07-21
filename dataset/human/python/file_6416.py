import math
n = input()
n = int(n)
summ=0
count = 0
if(n%2==1): print("0")
else:
    while(n/5>0):
        if(count==0): 
            n=str(n)
            n=n[0:len(n)-1]
            if(len(n)==0): break
            else: n=int(n) 
            count+=1
        else:
            n = n*2
            n=str(n)
            n=n[0:len(n)-1]
            if(len(n)==0): break
            else: n=int(n)            
        #print("n="+str(n))
        summ+=n
    print(summ)
#12499999999999996
#1000000000000000000
#100000000000000010
# 99999999999999990
