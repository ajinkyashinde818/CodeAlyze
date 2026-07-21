import java.util.*;
public class Main{
	static boolean Anag(String s, String t){
		HashMap<Character, Integer> map = new HashMap<>();
		map.put('a', 1);
		map.put('b', 2);
		map.put('c', 3);
		map.put('d', 4);
		map.put('e', 5);
		map.put('f', 6);
		map.put('g', 7);
		map.put('h', 8);
		map.put('i', 9);
		map.put('j', 10);
		map.put('k', 11);
		map.put('l', 12);
		map.put('m', 13);
		map.put('n', 14);
		map.put('o', 15);
		map.put('p', 16);
		map.put('q', 17);
		map.put('r', 18);
		map.put('s', 19);
		map.put('t', 20);
		map.put('u', 21);
		map.put('v', 22);
		map.put('w', 23);
		map.put('x', 24);
		map.put('y', 25);
		map.put('z', 26);
		int[] sh = new int[s.length()];
		int[] th = new int[t.length()];
		for(int i=0; i<s.length(); i++){
			sh[i] = map.get(s.charAt(i));
		}
		for(int i=0; i<t.length(); i++){
			th[i] = map.get(t.charAt(i));
		}
		Arrays.sort(sh);
		Arrays.sort(th);
		for(int i=0; i<=(t.length())/2; i++){
			int thh = th[i];
			th[i] = th[t.length()-1-i];
			th[t.length()-1-i] = thh;
		}
		for(int i=0; i<Math.min(s.length(), t.length()); i++){
			if(sh[i]<th[i])return true;
			if(sh[i]>th[i])return false;
		}
		if(s.length()>=t.length())return false;
		return true;
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		String T = sc.next();
		System.out.println(Anag(S, T)==true ? "Yes" : "No");
	}
}
