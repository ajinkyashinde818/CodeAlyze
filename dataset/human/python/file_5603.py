S = input()

def solver(S):
    l = 0   
    r = len(S)-1

    ans = 0
    while l < r:
        if S[l] == S[r]:
            l += 1
            r -= 1
            continue

        if S[l] == "x":
            l += 1
            ans += 1
            continue
        
        if S[r] == "x":
            r -= 1
            ans += 1
            continue
        
        return -1
    
    return ans


print(solver(S))
