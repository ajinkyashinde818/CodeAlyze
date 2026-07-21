def c_traveling_salesman_around_lake():
    K, N = [int(i) for i in input().split()]
    A = [int(i) for i in input().split()]  # ソート済
    A.append(A[0] + K)  # N 番の家と 1 番の家の間の距離も調べたい

    return K - max(A[i + 1] - A[i] for i in range(N))

print(c_traveling_salesman_around_lake())
