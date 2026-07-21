import sys
from collections import defaultdict
def input(): return sys.stdin.readline().strip()


def main():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    """
    2つのリストの関係を調べる云々は「二部グラフの完全マッチング問題」というカテゴリ名で呼ばれる。
    そしてこれに対しては「Hallの定理」というのが有効らしい。高校数学の美しい物語参照。

    特に大事なのがHall条件と呼ばれる方で、一見これはAの全ての部分集合を見ないといけないが
    部分集合のサイズが大きいと即座に|A| ¥subset |¥Gamma(A)|となるケースが多いよう？

    本問ではAが同一の元のみからなるケースのみ考えればよく（maspyさんブログ参照）、
    任意のx¥in Aに対して|{i|ai == x}| + |{i|bi == x}| <= Nが成り立てば答えはYesとなる。

    実際の二部グラフの構成方法は、|{i|ai == x}| + |{i|bi == x}|が大きいxから順にペアを作れば良い。

    ここで実装の注意点として、たくさん出てくる数から優先的に処理しないといけないが、
    ここにheapqを使うと２回ポップして出てきた数同士でペアを作る発想になるものの、
    一方からポップした数がBに存在しない等の場合何度もポップしてBにその数が含まれるかチェックすることになり
    非常に非効率になる。なのでheapqは使ってはいけない。

    なのでここでは
        hist[(出てきた回数)]=(その回数A+Bから出てくる数の集合)
    としてhistはリストで管理しないといけない。

    これむずすぎん？？？必要なデータ構造多すぎて訳わからんくなる。
    """
    num_kinds = defaultdict(int)
    hist = [set() for _ in range(N + 1)]
    for x in A + B: num_kinds[x] += 1
    for x, times in num_kinds.items():
        if times > N:
            print("No")
            return
        hist[times].add(x)
    print("Yes")

    num_to_idx_A = defaultdict(set)
    num_to_idx_B = defaultdict(set)
    num_to_cnt_A = defaultdict(int)
    num_to_cnt_B = defaultdict(int)
    for i, a in enumerate(A):
        num_to_idx_A[a].add(i)
        num_to_cnt_A[a] += 1
    for i, b in enumerate(B):
        num_to_idx_B[b].add(i)
        num_to_cnt_B[b] += 1


    B_new = [0] * N
    for times in range(N, 0, -1):
        nums = list(hist[times])
        l = len(nums)
        x, y = -1, -1
        if l == 2:
            x, y = nums
            for idxA in num_to_idx_A[x]: B_new[idxA] = y
            for idxA in num_to_idx_A[y]: B_new[idxA] = x
            break
        elif l == 1:
            x = nums[0]
            if num_to_idx_A[x]:
                y = -1
                for num in num_to_cnt_B:
                    if num != x:
                        y = num
                        break
            else:
                y = x
                x = -1
                for num in num_to_cnt_A:
                    if num != y:
                        x = num
                        break
        elif l == 0:
            x = -1
            for num in num_to_cnt_A:
                x = num
                break
            y = -1
            for num in num_to_cnt_B:
                if num != x:
                    y = num
                    break

        idxA = num_to_idx_A[x].pop()
        B_new[idxA] = y
        num_to_idx_B[y].pop()

        num_to_cnt_A[x] -= 1
        num_to_cnt_B[y] -= 1
        if num_to_cnt_A[x] == 0: del num_to_cnt_A[x]
        if num_to_cnt_B[y] == 0: del num_to_cnt_B[y]

        hist[num_kinds[x]].discard(x)
        hist[num_kinds[y]].discard(y)
        num_kinds[x] -= 1
        num_kinds[y] -= 1
        hist[num_kinds[x]].add(x)
        hist[num_kinds[y]].add(y)

    print(" ".join(map(str, B_new)))



if __name__ == "__main__":
    main()
