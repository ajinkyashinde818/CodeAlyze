def main():
    R, G, B, N = map(int, input().split())
    ans = 0
    for i in range(N//R+1):
        r = i
        for j in range(((N-R*r)//G)+1):
            g = j
            if N-R*r-G*g >= 0 and (N-R*r-G*g) % B == 0:
                ans += 1
    print(ans)

if __name__=='__main__':
    main()
