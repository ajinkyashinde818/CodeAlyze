def resolve():
    S = input()
    strings = ["dream", "dreamer", "erase", "eraser"]
    while True:
        if S == "":
            print("YES")
            return

        if S.startswith("eraser"):
            S = S[len("eraser"):]
            continue
        elif S.startswith("erase"):
            S = S[len("erase"):]
            continue
        elif S.startswith("dreamer"):
            if S.startswith("dreamerase"):
                S = S[len("dream"):]
                continue
            else:
                S = S[len("dreamer"):]
                continue
        elif S.startswith("dream"):
            S = S[len("erase"):]
            continue
        else:
            print("NO")
            return




if '__main__' == __name__:
    resolve()
