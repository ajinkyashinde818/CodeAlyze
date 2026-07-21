def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

if __name__ == "__main__":
    K, N = MI()
    A = LI()
    a = []
    for i in range(N):
        if i != N-1:
            a.append(abs(A[i]-A[i+1]))
        else:
            a.append(abs(A[i]-K-A[0]))
    a.remove(max(a))
    print(sum(a))
