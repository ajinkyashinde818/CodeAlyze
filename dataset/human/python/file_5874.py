if __name__ == '__main__':
    n = int(input())
    a_list = list(map(int,input().split()))
    b_list = list(map(int,input().split()))
    c_list = list(map(int,input().split()))

    answer = 0
    for i in range(n):
        a = a_list[i]
        answer += b_list[a-1]
        if i < n-1:
            next_a = a_list[i+1]
            if next_a - a == 1:
                answer += c_list[a-1]
    print(answer)
