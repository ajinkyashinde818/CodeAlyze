import sys
input = sys.stdin.readline
def print_ans(N,A,B,C):
    """Test Case
    >>> print_ans(3,"3 1 2","2 5 4","3 6")
    14
    >>> print_ans(4,"2 3 4 1","13 5 8 24","45 9 15")
    74
    >>> print_ans(2,"1 2","50 50","50")
    150
    """
    A_arr = list(map(int,A.split()))
    B_arr = list(map(int,B.split()))
    C_arr = list(map(int,C.split()))
    ans = sum(B_arr)
    for i in range(N - 1):
        if A_arr[i] + 1 == A_arr[i + 1]:
            ans += C_arr[A_arr[i] - 1]
    print(ans)
if __name__ == '__main__':
    N = int(input().rstrip())
    A = input().rstrip()
    B = input().rstrip()
    C = input().rstrip()
    print_ans(N,A,B,C)
