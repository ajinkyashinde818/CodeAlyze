import sys
def main():
    num_a, num_b = map(int, input().split())
    data_a = [list(input()) for i in range(num_a)]
    data_b = [list(input()) for i in range(num_b)]

    for i in range(num_a - num_b + 1):
        for j in range(num_a - num_b + 1):
            ok_flg = 1
            for k in range(num_b):
                for l in range(num_b):
                    # print(data_b[k][l],  data_a[k + i][l + j])
                    if data_b[k][l] != data_a[k + i][l + j]:
                        ok_flg = 0
                        break
            if ok_flg:
                print('Yes')
                sys.exit()

    print('No')



if __name__ == '__main__':
    main()
