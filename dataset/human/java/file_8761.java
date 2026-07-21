import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
        int B = sc.nextInt();
        int K = sc.nextInt();
      
		ArrayList<Integer> al = new ArrayList<>();
      
      	Integer min = A;
      	if(A>B){
          min = B;
        }
      	for(int i = 1; i < min+1; i++){
          	if((A%i==0)&&(B%i==0)){
              al.add(i);
            }
        }
		System.out.println(al.get(al.size()-K));
	}
}
