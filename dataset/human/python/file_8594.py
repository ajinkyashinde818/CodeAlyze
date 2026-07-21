S = input().split(" ")
K = int(S[0])
N = int(S[1])
ARR = [int(s) for s in input().split(" ")]


def calculate(k,n,arr):
    result = []
    for i in range(n-1):
        s = arr[i+1] - arr[i]
        m = k - s
        result.append(m)

    result.append(arr[n-1] - arr[0])

    print(min(result))


calculate(K,N,ARR)
