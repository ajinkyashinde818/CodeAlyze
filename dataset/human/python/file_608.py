def main():
    N = int(input())
    A = list(map(int, input().split()))

    if N == 2:
        print(max(A[0]+A[1], (-A[0])+(-A[1])))
        return

    a_sum, a1, a2 = 0, A[0], A[1]
    b_sum, b1, b2 = 0, -A[0], -A[1]
    for i in range(2, N):
        #print(a_sum, a1, a2)
        #print(b_sum, b1, b2)
        #print(A[i])
        

        if (a_sum + a1 + a2 + A[i]) > (b_sum + b1 + b2 + A[i]):
            new_a_sum = a_sum + a1
            new_a1 = a2
            new_a2 = A[i]
        else:
            new_a_sum = b_sum + b1
            new_a1 = b2
            new_a2 = A[i]

        if (a_sum + a1 - a2 - A[i]) > (b_sum + b1 - b2 - A[i]):
            new_b_sum = a_sum + a1
            new_b1 = -a2
            new_b2 = -A[i]
        else:
            new_b_sum = b_sum + b1
            new_b1 = -b2
            new_b2 = -A[i]

        a_sum, a1, a2 = new_a_sum, new_a1, new_a2
        b_sum, b1, b2 = new_b_sum, new_b1, new_b2
        
    print(max(a_sum+a1+a2, b_sum+b1+b2))

main()
