def main():
    s = input()
    N = len(s)

    nox = []
    idxs = []
    ans = 0
    for i, c in enumerate(s):
        if c != "x":
            nox.append(c)
            idxs.append(i)
    
    if nox != nox[::-1]:
        print(-1)
        exit()
    
    if len(nox) == 0:
        print(0)
        exit()

    if len(nox)%2 == 0:
        left = len(nox)//2 - 1
        right = len(nox)//2
        
        left_idx = idxs[left]
        right_idx = idxs[right]

    else:
        center = len(nox)//2
        left_idx = idxs[center]
        right_idx = idxs[center]

    while not(left_idx == 0 and right_idx == N-1):
        if s[left_idx] == s[right_idx]:
            if left_idx > 0 and right_idx < N - 1:
                left_idx -= 1
                right_idx += 1
            else:
                if left_idx <= idxs[0] and right_idx >= idxs[-1] and (left_idx > 0 or right_idx < N - 1):
                    ans += 1
                if left_idx > 0:
                    left_idx -= 1
                if right_idx < N-1:
                    right_idx += 1

        elif s[left_idx] == "x":
            ans += 1
            if left_idx > 0:
                left_idx -= 1
        elif s[right_idx] == "x":
            ans += 1
            if right_idx < N-1:
                right_idx += 1
    print(ans)

if __name__ == "__main__":
    main()
