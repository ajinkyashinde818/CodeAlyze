import java.io.IOException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

	public static int decode(char[] input){
		int in = 0;
		
		for(int j = 0; j < input.length; j++){
			if(input[j] >= '0' && input[j] <= '9'){
				int tmp = input[j] - '0';
				
				if(input[j+1] == 'i'){
					
				}else if(input[j+1] == 'x'){
					tmp *= 10;
				}else if(input[j+1] == 'c'){
					tmp *= 100;
				}else if(input[j+1] == 'm'){
					tmp *= 1000;
				}
				
				in += tmp;
				j++;
			}else{
				if(input[j] == 'i'){
					in += 1;
				}else if(input[j] == 'x'){
					in += 10;
				}else if(input[j] == 'c'){
					in += 100;
				}else if(input[j] == 'm'){
					in += 1000;
				}
			}
		}
		
		return in;
	}
	
	public static String code(int out){
		StringBuilder sb = new StringBuilder();
		
		while(out != 0){
			if((out / 1000) != 0){
				sb.append(((out / 1000) > 1 ? (out / 1000) : "") + "m");
				out = out % 1000;
			}else if((out / 100) != 0){
				sb.append(((out / 100) > 1 ? (out / 100) : "") + "c");
				out = out % 100;
			}else if((out / 10) != 0){
				sb.append(((out / 10) > 1 ? (out / 10) : "") + "x");
				out = out % 10;
			}else if(out != 0){
				sb.append((out > 1 ? out : "") + "i");
				out = 0;
			}
		}
		
		return sb.toString();
	}

	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);

		final int n = sc.nextInt();
		
		for(int i = 0; i < n; i++){
			System.out.println(code(decode(sc.next().toCharArray()) + decode(sc.next().toCharArray())));
		}
	}

}
