import java.util.*;

public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		char[] s = sc.next().toCharArray();
		char[] t = sc.next().toCharArray();
		//sを正順にソートして、tを逆順にソートする
		Arrays.sort(s);
		Arrays.sort(t);
		t = reverce(t);
		boolean getedAnser = false;
		//sとtの中身が要素数まで全く同じならば、NOを出力
		if(equal(t, s)){
			System.out.println("No");
		}else{
			//要素をはじめから比べて、tが辞書順で上になったらYesを出力する
			for(int i = 0;i < t.length && i < s.length; i++){
				if((int)s[i] < (int)t[i]){
					System.out.println("Yes");
					getedAnser = true;
					break;
				}else if((int)t[i] < (int)s[i]){
					System.out.println("No");
					getedAnser = true;
					break;
				}
			}
	//ここまで要素が一切同じで、どちらかの要素がそれより長い、tのほうがながければ辞書順で上になれる
			if(s.length < t.length && !getedAnser){
				System.out.println("Yes");
			}else if(!getedAnser){
				System.out.println("No");
			}
		}
	}

	public static char[] reverce(char[] c){
		//char並列の中身を逆順にする
		char[] t = new char[c.length];
		for(int i = (c.length - 1);0 <= i; i--){
			t[c.length - i - 1] = c[i];
		}
		return t;
	}

	public static boolean equal(char[] t, char[] s){
		//渡された配列の中身が同じかどうかを判断する。
		//まず要素数が違えばfalseを返す。
		if(t.length == s.length){
			for(int i = 0;i < t.length; i++){
				if(t[i] != s[i]){
					return false;
				}
			}
			return true;
		}else{
			return false;
		}
	}
}
