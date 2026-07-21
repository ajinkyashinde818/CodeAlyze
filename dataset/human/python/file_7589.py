def resolve():
    import collections
    S = input()
    Q = int(input())

    query_list = [input().split() for _ in range(Q)]

    T_cnt_list = collections.deque([0])
    left = ''
    right = ''

    for i, query in enumerate(query_list):
        if query[0] == '1':
            T_cnt_list.append(1+T_cnt_list[-1])

        else:
            T_cnt_list.append(T_cnt_list[-1])

            if query[1] == '1' and T_cnt_list[i+1]%2 == 0:
                left = query[2] + left

            elif query[1] == '1' and T_cnt_list[i+1]%2 == 1:
                right = right + query[2]

            elif query[1] == '2' and T_cnt_list[i+1]%2 == 0:
                right = right + query[2]

            elif query[1] == '2' and T_cnt_list[i+1]%2 == 1:
                left = query[2] + left

    if T_cnt_list[-1]%2 == 0:
        print(left + S + right)
    else:
        print(right[::-1] + S[::-1] + left[::-1])

if __name__ == "__main__":
    resolve()
