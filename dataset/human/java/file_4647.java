import java.util.Scanner;
public class Main {
	Scanner in = new Scanner(System.in);
	public static void main(String[] args) {
		new Main();
	}
	public Main() {
		new AOJ0181().doIt();
	}

	class AOJ0181{
		int m,n;
		int[] books;
		
		boolean isPossible(int width){
			int w=0,cnt=1;
			for(int i=0;i<n;i++){
				w+=books[i];
				if(books[i]>width)return false; 
//				System.out.println(books[i]);
				if(w>width){
//					System.out.println("---");
					cnt++;
					w = books[i];
				}
			}
			return cnt>m? false:true;
		}
		
		void doIt(){
			//横幅が可変
			//n = num of book
			//m = 段数
			while(true){
				m = in.nextInt();
				n = in.nextInt();
				if(n+m==0)return;
				books = new int[n];
				for(int i=0;i<n;i++)books[i] = in.nextInt();
//				System.out.println(isPossible(733));
				int left = 1;
				int right = 1500000;
				while(right-left!=1){
					int next = (left+right)/2;
					if(isPossible(next))right = next;
					else left = next;
//					System.out.println(left+" "+right);
				}
				System.out.println(right);
			}
		}
	}

}
