def main():
    import sys
    input = sys.stdin.readline

    import math
    N = int(input())

    if N % 2 != 0:
        print(0)
        exit()
    else:
        num_zeros = N // 10
        N_head = N//10
        for i in range(1, 25):
            num_zeros += (N_head)//(5**i)
    print(num_zeros)


if __name__ == "__main__":
    main()
