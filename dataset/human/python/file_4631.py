al = [chr(c) for c in range(ord('A'), ord('Z') + 1)] + [chr(c) for c in range(ord('a'), ord('z') + 1)] 

def f1(c):
    if 'A' <= c <= 'Z':
        return ord(c) - ord('A')
    return ord(c) - ord('a') + ord('Z') - ord('A') + 1
while True:
    if not int(input()):
        break
    k = list(map(int, input().split()))
    s = list(map(f1, input()))
    print(''.join([al[c - k[i % len(k)]]  for i, c in enumerate(s)]))
