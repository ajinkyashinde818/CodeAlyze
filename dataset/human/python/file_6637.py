import sys
input = lambda: sys.stdin.readline().rstrip()
input_nums = lambda: list(map(int, input().split()))

s = input()
n = int(input())
front = ''
end = ''
front_flag = True # Trueの場合frontがfront Falseの場合endがfront
for i in range(n):
    q = input()
    if len(q) == 1:
        front_flag = not front_flag
    else:
        _, f, c = q.split()
        if f == '1':
            if front_flag:
                front += c
            else:
                end += c
        else:
            if not front_flag:
                front += c
            else:
                end += c

if front_flag:
    s = front[::-1] + s + end
else:
    s = end[::-1] + s[::-1] + front

print(s)
