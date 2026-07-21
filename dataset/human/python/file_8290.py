import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int,input().split()))

S = ((N+1)*N)//2
sA = sum(A)
if sA%S!=0:
    print("NO")
else:
    C = sA//S
    count = 0    
    flag = False
    for i in range(N):
        if i == N-1:
            sub=A[0]-A[i]
        else:
            sub=A[i+1]-A[i]

        if (sub + C*(N-1))%N != 0:
            flag = True
            break
        cnt = C-(sub + C*(N-1))//N
        if cnt>C or cnt<0:
            flag = True
            break
        count += cnt
    if flag:
        print("NO")
    else:
        if C == count:
            print("YES")
        else:
            print("NO")
