from collections import defaultdict

def main():
    num = int(input())
    data = list(input())

    count_dic = defaultdict(int)

    for i in range(num):
        count_dic[data[i]] += 1

    count_list = list(count_dic.values())

    ans = 1
    for ele in count_list:
        ans *= ele + 1

    mod = 10 ** 9 + 7
    print((ans - 1) % mod)





if __name__ == '__main__':
    main()
