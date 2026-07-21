if __name__ == '__main__':
    N = int(input())
    A_list = list(map(int, input().split()))

    minus_cnt = 0

    for A in A_list:
        if A < 0:
            minus_cnt += 1

    answer = 0

    if minus_cnt % 2 == 0:
        for A in A_list:
            answer += abs(A)
    else:
        min_abs_A = pow(10, 9)
        for A in A_list:
            answer += abs(A)
            if min_abs_A > abs(A):
                min_abs_A = abs(A)
        answer -= min_abs_A * 2

    print(answer)
