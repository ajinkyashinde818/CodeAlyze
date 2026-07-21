def resolve():
    K, N = map(int, input().split())
    ie_list = list(map(int, input().split()))

    value_list = []
    value_list.append(K - ie_list[-1] + ie_list[0])
    count = 0
    while count != N - 1:
        value_list.append(ie_list[count + 1] - ie_list[count])
        count += 1
    print(K - max(value_list))

resolve()
