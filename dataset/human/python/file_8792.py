def main():
    K, N = map(int,input().split())
    L = list(map(int,input().split()))
    
    d = [L[i+1]-L[i] for i in range(N-1)]
    d.append(L[0] - (L[-1]-K))
    
    m = max(d)
    ans = sum(d) - m
    print(ans)


if __name__ == '__main__':
    main()
