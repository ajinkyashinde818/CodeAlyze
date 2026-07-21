import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
 
def main():
    N = int(readline())
    if N%2 != 0:
        print(0)
        return
    k = 1
    cnt = 0
    while 1:
        p = pow(5, k)
        tmp = N//p
        if tmp == 0:
            break
        cnt += tmp//2
        k += 1
    print(cnt) 
if __name__ == '__main__':
    main()
