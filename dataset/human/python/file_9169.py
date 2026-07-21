import sys
sys.setrecursionlimit(10 ** 6)
S = input()
def func(i):
    if i >= len(S):
        return True
    if (S[i:i+5] == 'dream' or S[i:i+5] == 'erase') and func(i + 5):
        return True
    if (S[i:i+7] == 'dreamer') and func(i + 7):
        return True
    if (S[i:i+6] == 'eraser') and func(i + 6):
        return True
    return False

print('YES' if func(0) else 'NO')
