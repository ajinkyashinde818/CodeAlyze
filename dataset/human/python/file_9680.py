def main():
    n,k = map(int, input().split())
    town = list(map(int, input().split()))
    town = [i-1 for i in town]
    visited = [-1] * n
    current_town = 0
    current_order = 0
    memo = []
    while visited[current_town] == -1:
        visited[current_town] = current_order
        memo.append(current_town)
        current_town = town[current_town]
        current_order += 1
    loop_start = visited[current_town]
    if k < len(memo):
        print(memo[k]+1)
    else:
        loop_length = len(memo) - loop_start
        k =  (k - loop_start) % loop_length
        print(memo[k+loop_start]+1)
if __name__ == '__main__':
    main()
