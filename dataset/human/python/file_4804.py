S = list(input())
T = list(input())

S.sort()
T.sort(reverse=True)

def cmp(A, B):
    for i in range(min(len(A), len(B))):
        if A[i] < B[i]:
            return True

        elif A[i] > B[i]:
            return False

    if len(A) < len(B):
        return True

    return False



if cmp(S, T):
    print('Yes')
else:
    print('No')
