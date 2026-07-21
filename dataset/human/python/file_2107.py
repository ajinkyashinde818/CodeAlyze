if __name__ == '__main__':
    import sys
    input = sys.stdin.readline

    n = int(input())
    s = input().rstrip()
    eng_list = 'abcdefghigklmnopqrstuvwxyz'
    eng_dict = {}
    for i in eng_list:
        eng_dict[i] = 1
    for i in s:
        try:
            eng_dict[i] += 1
        except KeyError:
            eng_dict[i] = 2
    ans = 1
    size = 10**9+7
    for i in eng_dict.values():
        ans = (ans*i)%size
    print((ans-1)%size)
