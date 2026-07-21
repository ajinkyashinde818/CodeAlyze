from collections import deque
def main():
    s = deque(raw_input().strip())
    ans = 0
    while len(s) > 1:
        st = s[0]
        nd = s[-1]
        if st == nd:
            s.pop()
            s.popleft()
        elif st == 'x':
            s.popleft()
            ans += 1
        elif nd == 'x':
            s.pop()
            ans += 1
        else:
            print -1
            return
    print ans
main()
