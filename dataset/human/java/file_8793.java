import java.util.*;
public class Main{
	public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int a = sc.nextInt();
      int b = sc.nextInt();
      int k = sc.nextInt();
      int[] surp = new int[Math.min(a,b)+1];
      for(int i = 1;i <= Math.min(a,b);i++){
      	if(a%i == 0 && b%i == 0){
        surp[i] = i;
        }
      }
      Arrays.sort(surp);
      System.out.println(surp[Math.min(a,b)-k+1]);
    }
}
