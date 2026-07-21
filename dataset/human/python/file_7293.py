import sys
input = sys.stdin.readline

def main():
    S = input().replace('\n', '')
    Q = int(input())

    flg = 0
    head = ""
    tail = ""
    for _ in range(Q):
        query = input().split()
        if len(query) == 1:
            head, tail = tail, head
            flg += 1
        else:
            T, F, C = query
            if int(F) == 1:
                head += C
            else:
                tail += C
    if flg % 2:
        print(head[::-1] + S[::-1] + tail)
    else:
        print(head[::-1] + S + tail)
main()
