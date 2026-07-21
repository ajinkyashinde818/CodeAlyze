def main(S):
    listdreamereraser = ['dreamer','eraser','dream','erase']
    while True:
        for i in listdreamereraser:
            if i == S[-len(i):]:
                S = S[:-len(i)]
                break
        else:
            return False
        if len(S) == 0:
            return True

S = input()
print('YES' if main(S) else 'NO')
