import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		//String tmp = sc.next();
		//int tmp = sc.nextInt();
		//Long tmp = sc.nextLong();
      int A = sc.nextInt();
      int B = sc.nextInt();
      int K = sc.nextInt();
      ArrayList<Integer> aList = new ArrayList<Integer>(A);
      ArrayList<Integer> bList = new ArrayList<Integer>(B);
      for(int i = 1; i <= A; i++){
        if(A % i == 0){
          aList.add(i);
        }
      }
      for(int i = 1; i <= B; i++){
        if(B % i == 0){
          bList.add(i);
        }
      }
      //System.out.println(aList);
      //System.out.println(bList);
      for(int i = 0; i < aList.size(); i++){
        if(bList.indexOf(aList.get(i)) == -1){
          aList.remove(aList.get(i));
          i--;
        }
      }
      //System.out.println(aList);
      System.out.println(aList.get(aList.size() - K));
	}
}
