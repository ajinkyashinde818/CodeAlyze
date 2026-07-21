from collections import defaultdict
N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
Adic = defaultdict(int)
Bdic = defaultdict(int)
for i in range(N):
    Adic[A[i]] += 1
    Bdic[B[i]] += 1
nums = []
for i in range(1,N+1):
    nums.append((Adic[i],Bdic[i],i))
nums.sort(key=lambda x:x[0]+x[1],reverse=True)
index = 0
Aindex = 0
Bindex = 0
ansA = [-1]*N
ansB = [-1]*N
OK = False
for nA,nB,i in nums:
    if nA + nB > N:
        print('No')
        exit()
    else:
        if not OK:
            while nA and index < N:
                ansA[index] = i
                index += 1
                nA -= 1
            if index == N:
                OK = True
            while nB and index < N:
                ansB[index] = i
                index += 1
                nB -= 1
            if index == N:
                OK = True
        if OK:
            while nA:
                while ansA[Aindex] != -1:
                    Aindex += 1
                ansA[Aindex] = i
                nA -= 1
            while nB:
                while ansB[Bindex] != -1:
                    Bindex += 1
                ansB[Bindex] = i
                nB -= 1
ans = []
for i in range(N):
    ans.append((ansA[i],ansB[i]))
    if ansA[i] == ansB[i]:
        print('No')
        exit()
ans.sort(key=lambda x:x[0])
ANS = []
for i in range(N):
    ANS.append(ans[i][1])
print('Yes')
print(*ANS)
