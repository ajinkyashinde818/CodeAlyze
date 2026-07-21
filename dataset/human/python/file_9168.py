def main():
    S = input()

    word_list = ['dream', 'dreamer', 'erase', 'eraser']

    while len(S) > 0:
        for word in word_list:
            flag = "NO"
            if S[len(S) - len(word):] == word:
                S = S[:len(S) - len(word)]
                flag = "YES"
                break

        if flag == "NO":
            break
    print(flag)

main()
