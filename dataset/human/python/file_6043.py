if __name__ == '__main__':
    n = int(input())
    a_input = list(map(int, input().split()))
    b_input = list(map(int, input().split()))
    c_input = list(map(int, input().split()))

    score = 0
    pre_a = -1
    for i in range(n):
        score += b_input[a_input[i] - 1]
        if pre_a == a_input[i] - 1:
            score += c_input[pre_a - 1]
        pre_a = a_input[i]
    print(score)
