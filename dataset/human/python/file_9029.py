import sys

S = input()

words = ['dream', 'dreamer', 'erase', 'eraser']

while len(S) > 0:
    if len(S) < 5:
        print('NO')
        sys.exit(0)
    no_match = True
    for word in words:
        if S[-3] == word[-3]:
            if len(S) < len(word) or S[-len(word):] != word:
                print('NO')
                sys.exit(0)
            S = S[:-len(word)]
            no_match = False
            break
    if no_match:
        print('NO')
        sys.exit(0)

print('YES')
