import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        int k = scan.nextInt();
        int s = scan.nextInt();
        //System.out.println("k = " + k);
        //System.out.println("s = " + s);
        if(k >= s){
            System.out.println((s + 2) * (s + 1) / 2);
        }else{
            int ans = 0;
            for(int x = 0; x <= k; x++){
                for(int y = 0; y <= k; y++){
                    int z = s - x - y;
                    if(z >= 0 && z <= k){
                        ans++;
                    }
                }
            }
            System.out.println(ans);
        }
    }
}
