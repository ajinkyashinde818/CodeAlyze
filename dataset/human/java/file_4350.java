import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int elements = sc.nextInt();
        int[] order = new int[elements];
        for (int i = 0; i < elements; i++) {
            order[i] = sc.nextInt()-1;
        }
        int[] point = new int[elements];
        for (int i = 0; i < elements; i++) {
            point[i] = sc.nextInt();
        }
        int[] bonus = new int[elements-1];
        for (int i = 0; i < elements-1; i++) {
            bonus[i] = sc.nextInt();
        }
        
        solve(order,point,bonus);
    }

    public static void solve(int[] order,int[] point,int[] bonus){
        int result = 0;
        int prev = order.length;
        for(int now:order){
            result += point[now];
            if(now-prev==1){
                result += bonus[prev];
            }
            prev = now;
        }
        System.out.println(result);
    }
}
