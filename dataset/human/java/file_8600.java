import java.util.*;
public class Main {
	public static void main(String[] args){
      	//データ取り込み
		Scanner sc = new Scanner(System.in);
      	ArrayList<Integer> list = new ArrayList<Integer>();
      	
		int A = sc.nextInt();
      	int B = sc.nextInt();
      	int K = sc.nextInt();
        for(int i=1;i<A+1;i++){
        	if(A%i==0 &&B%i==0){
            	list.add(i);
            }
        }
       Collections.reverse(list);
      	
          System.out.println(list.get(K-1)); 
        
		     
      
    }
}
