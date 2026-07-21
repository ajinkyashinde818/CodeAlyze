import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        String[] line = sc.nextLine().split(" ");

        int K = Integer.parseInt(line[0]);
        int S = Integer.parseInt(line[1]);

        int ans = 0;
        for(int x = 0;x <= K;x++){
            for(int y = 0;y <= K;y++){
                    int target = S -x - y;
                    if(target >= 0 && target <= K){
                        ans++;
                    }
            }
        }    
        System.out.println(ans);
    }
}
