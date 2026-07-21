def solve():
    N = int(input())
    A = list(map(int, input().split()))
    
    sum_A = sum(A)
    sub_sum = A[0]
    ret = abs(sum_A-2*sub_sum)
    for a in A[1:-1]:
        sub_sum += a
        if abs(sum_A-2*sub_sum) < ret:
            ret = abs(sum_A-2*sub_sum)
            
    print(ret)
    
solve()
