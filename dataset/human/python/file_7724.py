def ri(): return int(input())
def rli(): return list(map(int, input().split()))
def ris(): return list(input())
def pli(a): return "".join(list(map(str, a)))

x = ri()
print("ABC" if x < 1200 else "ARC")
