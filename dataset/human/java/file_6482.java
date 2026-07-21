import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int S = sc.nextInt();
        int count = 0;
        for(int i=0;i<=K;i++){
            for(int j=0;j<=i;j++){
                for(int k=0;k<=j;k++){
                    int a = i+j+k;
                    if(a == S){
                        if(i == j && j== k){
                            count ++;
                        }else if(i != j && j != k && k != i){
                            count += 6;
                        }else{
                            count += 3;
                        }
                    }
                }
            }
        }
        System.out.println(count);
    }
}
