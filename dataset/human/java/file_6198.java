import java.util.*;
public class Main {
	public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int K = sc.nextInt();
      int S = sc.nextInt();
      int count=0;
      for(int x=0;x<=K && x<=S;x++){
        for(int y=0;y<=K && y<=S;y++){
	          if(S-x-y>=0 && S-x-y<=K){
                count++;
              }
        }
      }
      System.out.println(count);
    }
}
