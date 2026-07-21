def main():
    antidote, antidote_delicious, poison = map(int, input().split())
    answer = antidote_delicious + poison
    if antidote + antidote_delicious < poison and antidote_delicious < poison - antidote:
        answer = antidote + 2 * antidote_delicious + 1
    print(answer)


if __name__ == '__main__':
    main()
