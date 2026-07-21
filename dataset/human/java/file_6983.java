import java.util.Scanner;
public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int max = 0;
        int stac = 0;
        int first = sc.nextInt();
        int next = 0;
        stac = first;
        for(int i=0;i<n-1;i++){
            next = sc.nextInt();
            if((next - first)>max){
                max = next - first;                
            }
            first = next;
        }
        if((k + stac - next)>max){
            max = k + stac - next;
        }
        sc.close();
        System.out.println(k - max);
    }
}
