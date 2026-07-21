R, G, B, N = [int(a) for a in input().split()]

def func(n, boxes):
    b = boxes[0]

    if len(boxes) == 1:
        return 1 if n % b == 0 else 0
    else:
        return sum([func(n - i, boxes[1:]) for i in range(0, n+1, b)])
    
arr = [R, G, B]
arr.sort()
result = func(N, arr)

print(result)
