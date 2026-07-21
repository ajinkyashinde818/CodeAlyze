N = int(input())
S = input()


def char_to_int(c):
    return ord(c) - 97


char_counts = [0 for _ in range(26)]
for c in S:
    i = char_to_int(c)
    char_counts[i] = char_counts[i] + 1

ans = 1
for i in char_counts:
    ans = ans * (i + 1)
ans = (ans - 1) % (10 ** 9 + 7)
print(ans)
