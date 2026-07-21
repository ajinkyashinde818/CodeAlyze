def resolve():
    '''
    code here
    '''
    K, N = [int(item) for item in input().split()]
    A_list = [int(item) for item in input().split()]

    last_dist = K-A_list[-1] + A_list[0]
    res = A_list[-1] - A_list[0]

    temp_dist = res - (A_list[1] - A_list[0]) + last_dist
    res = min(res, temp_dist)

    for i in range(2,N):
        temp_dist = temp_dist - (A_list[i] - A_list[i-1]) + (A_list[i-1] - A_list[i-2])
        res = min(res, temp_dist)

    print(res)

if __name__ == "__main__":
    resolve()
