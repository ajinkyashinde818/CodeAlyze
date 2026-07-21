import java.io.File;
import java.io.IOException;
import java.util.*;
 
public class Main {
 
	public static void main(String[] args) throws IOException {
		//File file = new File("input.txt");
		//Scanner sc = new Scanner(file);
		
		Scanner sc = new Scanner(System.in);
		
		int D = sc.nextInt();
		int G = sc.nextInt();
		int[] p = new int[D];
		int[] sumP = new int[D];
		int min = 0;
		int ans = 0;
		
		for(int i = 0; i < D; i++){
			p[i] = sc.nextInt();
			sumP[i] = sc.nextInt() + (i + 1) * 100 * p[i];
			min += p[i];
		}
		
		int bitMax = ((1 << D) - 1);
		//System.out.printf(Integer.toBinaryString(bit));
		
		for(int bit = 0; bit <= bitMax; bit++){
			//System.out.println(Integer.toBinaryString(bit));
			int sumPoint = 0;
			int sumProblem = 0;
			int index = D;
			for(int j = 0; j < D; j++){
				if((1&(bit>>j)) == 1){
					sumPoint += sumP[j];
					sumProblem += p[j];
				}
				else index = j;
			}
			
			//System.out.println(Integer.toBinaryString(bit) + " " + sumPoint + " " + sumProblem + " " + index);
			
			if(index != D){
				for(int j = 0; j < p[index]; j++){
					if(sumPoint + (index + 1) * 100 * j >= G && sumProblem + j < min){
						min = sumProblem + j;
						ans = sumPoint + (index + 1) * 100 * j;
						break;
					}
				}
			}else{
				if(sumPoint >= G && sumProblem < min){
					min = sumProblem;
				}
			}
		}
		
		System.out.println(min);
	}
}
