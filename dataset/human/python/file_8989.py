def main():
    S = input()

    i = 0
    while i < len(S):
        if S[i:i+7] == "dreamer" and (i+7 == len(S) or (i+7 < len(S) and S[i+7] != "a")):
            i += 7
        elif S[i:i+6] == "eraser":
            i += 6
        elif S[i:i+5] == "dream" or S[i:i+5] == "erase":
            i += 5
        else:
            return "NO"

    return "YES"



if __name__ == '__main__':

    print(main())
