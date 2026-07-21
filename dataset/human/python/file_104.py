if __name__ == '__main__':
    import sys
    input = sys.stdin.readline

    r, g, b, n = map(int, input().split())
    ans = 0
    rgb = sorted([r,g,b], reverse=True)
    if rgb[1] == 1 and rgb[2] == 1:
        for i in range(n//rgb[0]+1):
            ans += (n-i*rgb[0]+1)
        print(ans)
        exit()
    for i in range(n//rgb[0]+1):
        for j in range((n-i*rgb[0])//rgb[1]+1):
            if (n-i*rgb[0]-j*rgb[1])%rgb[2]==0:
                ans+=1
    print(ans)
