def main():
    import sys

    def input(): return sys.stdin.readline().rstrip()

    s = input()
    n = len(s)
    sr = s.replace('x', '')
    if sr == '':
        print(0)
        return
    elif sr != sr[::-1]:
        print(-1)
        return
    cur_l = 0
    cur_r = n-1
    ans = 0
    cnt = 0
    while cur_l < cur_r:
        while s[cur_l] == 'x':
            cnt += 1
            cur_l += 1
        while s[cur_r] != s[cur_l]:
            cur_r-=1
            cnt -= 1
        ans += abs(cnt)
        cur_l += 1
        cur_r -= 1
        cnt = 0
        
    print(ans)   
    
        

if __name__ == '__main__':
    main()
