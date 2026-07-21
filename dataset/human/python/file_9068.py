S = input()
T = ["dream", "dreamer", "erase", "eraser"]
def main():
    i = len(S)
    if i == 0:
        print("NO")
        return 0
    while True:
        if i == 0:
            break
        elif i < 5:
            print("NO")
            return 0
        elif S[i - 5:i] == T[0] or S[i - 5:i] == T[2]:
            i -= 5
        elif i < 6:
            print("NO")
            return 0
        elif S[i - 6:i] == T[3]:
            i -= 6
        elif i < 7:
            print("NO")
            return 0
        elif S[i - 7:i] == T[1]:
            i -= 7
        else:
            print("NO")
            return 0
    print("YES")
    return 0
main()
