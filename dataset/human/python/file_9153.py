def two_int():
    N, K = map(int, input().split())
    return N,K

def one_int():
    return int(input())

def one_str():
    return input()

def many_int():
    return list(map(int, input().split()))

S = one_str()

w_list = [ "dream", "dreamer", "erase", "eraser" ]

flg=True
while len(S) != 0:
    if S[-7:] =="dreamer":
        S = S[:-7]
        continue

    elif S[-6:] =="eraser":
        S = S[:-6]
        continue

    elif S[-5:] =="dream" or S[-5:] =="erase":
        S = S[:-5]
        continue
    
    flg = False
    break


if flg:
    print("YES")
else:
    print("NO")
