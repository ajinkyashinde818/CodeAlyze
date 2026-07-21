def main():
    r,g,b,n = map(int, input().split())
    tmp = [r,g,b]
    r,g,b = sorted(tmp, reverse=True)
    res = 0
    for i in range(n//r + 1):
        if i*r > n:
            break
        for j in range(n//g + 1):
            if r*i + g*j > n:
                break
            if (n-(r*i + g*j)) % b==0:
                res += 1           
    print(res)

if __name__ == '__main__':
    main()
