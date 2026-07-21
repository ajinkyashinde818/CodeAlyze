import sys
input = sys.stdin.buffer.readline

def main():
    K,N = map(int,input().split())
    a = list(map(int,input().split()))
    
    a = [a[-1]-K] + a + [a[0]+K]
    
    ans = K
    
    for i in range(N):
        use = max(a[i+1]-a[i],a[i+2]-a[i+1])
        ans = min(ans,K-use)
    
    print(ans)
    
if __name__ == "__main__":
    main()
