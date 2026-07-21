import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
  	long k=sc.nextLong();
  	int n=sc.nextInt();
  	long[] ai=new long[n];
  	for(int i=0;i<n;i++){
  		ai[i]=sc.nextLong();
  	}
  	long s=0;
  	long[] si=new long[n];
  	for(int i=0;i<n;i++){
  		if(i==n-1){
  			si[i]=k+ai[0]-ai[i];
  		}else{
  			si[i]=ai[i+1]-ai[i];
  		}
  	}
  	Arrays.sort(si);
  	for(int i=0;i<n-1;i++){
  		s+=si[i];
  	}
  	System.out.print(s);
  }
}
