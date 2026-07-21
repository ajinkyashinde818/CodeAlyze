import math

def solve():
    N, K = map(int,input().split())
    A = list(map(int, input().split()))

    state = 1
    chklist = [0] * (N + 1)
    chklist_flag = [False] * (N + 1)
 
    chkmod = 0
    chkrem = K

    chklist_flag[0] = True

    for i in range(1, K + 1):
        state = A[state - 1]
        if chklist_flag[state - 1]:
            chkmod = (K - chklist[state - 1]) % (i - chklist[state - 1]) 
            chkrem = chklist[state - 1]
            break
        chklist[state - 1] = i 
        chklist_flag[state - 1] = True
    
    state = 1

    for i in range(chkrem + chkmod):
        state = A[state - 1]
    
    print(state)

if __name__ == "__main__":
    solve()
