if __name__ == '__main__':
    S = str(input())
    T = ''
    while True:
        if len(S) == 0:
            print('YES')
            break
        elif S[len(S)-7:len(S)] == 'dreamer':
            S = S[:len(S)-7]
            continue
        elif S[len(S)-6:len(S)] == 'eraser':
            S = S[:len(S)-6]
            continue
        elif S[len(S)-5:len(S)] == 'dream':
            S = S[:len(S)-5]
            continue
        elif S[len(S)-5:len(S)] == 'erase':
            S = S[:len(S)-5]
            continue
        else:
            print('NO')
            break
