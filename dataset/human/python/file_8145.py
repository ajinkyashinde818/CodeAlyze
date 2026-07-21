def solve(K, S):
    import bisect
    count = 0
    z_array = [i for i in range(K+1)]
    for x in range(K+1):
        for y in range(K+1):
                z = S - x - y
                if(z >= 0 and z <= K):count+=1
    return count

def main():
    K, S = map(int, input().split())
    print(solve(K, S))
#print(solve(2, 2))
#print(solve(5, 15))
main()
