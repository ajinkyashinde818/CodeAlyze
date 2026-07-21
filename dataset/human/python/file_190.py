def resolve():
    '''
    code here
    '''

    R, G, B, N = [int(item) for item in input().split()]

    cnt = 0

    for i in range(N+1):
        for j in range(N+1-i):
            _b = N - (i * R + j * G)
            
            if _b % B == 0 and _b >= 0:
                cnt += 1

    print(cnt)

if __name__ == "__main__":
    resolve()
