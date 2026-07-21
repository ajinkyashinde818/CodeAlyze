def main():
    k, n = map(int, input().split(" "))
    a = list(map(int, input().split(" ")))
    d =[min(a)+k-max(a)]
    for i in range(n-1):
        d.append(a[i+1]-a[i])
    print(k-max(d))
    

if __name__ == "__main__":
    main()
