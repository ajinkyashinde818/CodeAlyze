import java.util.*;

public class Main{
    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int d1=0, d2=0;
	int ans=0;

	for(int i=0; i<N; i++){
	    d1 = sc.nextInt();
	    d2 = sc.nextInt();
	    if(d1==d2 || ans>=3){
		if(ans>=3)continue;
		ans++;
	    }else ans=0;
	}
	if(ans>=3)System.out.println("Yes");
	else System.out.println("No");
    }
}
