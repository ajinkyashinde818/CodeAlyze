def qsort(array):
    if len(array) < 2:
        return array
    else:
        pivot = array[0]
        less = [i for i in array[1:] if i <= pivot]
        greater = [i for i in array[1:] if i > pivot]
        return qsort(less) + [pivot] + qsort(greater)

si = input()
ti = input()

s_sort = qsort(si)
t_sort = qsort(ti)

s = ''
t = ''

for i in s_sort:
    s += i
for i in t_sort[::-1]:
    t += i
if s < t:
    print('Yes')
else:
    print('No')
