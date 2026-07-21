import java.util.Scanner;


public class Main{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int[] dish = new int[n];
        int[] gain = new int[n];
        int[] bonus = new int[n-1];
        for(int i=0;i<n;i++){
            dish[i] = Integer.parseInt(sc.next());
        }
        for(int i=0;i<n;i++){
            gain[i] = Integer.parseInt(sc.next());
        }
        for(int i=0;i<n-1;i++){
            bonus[i] = Integer.parseInt(sc.next());
        }

        int sum = 0;
        int prev = n+1;
        for(int i=0;i<n;i++){
            sum += gain[dish[i]-1];
            if(dish[i]==(prev+1)){
                sum += bonus[prev-1];
            }
            prev = dish[i];
        }
        System.out.println(sum);
    }
}
