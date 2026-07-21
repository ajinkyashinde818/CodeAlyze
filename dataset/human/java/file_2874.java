import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args){
		Scanner stdIn = null;
		int[] num = {1,4,1,4,1,2,1,2,1,4,1,4,1,2,1};
		
		try{
			stdIn = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
			while( stdIn.hasNext() ){
				int[] data = new int[8];
				for(int i = 0; i < 8; i++){
					data[i] = stdIn.nextInt();
				}
				int min = -1;
				String key = new String();
				for(int i = 0; i < 8; i++){
					int sum = 0;
					for(int j = 0; j < 8; j++){
						sum += (data[j] > num[i+j]) ? (data[j]-num[i+j]) : 0;
					}
					if( min < 0 || sum <= min ){
						StringBuilder key2 = new StringBuilder();
						for(int j = 0; j < 8; j++){
							key2.append(Integer.toString(num[i+j]));
						}
						if( sum < min ){
							key = new String(key2.toString());
						} else if( key.equals("") || Integer.parseInt(key2.toString()) < Integer.parseInt(key) ){
								key = new String(key2.toString());
						}
						min = sum;							
					}
				}
				for(int i = 0; i < 7; i++){
					System.out.print(key.charAt(i) + " ");
				}
				System.out.println(key.charAt(7));				
			}			
		} finally {
			if( stdIn != null){
				stdIn.close();
			}
		}
	}
}
