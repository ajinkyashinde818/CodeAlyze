def actual(K, S):
    my_range = lambda n: range(n + 1)

    count = 0

    for x in my_range(K):
        for y in my_range(K):
            z = S - (x + y)
            if 0 <= z <= K:
                count += 1
    return count

  
K, S = map(int, input().split())

print(actual(K, S))
