import sys
import decimal # 10進法に変換，正確な計算

def input():
    return sys.stdin.readline().strip()

def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    keep = n
    sum = 0
    for i in a:
        sum += b[i-1]
        if i == keep + 1:
            sum += c[i-2]
        keep = i
    print(sum)

    
    
main()
