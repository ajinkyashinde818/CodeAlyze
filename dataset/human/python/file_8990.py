import sys
input=sys.stdin.readline

def main():
    S = input().strip()
    S = S.replace("eraser","")
    S = S.replace("erase","")
    S = S.replace("dreamer","")
    S = S.replace("dream","")
    if S == "":
        print("YES")
    else:
        print("NO")

if __name__ == '__main__':
    main()
