def solve():
    S = input()
    N = len(S)

    left = 0
    right = N-1

    ans = 0
    while right - left > 0:
        if S[left] == S[right]:
            left += 1
            right -= 1
        else: 
            if S[left] == 'x':
                left += 1
                ans += 1
            elif S[right] == 'x':
                right -= 1
                ans += 1
            else:
                print('-1')
                return
    
    print(ans)
                
if __name__ == '__main__':
    solve()
