from collections import deque

def main():
    ans = deque(input())
    n = int(input())
    vec = 1
    for i in range(n):
        q = input()
        if q == "1":
            vec *= -1
        else:
            _,o,s = q.split()
            if ((o == "1") and (vec == 1)) or ((o == "2") and (vec == -1)):
                ans.appendleft(s)
            else:
                ans.append(s)
    if vec == -1:
        ans.reverse()
    ans = ''.join(ans)
    print(ans)

if __name__ == '__main__':
    main()
