import sys
readline = sys.stdin.readline

def main():
    s = input()
    q = int(input())

    hanten = 0 # 偶数なら正常、 奇数なら反転状態

    front = "" # リストの前に追加するのは、O(n)なので避ける
    back = ""

    for _ in range(q):
        tmp = readline().split()
        if len(tmp) == 1:
            hanten ^= 1
        else:
            if hanten: # 反対ver
                if tmp[1] == '1':
                    back += tmp[2]
                else:
                    front += tmp[2]
            else: # 正常
                if tmp[1] == '1':
                    front += tmp[2]
                else:
                    back += tmp[2]

    if hanten == 0:
        print(front[::-1] + s + back)
    else:
        print((front[::-1] + s + back)[::-1])

if __name__ == '__main__':
    main()
