def getAB(r,books,N):
     if r==0:
         return(books[2*r],books[2*(N+r)])
     elif r==N:
         return(books[2*r-1],books[2*(N+r)-1])
     elif r==N+1:
         return (1,0)
     else:
         return(books[2*r-1]|books[2*r],books[2*(N+r)-1]|books[2*(N+r)])
         
#def getcostandarray(A,B,array,r,books):
#    if array==0:
#        if B:
#            return(3,2)
#        elif A:
#            nextB=getAB(r+1,books,N)[1]
#            if nextB:
#                return (2,1)
#            else:
#                return(2,0)
#        else:
#            return (1,0)
#    elif array==2:
#        if A:
#            return(3,0)
#        elif B:
#            nextB=getAB(r+1,books,N)[1]
#            if nextB:
#                return (2,2)
#            else:
#                return(2,1)
#        else:
#            return (1,2)
#    else:
#        if A==0 and B==0:
#            return (1,1)
#        elif A==1 and B==0:
#            return (2,0)
#        elif B==1 and A==0:
#            return (2,2)
#        else:
#            nextA=getAB(r+1,books,N)[0]
#            if nextA:
#                return (4,0)
#            else:
#                return (4,2)


Q=int(raw_input())
for i in range(Q):
    N=int(raw_input())
    books=[1 if x=='Y' else 0 for x in raw_input()]
    array=0
    Alist=[]
    Blist=[]
    firstB=-1
    lastB=-1
    for i in range(N+1):
        (A,B)=getAB(i,books,N)
        Alist.append(A)
        Blist.append(B)
        if B:
            if firstB==-1:
                firstB=i
            lastB=i
    if firstB!=-1:
        if 1 not in Alist[:firstB+1]:
            Alist[firstB]=1
        if 1 not in Alist[lastB:]:
            Alist[lastB]=1
    totalcost=N+sum(Alist)+sum(Blist)
        #(cost,array)=getcostandarray(A,B,array,i,books)
        #totalcost=totalcost+cost
        #print (A,B),(cost,array)
    #totalcost=totalcost+array
    print totalcost
