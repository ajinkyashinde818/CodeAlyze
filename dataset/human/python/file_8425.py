from sys import stdin

k,n = [int(x) for x in stdin.readline().strip().split()]
a_lst = [int(x) for x in stdin.readline().strip().split()]
diff_lst = [a_lst[i+1] - a_lst[i] for i in range(len(a_lst)-1)] + [k - a_lst[-1] + a_lst[0]]

print(k - max(diff_lst))
