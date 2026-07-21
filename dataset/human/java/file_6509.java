import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int k = Integer.parseInt(sc.next());
		int s = Integer.parseInt(sc.next());
		int count = 0;
      	for(int i = 0; i <= k; i++){
          	for(int j = 0; j <= k; j++){
          		int z = s-i-j;
          		if(z >=0 && z<=k) {
          			count++;
          		}
          	}
      	}
      			System.out.println(count);
	}
}
