import sys
from collections import Counter
input = sys.stdin.readline

def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    judge_a = Counter(a)
    judge_b = Counter(b)
    judge = judge_a + judge_b
    
    flag = True
    for v in judge.values():
        if v > n:
            flag = False
    
    if flag:
        i, j = 0, 0

        cycle = 0
        while i < n and j < n:
            ii, jj = i, j
            if a[i] < b[j]:
                i += 1
                continue
            if a[i] > b[j]:
                j += 1
                continue
            if a[i] == b[j]:
                while i < n-1 and a[i] == a[i+1]:
                    i += 1
                while j < n-1 and b[j] == b[j+1]:
                    j += 1
            cycle = max(cycle, i-jj+1)
            i += 1
            j += 1
        
        ans = [0]*n
        for i in range(n):
            ans[(i+cycle)%n] = b[i]
        
        for i in range(n):
            if a[i] == ans[i]:
                print("No")
                sys.exit()
        print("Yes")
        print(*ans)
    else:
        print("No")

if __name__ == "__main__":
    main()
