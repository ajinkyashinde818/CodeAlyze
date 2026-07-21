import sys
input = sys.stdin.readline

def main():
    s = sorted(list(input().strip()), reverse=False)
    t = sorted(list(input().strip()), reverse=True)

    ok = False
    same_all = True
    for i in range(min(len(s), len(t))):
        if s[i] < t[i]:
            same_all = False
            ok = True
            break
        elif s[i] > t[i]:
            same_all = False
            break
    
    if same_all:
        if len(s) < len(t):
            ok = True
    
    if ok:
        print("Yes")
    else:
        print("No")



if __name__ == "__main__":
    main()
