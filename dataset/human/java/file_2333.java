import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		char[] output_char = new char[52];
		
		for(int i = 0; i < 26; i++){
			output_char[i] = (char)('a' + i);
			output_char[i + 26] = (char)('A' + i);
		}
		
		Map<Character, Integer> dict = new HashMap<Character, Integer>();
		for(int i = 0; i < output_char.length; i++){
			dict.put(output_char[i], i);
		}
		
		while(true){
			final int n = sc.nextInt();
			
			if(n == 0){
				break;
			}
			
			int[] keys = new int[n];
			for(int i = 0; i < n; i++){
				keys[i] = sc.nextInt();
			}
			
			
			char[] input = sc.next().toCharArray();
			int[] input_value = new int[input.length];
			for(int i = 0; i < input.length; i++){
				input_value[i] = dict.get(input[i]);
			}
			
			for(int pos = 0; pos < input_value.length; pos++){
				final int use_key = pos % n;
				
				//System.out.println(use_key);
				
				//System.out.println(use_key);
				
				int out = (52 + input_value[pos] - keys[use_key]) % 52;
				
				input[pos] = output_char[out];
			}
			
			for(int i = 0; i < input.length; i++){
				System.out.print(input[i]);
			}
			System.out.println();
		}

	}

}
