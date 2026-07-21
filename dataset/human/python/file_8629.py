def main():
    k,n = map(int,input().split())
    arr = list(map(int,input().split()))
    ans = float('inf')
    prev = 0
    for i in range(n):
        if i == n-1:
            if prev == 0:
                total = arr[-1]-arr[i]
            else:
                total = k-arr[i]+prev
        else:
            if i == 0:
                total = arr[-1]-arr[i]
            else:
                total = min(k-arr[i]+prev,arr[i]+k-arr[i+1])

        prev += arr[i]
            
        ans = min(ans,total)

    print(ans)
                            
main()
