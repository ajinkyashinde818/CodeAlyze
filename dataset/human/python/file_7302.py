def main():
    S = input()
    Q = int(input())
    count = 0
    A = []
    B = []
    for _ in range(Q):
        U = input()
        if len(U) == 1:
            count += 1
        else:
            _, F, C = U.split()
            F = int(F)
            if F == 1:
                if count % 2 == 0:
                    A.append(C)
                else:
                    B.append(C)
            else:
                if count % 2 == 0:
                    B.append(C)
                else:
                    A.append(C)

    if count % 2 == 0:
        A = A[::-1]
        return "".join(A) + S + "".join(B)
    else:
        B = B[::-1]
        return "".join(B) + S[::-1] + "".join(A)
        
if __name__ == '__main__':
    print(main())
