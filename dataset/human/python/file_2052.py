def main():
    length = int(input())
    word = input()
    count = {}
    for i in range(length):
        if word[i] in count:
            count[word[i]] += 1
        else:
            count[word[i]] = 2
    mod = 10 ** 9 + 7
    answer = 1
    for c in count.values():
        answer = (answer * c) % mod
    print(answer - 1)


if __name__ == '__main__':
    main()
