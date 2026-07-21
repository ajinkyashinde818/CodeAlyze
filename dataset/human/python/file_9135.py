import sys
input = sys.stdin.readline

def main():
    t1 = "dream"[::-1]
    t2 = "dreamer"[::-1]
    t3 = "erase"[::-1]
    t4 = "eraser"[::-1]

    s = input().strip()[::-1]

    while True:
        ok = False
        if len(s) >= 7:
            if s[:7] == t2:
                s = s[7:]
                ok = True
        if len(s) >= 6:
            if s[:6] == t4:
                s = s[6:]
                ok = True
        if len(s) >= 5:
            if s[:5] == t1 or s[:5] == t3:
                s = s[5:]
                ok = True
        
        if len(s) < 5 or not ok:
            break
    
    if s != "":
        print("NO")
    else:
        print("YES")

if __name__ == "__main__":
    main()
