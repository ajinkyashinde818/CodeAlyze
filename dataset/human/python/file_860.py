import sys
import decimal # 10進法に変換，正確な計算

def input():
    return sys.stdin.readline().strip()

def main():
    n, r = map(int, input().split())
    if n >= 10:
        print(r)
        return
    ans = r + 100*(10-n)
    print(ans)
    

main()
