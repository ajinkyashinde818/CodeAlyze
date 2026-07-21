import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
	int n;
	String[] s;
	int[] d;

	public static void main(String[] args) throws FileNotFoundException {
//		System.setOut(new PrintStream(new File(System.currentTimeMillis()/1000+".txt")));

		new Main().run();
	}

	private void run() {
		Scanner sc = new Scanner(System.in);

		while(true){
			s = new String[1000];
			d = new int[1000];

			n = sc.nextInt();

			if(n==0) return;
			sc.nextLine();

			for(int i=0;i<n;i++){
				s[i] = sc.nextLine();
				for(int j=0;j<s[i].length();j++){
					if(s[i].charAt(j)!='.'){
						d[i] = j;
						break;
					}
				}
				s[i] = s[i].replace(".", "");
			}

			for(int i=0;i<n;i++){
				for(int j=0;j<d[i];j++){
					if(j==d[i]-1){
						System.out.print("+");
					}
					else{
						int x = -1, y = -1;
						for(int p=i-1;p>=0;p--){
							if(j==d[p]-1){
								x = p;
								break;
							}
							else if(j>d[p]-1){
								break;
							}
						}
						for(int q=i+1;q<n;q++){
							if(j==d[q]-1){
								y = q;
								break;
							}
							else if(j>d[q]-1){
								break;
							}
						}
//						System.out.println("i="+i+",j="+j+",x="+x+",y="+y);
						if(x==-1||y==-1){
							System.out.print(" ");
						}
						else if(y-x>=2){
							System.out.print("|");
						}
						else{
							System.out.print(" ");
						}
					}
				}
				System.out.println(s[i]);
			}
		}
	}

}
