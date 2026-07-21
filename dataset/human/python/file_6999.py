import bisect

def main():
    s = input()
    qc = int(input())
    front = ""
    back = ""
    direct = 1
    for _ in range(qc):
        t = input()
        if t[0] == "1":
            direct = 2 if direct == 1 else 1
        else:
            _,f,c = t.split()
            if f == "1":
                if direct == 1:
                    front += c
                else:
                    back += c
            else:
                if direct == 1:
                    back += c
                else:
                    front += c
    if direct % 2 == 0:
        print((s+back)[::-1] + front)
    else:
        print(front[::-1]+s+back)
    
if __name__ == "__main__":
    main()
