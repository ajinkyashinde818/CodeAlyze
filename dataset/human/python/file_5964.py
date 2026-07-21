"""
3
3 1 2
2 5 4
3 6

ans 14
"""


def main():
    N = int(input())
    A = [int(x)-1 for x in input().split()]
    B = [int(x) for x in input().split()]
    C = [int(x) for x in input().split()]

    total_eat_point = 0
    for round_num in range(N):
        total_eat_point += B[A[round_num]]
        if round_num == 0:
            continue
        if A[round_num] - 1 == A[round_num-1]:
            total_eat_point += C[A[round_num-1]]

    print(total_eat_point)


if __name__ == "__main__":
    main()
