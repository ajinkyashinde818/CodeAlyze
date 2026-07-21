import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		//String tmp = sc.next();
		//int tmp = sc.nextInt();
		//Long tmp = sc.nextLong();
      int N = sc.nextInt();
      int M = sc.nextInt();
      Set<Integer> oneList = new HashSet<>();
      Set<Integer> NList = new HashSet<>();
      for(int i = 0; i < M; i++){
        int mae = sc.nextInt();
        int ato = sc.nextInt();
        if(mae == 1){
          oneList.add(ato);
        }
        if(ato == N){
          NList.add(mae);
        }
      }
      if(oneList.isEmpty() || NList.isEmpty()){
        System.out.println("IMPOSSIBLE");
        return;
      }
      for(int i = 2; i < N; i++){
        if(oneList.contains(i) && NList.contains(i)){
          System.out.println("POSSIBLE");
          return;
        }
      }
      System.out.println("IMPOSSIBLE");
	}
}
