def solve():
    R,G,B,N = map(int,input().split())

    cnt = 0
    for r in range(0,3000+1):
        for g in range(0,3000+1):
            b = N - (r * R + g * G)
            if b >= 0 and b % B == 0:
                cnt += 1
    
    print(cnt)
        
if __name__ == '__main__':
    solve()
