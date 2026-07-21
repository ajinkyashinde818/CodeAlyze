if __name__ == '__main__':
    S = str(input())
    word_list = ['dream', 'dreamer', 'erase', 'eraser']
    rev_S = S[::-1]
    word_list = list(map(lambda x : x[::-1], word_list))

    answer = 'YES'
    while len(rev_S) >= 1:
        for i in range(len(word_list)):
            word = word_list[i]
            if rev_S.startswith(word):
                rev_S = rev_S[len(word)::]
                break
            elif i == len(word_list)-1:
                answer = 'NO'
                break
        if answer == 'NO':
            break

    print(answer)
