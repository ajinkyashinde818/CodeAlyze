import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int count = 0;
        int max = 0;
        for(int i=0;i<N;i++){
            if(sc.nextInt()==sc.nextInt()){
                count++;
            }else{
                if(count>max){
                    max = count;
                }
                count = 0;
            }
        }
        if(count>max){
            max = count;
        }
        System.out.println(max>=3?"Yes":"No");
    }
}
