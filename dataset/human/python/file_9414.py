import math
import copy

def Reach(A, T, K):
    for i in range(K):
        T = A[T]-1
    return T + 1


def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    ac = [0 for j in range(N)]
    T = 0
    ac[0] = 1
    for i in range(1,N):
        T = A[T]-1
        if ac[T] == 0:
            ac[T] = 1
        else:
            pos_from_F = T
            cnt_from_F = i
            break

    T = pos_from_F
    for i in range(1,N):
        T = A[T]-1
        if T == pos_from_F:
            cnt_from_S = i
            break


    T = 0
    if K < cnt_from_F:
        for i in range(K):
            T = A[T]-1
    else:
        K = (K-cnt_from_F) % cnt_from_S
        T = pos_from_F
        for i in range(K):
            T = A[T]-1

    print(T+1)

if __name__ == '__main__':
    main()
