def judge(S):
    S = "zzz" + S
    update = True
    while update:
        update = False
        if S[len(S)-7:] == "dreamer":
            S = S[:len(S)-7]
            update = True
        elif S[len(S)-6:] == "eraser":
            S = S[:len(S)-6]
            update = True
        elif S[len(S)-5:] == "dream" or S[len(S)-5:] == "erase":
            S = S[:len(S)-5]
            update = True
    if len(S) == 3:
        return True
    else:
        return False

S = input()

if judge(S):
    print("YES")
else:
    print("NO")
