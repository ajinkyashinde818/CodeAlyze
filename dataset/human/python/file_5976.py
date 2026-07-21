def main():
    n = int(input())
    alis = list(map(int, input().split()))
    blis = list(map(int, input().split()))
    clis = list(map(int, input().split()))
    ans = 0
    tmp = ""
    for a in alis:
        ans += blis[a-1]
        if tmp == a-1:
            ans += clis[a-2]
        tmp = a
    print(ans)
    
    
if __name__ == "__main__":
    main()
