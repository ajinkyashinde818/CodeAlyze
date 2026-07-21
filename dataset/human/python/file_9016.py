def solve():
    S = input()[::-1]
    i = 0
    while i < len(S):
        if S[i:i+5] in ['maerd', 'esare']:
            i += 5
        elif S[i:i+6] == 'resare':
            i += 6
        elif S[i:i+7] == 'remaerd':
            i += 7
        else:
            return 'NO'
    return 'YES'

    
if __name__ == '__main__':
    ans = solve()
    print(ans)
