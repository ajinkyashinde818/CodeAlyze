import scipy as sp

k, n = list(map(int, input().split()))
a_list = list(map(int, input().split()))

a_list = sp.array(a_list)
sub_a_list = (a_list - sp.roll(a_list, 1))[1:]
sub_a_list = sp.append(sub_a_list, a_list[0]+k-a_list[-1])
print(k-max(sub_a_list))
