import java.util.Scanner;

public class Main {
    static public void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int zoro = 0;
        boolean ok = false;
        
        int N = sc.nextInt();
        
        for(int i = 0 ; i < N ; i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            if(x == y){
                zoro++;
                if(zoro >= 3){
                    ok = true;
                }
            }else{
                zoro = 0;
            }
        }

        System.out.println(ok? "Yes" : "No");
    }
}
