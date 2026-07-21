import sys

def main():
    S = list(input())
    S.reverse()
    words = ['resare', 'esare', 'remaerd', 'maerd']
    while len(S) > 0:
        deleted = False
        for word in words:
            if len(S) >= len(word) and ''.join(S[0:len(word)]) == word:
                del S[0:len(word)]
                deleted = True
        if deleted is False:
            print('NO')
            sys.exit()

    print('YES')

main()
