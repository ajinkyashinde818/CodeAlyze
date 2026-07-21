import sys

input = sys.stdin.readline

def main():
    N = int(input())
    A = list(map(int, input().split()))
    ans = 0; cnt = 0; tmp = float('inf'); flag = False
    for a in A:
        ans += abs(a)
        tmp = min(tmp, abs(a))
        if a < 0:
            cnt += 1
        elif a == 0:
            flag = True
        else:
            continue
    if cnt%2 == 0:
        flag = True
    if flag:
        print(ans)
    else:
        print(ans - 2*tmp)

if __name__ == "__main__":
    main()
