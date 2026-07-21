def main():
    S = input()
    no_x = ''.join(S.split('x'))
    if no_x != no_x[::-1]:
        print(-1)
        return
    left, right = 0, len(S) - 1
    ans = 0
    while left <= right:
        if S[left] != S[right]:
            if S[left] == 'x':
                while S[left] != S[right]:
                    left += 1
                    ans += 1
            else:  # S[right] == 'x'
                while S[left] != S[right]:
                    right -= 1
                    ans += 1
        left += 1
        right -= 1
    print(ans)


if __name__ == '__main__':
    main()
