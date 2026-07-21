import sys
input = sys.stdin.readline

def main():
    k , s = map( int , input().split() )

    ans = 0

    for i in range( k + 1 ):
        if i > s:
            break
        if s - i > 2 * k:
            continue
        for j in range( k + 1 ):
            if i + j > s:
                break
            if s - i - j > k:
                continue
            ans += 1

    print( ans )




main()
