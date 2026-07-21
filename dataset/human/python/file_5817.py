def func():
    N = int(input())
    A = list(map(lambda x: int(x) -1, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))

    prevIdx = -1
    value = 0
    for i in A:
        value += B[i]
        if prevIdx != -1 and prevIdx + 1 == i:
            value += C[i-1]
        
        prevIdx = i

    print(value)

if __name__ == '__main__':
    func()
