def main():
    N = int(input())
    lst_A = list(map(int, input().split()))
    lst_B = list(map(int, input().split()))
    lst_C = list(map(int, input().split()))

    ret = sum(lst_B)
    for i in range(N - 1):
        a1 = lst_A[i]
        a2 = lst_A[i + 1]
        diff = a2 -a1

        if diff == 1:
            ret += lst_C[a1 - 1]
    
    return ret


if __name__ == "__main__":
    print(main())
