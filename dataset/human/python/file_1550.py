import numpy as np


def main():
    n, m = map(int, input().split())
    As = [list(input()) for _ in range(n)]
    Bs = [list(input()) for _ in range(m)]

    As_arr = np.array(As)
    Bs_arr = np.array(Bs)
    for i in range(n-m+1):
        for j in range(n-m+1):
            xs, xe = i, i+m
            ys, ye = j, j+m
            if np.all(As_arr[ys:ye, xs:xe] == Bs_arr):
                print('Yes')
                exit()
    print('No')


if __name__ == "__main__":
    main()
