def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    c = [int(x) for x in input().split()]
    ans = 0
    latter = 60
    for i in range(n):
        now = a[i]-1
        ans += b[now]
        if latter+1 == now:
            ans += c[now-1]
        latter = now
    print(ans)
if __name__ == "__main__":
    main()
