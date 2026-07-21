import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N  = sc.nextInt();

        int seqCount = 0;
        int maxSeq = 0;
        for (int i = 0; i < N; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();

            if(a==b){
                seqCount++;
            }else{
                seqCount=0;
            }

            maxSeq = Math.max(seqCount,maxSeq);


        }

        if(maxSeq >=3){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }

    }

}
