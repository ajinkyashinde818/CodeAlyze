def solve(S):
    S = S[::-1]
    for _ in range(len(S) // 5 + 1):
        if S[:5] == "dream"[::-1]:
            S = S[5:]
        if S[:5] == "erase"[::-1]:
            S = S[5:]
        if S[:6] == "eraser"[::-1]:
            S = S[6:]
        if S[:7] == "dreamer"[::-1]:
            S = S[7:]
    if len(S):
        return "NO"
    else:
        return "YES"
#
# assert(solve("erasedream") == "YES")
# assert(solve("dreameraser") == "YES")
# assert(solve("dreamerer") == "NO")
# assert(solve("dreamdreamerer") == "NO")
# assert(solve("erasdreamerer") == "NO")
# assert(solve("dreameraserer") == "NO")

if __name__ == "__main__":
    S = input()
    print(solve(S))
