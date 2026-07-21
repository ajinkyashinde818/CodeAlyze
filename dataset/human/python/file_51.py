def main():
    r,g,b,n=map(int,input().split())
    a = 0
    for i in range(n+1):
        ri = r * i
        if ri > n:
            break
        for j in range(n+1):
            x=(n-(ri + j*g))
            if x>=0:
                if x%b == 0:
                    a += 1
            else:
                break
    print(a)

if __name__ == "__main__":
    main()
