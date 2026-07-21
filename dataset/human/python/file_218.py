from sys import stdout
def main():
    n = int(raw_input())
    k = 1
    while k * (k - 1) / 2 < n:
        k += 1
    if k * (k - 1) / 2 != n:
        print "No"
        return
    ans = [[n * 2 / k] for _ in xrange(k)]
    c = 0
    for i in xrange(k):
        for j in xrange(i + 1, k):
            c += 1
            ans[i].append(c)
            ans[j].append(c)
    stdout.write('Yes\n')
    stdout.write(str(k) + '\n')
    for l in ans:
        stdout.write(' '.join(map(str, l)))
        stdout.write('\n')
main()
