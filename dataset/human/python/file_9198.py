import sys

input = sys.stdin.readline

dct = ['dream', 'dreamer', 'erase', 'eraser']
rdct = [''.join(reversed(x)) for x in dct]

def main():
    S = input()[:-1]
    rS = ''.join(reversed(S))

    fr = 0
    for _ in range(20005):
        flag = False
        for d in rdct:
            to = fr + len(d)
            if d == rS[fr:to]:
                fr = to
                flag = False
                break
            flag = True
        if flag:
            break
    
    if fr == len(S):
        print('YES')
    else:
        print('NO')
    
if __name__ == "__main__":
    main()
