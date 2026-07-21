def C():
    kn=list(map(int,input().split()))
    A=list(map(int,input().split()))
    d=[]
    sum_ans=[]
   
    for i in range(kn[1]):
        
        if i==kn[1]-1:
            d.append(kn[0]-A[i])
        else:
            d.append(A[i+1]-A[i])
        
        
    sum_ans.append(A[kn[1]-1]-A[0])
    for i in range(1,kn[1]):
        sum_ans.append(min(kn[0]-d[i],kn[0]-d[i-1]))
    
    print(min(sum_ans))    
        
    
if __name__=='__main__':
    C()
