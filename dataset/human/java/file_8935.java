import java.util.*;

class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		int m = Math.min(a,b);
		int cou = 0;
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int i = 1; i < m+1; i++){
			if(a%i == 0 && b%i == 0){
				list.add(i);
				cou++;
			}
		}
		Collections.sort(list);
		Collections.reverse(list);
		System.out.print(list.get(k-1));
	}
}
