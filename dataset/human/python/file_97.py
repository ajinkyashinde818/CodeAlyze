def solve():
    R,G,B,N = map(int, input().split())
    ans = 0
    for r in range( N // R + 1):
        nokori = N - r*R
        for g in range(  nokori // G + 1):
            nokoko = nokori - g * G
            if (nokoko % B == 0):
                ans += 1
    print(ans)
            

if __name__ == "__main__":
    solve()
