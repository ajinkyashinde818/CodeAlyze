import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try (Scanner scan = new Scanner(System.in)) {
          int num = scan.nextInt();
          int Bsum = 0;
          List<Integer> array = new ArrayList<>();
			List<Integer> Carray = new ArrayList<>();
          
          for (int i = 0; i < num; i++) {
				int a = scan.nextInt();
				array.add(a);
			}
          
          for (int i = 0; i < num; i++) {
				int a = scan.nextInt();
				Bsum += a;
			}
          
          for (int i = 0; i < num-1; i++) {
				int a = scan.nextInt();
				Carray.add(a);
			}
          
          for(int i=1; i<array.size(); i++) {
           		 if(array.get(i-1) == array.get(i)-1) {
                   Bsum += Carray.get(array.get(i-1)-1);
                 }
          }
          
          System.out.println(Bsum);
        }
    }
}
