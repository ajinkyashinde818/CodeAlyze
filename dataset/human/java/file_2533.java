import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String A = sc.nextLine();
        String B = sc.nextLine();
        String A_new = null;
        String B_new = null;
        String []A_array = A.split("");
        String []B_array = B.split("");
        Arrays.sort(A_array);
        Arrays.sort(B_array,Comparator.reverseOrder());
        for(int i = 0; i < A_array.length; i++){
            A_new += A_array[i];
        }
        for(int i = 0; i < B_array.length; i++){
            B_new += B_array[i];
        }
        if(A_new.compareTo(B_new) < 0){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}
