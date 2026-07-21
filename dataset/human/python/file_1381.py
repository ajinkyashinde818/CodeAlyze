def main():
    _ = int(input())
    a = [int(s) for s in input().split()]
    print(solve(a))

def solve(a):
    s = sum(a)
    x = 0
    m = float('inf')

    for i in a[:-1]:
        x += i
        y = s - x
        m = min(m, abs(x - y))
    
    return m

main()
