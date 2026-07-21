def solve(A,B):
    i = 0
    j = 0


    C = defaultdict(list)
    D = [0]*len(B)
    flagA = -1
    flagB = -1
    while i<len(A) and j<len(B):
        if A[i][0] == B[j][0]:
            if i==len(A)-1:
                if j==len(B)-1:
                    break
                j+=1
                flagB = j-1
            else:
                i+=1
                flagA = i-1
        while len(C[A[i][0]]) < A[i][1] and D[j] < B[j][1]:
            C[A[i][0]].append(str(B[j][0]))
            D[j] += 1
        if D[j] == B[j][1]:
            if flagA>=0:
                i=flagA
                flagA = -1
            j+=1    
        else:
            if flagB>=0:
                j=flagB
                flagB = -1
            i+=1
        #print(D)
        #print(i,j)
        #print(flagA,flagB)
    return C,D


from collections import Counter,defaultdict

N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

A = Counter(A)
B = Counter(B)

A = [(c,A[c]) for c in A]
B = [(c,B[c]) for c in B]

A.sort(key = lambda x:x[1])
B.sort(key = lambda x:x[1])

i = 0
j = 0


C = defaultdict(list)
D = [0]*len(B)
flagA = -1
flagB = -1
while i<len(A) and j<len(B):
    if A[i][0] == B[j][0]:
        if i==len(A)-1:
            if j==len(B)-1:
                break
            j+=1
            flagB = j-1
        else:
            i+=1
            flagA = i-1
    while len(C[A[i][0]]) < A[i][1] and D[j] < B[j][1]:
        C[A[i][0]].append(str(B[j][0]))
        D[j] += 1
    if D[j] == B[j][1]:
        if flagA>=0:
            i=flagA
            flagA = -1
        j+=1    
    else:
        if flagB>=0:
            j=flagB
            flagB = -1
        i+=1
    #print(D)
    #print(i,j)
    #print(flagA,flagB)

if sum(D)==N:
    print("Yes")
    E = [(c," ".join(C[c])) for c in C]
    #print(E)
    E.sort(key = lambda x: x[0])
    E = [e[1] for e in E]
    print(*E)
else:
    A.sort(key = lambda x:x[1],reverse=True)
    B.sort(key = lambda x:x[1],reverse=True)

    i = 0
    j = 0


    C = defaultdict(list)
    D = [0]*len(B)
    flagA = -1
    flagB = -1
    while i<len(A) and j<len(B):
        if A[i][0] == B[j][0]:
            if i==len(A)-1:
                if j==len(B)-1:
                    break
                j+=1
                flagB = j-1
            else:
                i+=1
                flagA = i-1
        while len(C[A[i][0]]) < A[i][1] and D[j] < B[j][1]:
            C[A[i][0]].append(str(B[j][0]))
            D[j] += 1
        if D[j] == B[j][1]:
            if flagA>=0:
                i=flagA
                flagA = -1
            j+=1    
        else:
            if flagB>=0:
                j=flagB
                flagB = -1
            i+=1
        #print(D)
        #print(i,j)
        #print(flagA,flagB)
    if sum(D)==N:
        print("Yes")
        E = [(c," ".join(C[c])) for c in C]
        #print(E)
        E.sort(key = lambda x: x[0])
        E = [e[1] for e in E]
        print(*E)
    else:
        A.sort(key = lambda x:x[1],reverse=True)
        B.sort(key = lambda x:x[1],reverse=False)

        i = 0
        j = 0


        C = defaultdict(list)
        D = [0]*len(B)
        flagA = -1
        flagB = -1
        while i<len(A) and j<len(B):
            if A[i][0] == B[j][0]:
                if i==len(A)-1:
                    if j==len(B)-1:
                        break
                    j+=1
                    flagB = j-1
                else:
                    i+=1
                    flagA = i-1
            while len(C[A[i][0]]) < A[i][1] and D[j] < B[j][1]:
                C[A[i][0]].append(str(B[j][0]))
                D[j] += 1
            if D[j] == B[j][1]:
                if flagA>=0:
                    i=flagA
                    flagA = -1
                j+=1    
            else:
                if flagB>=0:
                    j=flagB
                    flagB = -1
                i+=1
            #print(D)
            #print(i,j)
            #print(flagA,flagB)
        if sum(D)==N:
            print("Yes")
            E = [(c," ".join(C[c])) for c in C]
            #print(E)
            E.sort(key = lambda x: x[0])
            E = [e[1] for e in E]
            print(*E)
        else:
            A.sort(key = lambda x:x[1],reverse=False)
            B.sort(key = lambda x:x[1],reverse=True)

            i = 0
            j = 0


            C = defaultdict(list)
            D = [0]*len(B)
            flagA = -1
            flagB = -1
            while i<len(A) and j<len(B):
                if A[i][0] == B[j][0]:
                    if i==len(A)-1:
                        if j==len(B)-1:
                            break
                        j+=1
                        flagB = j-1
                    else:
                        i+=1
                        flagA = i-1
                while len(C[A[i][0]]) < A[i][1] and D[j] < B[j][1]:
                    C[A[i][0]].append(str(B[j][0]))
                    D[j] += 1
                if D[j] == B[j][1]:
                    if flagA>=0:
                        i=flagA
                        flagA = -1
                    j+=1    
                else:
                    if flagB>=0:
                        j=flagB
                        flagB = -1
                    i+=1
                #print(D)
                #print(i,j)
                #print(flagA,flagB)
            if sum(D)==N:
                print("Yes")
                E = [(c," ".join(C[c])) for c in C]
                #print(E)
                E.sort(key = lambda x: x[0])
                E = [e[1] for e in E]
                print(*E)
            else:

                A.sort(key = lambda x:x[0],reverse=True)
                B.sort(key = lambda x:x[0],reverse=True)

                C,D = solve(A,B)
                if sum(D)==N:
                    print("Yes")
                    E = [(c," ".join(C[c])) for c in C]
                    #print(E)
                    E.sort(key = lambda x: x[0])
                    E = [e[1] for e in E]
                    print(*E)
                else:
                    A.sort(key = lambda x:x[0],reverse=True)
                    B.sort(key = lambda x:x[0],reverse=False)

                    C,D = solve(A,B)
                    if sum(D)==N:
                        print("Yes")
                        E = [(c," ".join(C[c])) for c in C]
                        #print(E)
                        E.sort(key = lambda x: x[0])
                        E = [e[1] for e in E]
                        print(*E)
                    else:
                        A.sort(key = lambda x:x[0],reverse=False)
                        B.sort(key = lambda x:x[0],reverse=True)
                        C,D = solve(A,B)
                        if sum(D)==N:
                            print("Yes")
                            E = [(c," ".join(C[c])) for c in C]
                            #print(E)
                            E.sort(key = lambda x: x[0])
                            E = [e[1] for e in E]
                            print(*E)
                        else:

                            A.sort(key = lambda x:x[0],reverse=False)
                            B.sort(key = lambda x:x[0],reverse=False)
                            C,D = solve(A,B)
                            if sum(D)==N:
                                print("Yes")
                                E = [(c," ".join(C[c])) for c in C]
                                #print(E)
                                E.sort(key = lambda x: x[0])
                                E = [e[1] for e in E]
                                print(*E)
                            else:
                                print("No")
