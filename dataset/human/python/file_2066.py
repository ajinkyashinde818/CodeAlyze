from collections import defaultdict

if __name__ == '__main__':
    mod = 10**9 +7
    N = int(input())
    S = str(input())

    letter = defaultdict(int)
    letter_count = defaultdict(int)
    count = 0
    for i in range(N):
        new_count = count + 1
        new_count -= letter[S[i]] #今まで追加文字が使われている組み合わせはNG
        count += new_count
        letter[S[i]] += new_count #追加文字が追加されたことによる組み合わせ増分を増やす
        #追加文字による、他のある文字が使われる組み合わせの増加は
        #今まである文字が使われていた組み合わせの数-ある数が使われていてかつ追加文字が含まれている組み合わせ
        for key in letter:
            if key != S[i]:
                letter[key] += letter[key]//(1 + letter_count[S[i]])
        letter_count[S[i]] += 1
    print(count%mod)
