def A():
    print(int(input())**3)

def B():
    N = int(input())
    A = [int(i) for i in input().split()]
    B = [int(i) for i in input().split()]
    C = [int(i) for i in input().split()]

    points = B[A[0]-1]
    previous = A[0]-1
    #print(points)
    for i in range(1, N):
        points += B[A[i]-1]
        if A[i]-1 == previous+1:
            points += C[previous]
        #print(points)
        previous = A[i]-1
    
    print(points)
B()
