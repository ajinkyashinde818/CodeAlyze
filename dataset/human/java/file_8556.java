import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int K = sc.nextInt();
        //char[] S = sc.next().toCharArray();
        int count=0;
        int S = Math.min(A, B);
        int L = Math.max(A, B);
        for(int i=S; i>0; i--){
            if(S%i==0 && L%i==0){
                count++;
                if(count==K){
                    System.out.println(i);
                    return;
                }

            }

        }

          //System.out.println(count);
        }
    }
