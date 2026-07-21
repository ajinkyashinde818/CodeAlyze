def main():
    N = int(input())
    S = input()
    div = pow(10, 9) + 7
    facN = 1
    for i in range(1, N+1):
        facN = (facN * i) % div

    if S[0] != "B": return 0
    t = "L"
    ctL, ctR = 1, 0
    for i in range(1, 2*N):
        if S[i-1] != S[i]:
            t += t[-1]
        else:
            if t[-1] == "L":
                t += "R"
            else:
                t += "L"
        if t[-1] == "L": ctL += 1
        else: ctR += 1
    if S[-1] != "B":
        return 0
    if ctL != ctR: return 0

    prefixL = [0]
    for c in t:
        if c == "L":
            prefixL.append(prefixL[-1]+1)
        else:
            prefixL.append(prefixL[-1])

    # print(S, t)
    # print(prefixL)
    ans = 1
    countR = 0
    for i in range(len(t)):
        if t[i] == "R":
            ans *= prefixL[i] - countR
            ans %= div
            countR += 1
    return (ans * facN) % div

if __name__ == '__main__':

    print(main())
