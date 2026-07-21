def main():
    n = int(input())
    a_s = list(map(int, input().split(' ')))
    b_s = list(map(int, input().split(' ')))
    c_s = list(map(int, input().split(' ')))

    result = 0
    pre = -1
    for a in a_s:
        result += b_s[a-1]
        if a == (pre+1):
            result += c_s[pre-1]
        pre = a
    print(result)



if __name__ == '__main__':
    main()
