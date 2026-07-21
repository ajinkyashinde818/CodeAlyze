import java.util.Scanner;
 
public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N=sc.nextInt();
    int X[] = new int[N];
    int Y[] = new int[N];
    for (int i = 0; i < N; i++) {
        X[i] = sc.nextInt();
        Y[i] = sc.nextInt();
    }
    int ans=0;
    for (int i = 0; i < N-2; i++) {
    	if(X[i]==Y[i]&&X[i+1]==Y[i+1]&&X[i+2]==Y[i+2]) {
    		ans++;
    	}
    }
    if(ans>0) {
    	System.out.println("Yes");
    }else {
    	System.out.println("No");
    }
  }
}
