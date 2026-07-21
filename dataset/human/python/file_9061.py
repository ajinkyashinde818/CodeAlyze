def DFS(S):
    word_list = [ "dreamer","dream", "eraser", "erase"]
    stack = ["dream", "dreamer", "erase", "eraser"]
    while stack:
        word = stack.pop()
        if word == S[0]:
            return "YES"
        for i in word_list:
            next_word = word + i
            check = S[0][:len(word + i)]
            if next_word != check:
                continue
            if next_word == check:
                stack.append(next_word)
    return "NO"






if __name__ == "__main__":
    S = [input()]
    print(DFS(S))
