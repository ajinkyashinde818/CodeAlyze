import java.util.Scanner;
 
class Main {
	int k;
	int s;
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		Main m = new Main(sc);
		m.solve();
		sc.close();
	}
	Main(Scanner sc){
		k = sc.nextInt();
		s = sc.nextInt();
	}
	void solve(){
		int ans = 0;
		for(int x=0;x<=k;x++){
			for(int y=0;y<=k;y++){
				if((s-(x+y)<=k)&&(s-(x+y)>=0)) ans++;
			}
		}
		System.out.println(ans);
	}
}
