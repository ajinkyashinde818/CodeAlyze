def resolve():
    N = int(input())
    A_list = list(map(int, input().split()))
    B_list = list(map(int, input().split()))
    C_list = list(map(int, input().split()))

    point = 0

    i_minus = None

    for i in A_list:
        point += B_list[i-1]
        if i_minus is not None:
            if (i - i_minus) == 1:
                point += C_list[i_minus-1]
        i_minus = i

    print(point)

if __name__ == "__main__":
    resolve()
