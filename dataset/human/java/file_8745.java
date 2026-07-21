import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	int A = sc.nextInt();
       	int B =sc.nextInt();
       	int K =sc.nextInt();
       	ArrayList<Integer> array = new ArrayList<>();

       	for(int i =1 ;i<=100;i++){
       		if(A %i ==0 & B%i ==0){
       			array.add(i);
       		}
       	}
       	Collections.sort(array, Comparator.reverseOrder());

       	System.out.println(array.get(K-1));

}
}
