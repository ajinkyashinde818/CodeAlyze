from sys import stdin


if __name__ == "__main__":
    _in = [_.rstrip() for _ in stdin.readlines()]
    K, N = list(map(int,_in[0].split(' ')))  # type:list(int)
    A_arr = list(map(int,_in[1].split(' ')))  # type:list(int)
    # vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
    A_arr_diff = []
    for i in range(len(A_arr[1:])):
        A_arr_diff.append(A_arr[i+1]-A_arr[i])
    A_arr_diff.append(K-A_arr[-1]+A_arr[0])
    cnt = K - max(A_arr_diff)
    # ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    print(cnt)
