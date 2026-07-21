import collections
N = int(input())
counter = 0
if N == 1:
  print(0)
  exit()
def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a

def cc(n):
    ans = 0
    i = 1
    while True:
        n = n - i
        ans += 1
        i += 1
        if n < i:
            break
    return ans

s_list = prime_factorize(N)
c = collections.Counter(s_list)
values,counts = zip(*c.most_common())
j = 0
for i in range(len(counts)):
    counter += cc(counts[i])
print(counter)
