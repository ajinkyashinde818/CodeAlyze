import java.util.*;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int S = sc.nextInt();
        int sum = 0;
        for(int X = 0; X <= K; X++){
        	for(int Y = 0; Y <= K; Y++){
        		int Z = S - (X+Y);
        		if((0 <= Z)&&(Z <= K)) sum++;
        	}
        }
        System.out.println(sum);
	}

}
