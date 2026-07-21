import java.io.BufferedReader;
import java.io.InputStreamReader;


/*
 旅行先のパーティ

八重さんは、旅行先で何度か行われるパーティに出席することになりました。パーティでは１回につき１着、ドレスを身に付ける必要があります。旅行には何着かドレスを持っていきますが、パーティの回数よりもドレスの枚数が少ない場合、すべてのパーティに出席するには、同じドレスを何回か身に付ける必要があります。

おしゃれな八重さんは、同じドレスを何回も着たくありません。一番多く使うドレスを着る回数をなるべく少なくしたいと考えています。

ドレスの枚数とパーティの回数が与えられる。一番多く使うドレスを着る回数をなるべく少なくしたときに、そのドレスを何回着なければならないかを計算するプログラムを作成せよ。

入力
A B
１行にドレスの枚数A (1≤A≤105) とパーティの回数B (1≤B≤105)が与えられる。

出力
一番多く使うドレスを何回着なければならないかを、１行に出力する。

入出力例
入力例１
3 5
出力例１
2



 */

/**
 * URL
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0392&lang=ja
 */

class Main{

	public static void main(String[] args) throws Exception {
		try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
			String[] data = reader.readLine().split(" ");
			Integer numDress = Integer.parseInt(data[0]);
			Integer numParty = Integer.parseInt(data[1]);

			Integer result = numParty / numDress;
			if(numParty % numDress > 0) result += 1;

			System.out.println(result);

		}
	}
}
