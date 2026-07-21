def read():
    K, N = list(map(int, input().strip().split()))
    A = list(map(int, input().strip().split()))
    return K, N, A

def solve(K, N, A):
    A.append(A[0] + K)
    B = [A[(i+1)] - A[i] for i in range(N)]
    B = sorted(B)
    return sum(B[:-1])


if __name__ == '__main__':
    inputs = read()
    print("{}".format(solve(*inputs)))
