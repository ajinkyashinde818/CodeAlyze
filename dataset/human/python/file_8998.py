def solve():
    S = input()
    N = len(S)
    Srev = []
    for i in reversed(range(N)): Srev.append(S[i])
    Srev = "".join(Srev)
    ti = 0
    while ti < N:
        if Srev[ti] == "m":
            if Srev[ti:min(N, ti + 5)] == "maerd": ti += 5
            else:
                print("NO")
                break
        elif Srev[ti] == "e":
            if Srev[ti:min(N, ti + 5)] == "esare": ti += 5
            else:
                print("NO")
                break
        elif Srev[ti] == "r":
            if Srev[ti:min(N, ti + 6)] == "resare": ti += 6
            elif Srev[ti:min(N, ti + 7)] == "remaerd": ti += 7
            else:
                print("NO")
                break
        else:
            print("NO")
            break
    else: print("YES")


    return 0

if __name__ == "__main__":
    solve()
