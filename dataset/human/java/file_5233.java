import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
 


public class Main {
	private static Scanner sc = new Scanner(System.in);
	//result = Math.pow(num1, num3)
	//StringBuffer str = new StringBuffer(hoge1);
	//String hoge2 = str.reverse().toString();
	//map.containsKey(A)

	//Map<String, Integer> map = new HashMap<String, Integer>(n);
	/*for ( キーのデータ型 key : マップの名前.keySet() ) {
		データのデータ型 data = マップの名前.get( key );
		
		// keyやdataを使った処理;
	}*/
	//int i = Integer.parseInt(s);
	//Queue<String> qq=new ArrayDeque<>(); //add,poll,peek
	//Deque<String> qq=new ArrayDeque<>();//push,pop,peek
	//ArrayList<String> cc = new ArrayList<>(n);
	//Collections.sort(list);
	//Array.sort(list);   cc.contains(tmp)
	//Arrays.asList(c).contains("a")
	//list.set(1,"walk");//1 1 2 3 5
	//static long mod =1000000007;
	//static 	ArrayList<Integer> cc = new ArrayList<>(100);
	
	
	
	public static void main(String[] args) {
		//int N=sc.nextInt();for(int i=0;i<N;i++) {}
		//M 77 || //A 65 || //R 82 || //C 67 || //H 72 || 
		StringBuffer S = new StringBuffer(sc.next());
		
		StringBuffer Su = new StringBuffer();
		
		int Q=Integer.parseInt(sc.next());
		
		int t,f;
		String C;
		boolean x=true;
		for(int i=0;i<Q;i++) {
			t=Integer.parseInt(sc.next());
			if(t==1) {
				if(x)x=false;
				else x=true;
				
			}else {
				f=Integer.parseInt(sc.next());
				C=sc.next();
				if(f==1) {
					if(x) {
						Su.append(C);
					}else {
						S.append(C);
					}
				}else {
					if(x) {
						S.append(C);
					}else {
						Su.append(C);
					}
				}
				
				
			}

		}
		Su.reverse();
		S.insert(0, Su);
		if(x) {
			p(S.toString());
		}else {
			S.reverse();
			p(S.toString());
		}

		
	
		
		
	}



	
	
	
	

	


	
	static void p(String ans) {System.out.println(ans);};
	static void p(int ans) {System.out.println(ans);};
	static void p() {System.out.println();};
	static void p(long ans) {System.out.println(ans);};
	static void p(double ans) {System.out.println(ans);};
	
}
