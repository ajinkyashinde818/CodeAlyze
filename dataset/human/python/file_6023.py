if __name__ == "__main__":
    input_data =[]
    for x in range(4):
        input_data.append(input())
    dim = int(input_data[0])
    A = [int(x) for x in input_data[1].split()]
    B = [int(x) for x in input_data[2].split()]
    C = [int(x) for x in input_data[3].split()]

    goukei = 0
    pre = -10
    for x in range(dim):
        goukei += B[A[x]-1]
        if A[x] - pre == 1:
            goukei += C[pre - 1]
        
        pre = A[x]

    print(goukei)
