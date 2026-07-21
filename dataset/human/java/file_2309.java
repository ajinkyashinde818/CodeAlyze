import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		//station info
		HashMap<Integer, Character> stations = new HashMap<Integer, Character>();
		for(int i = 0; i < 26; i++){
			stations.put(i, (char) ('a'+i));
		}
		for(int i = 0; i < 26; i++){
			stations.put(i + 26, (char) ('A'+i));
		}
		
		while(true){
			int n = Integer.parseInt(br.readLine());
			
			if(n == 0){
				break;
			}
			
			int[] keys = new int[n];
			
			String[] tmpArray = br.readLine().split(" ");
			
			for(int i = 0; i < n; i++){
				keys[i] = Integer.parseInt(tmpArray[i]);
			}
			
			String str = br.readLine();
			
			for(int i = 0; i < str.length(); i++){
				char tmpStation = str.charAt(i);
				
				int tmpId = 0;
				if(Character.isUpperCase(tmpStation)){
					tmpId = tmpStation - 'A' + 26;
				}
				else {
					tmpId = tmpStation - 'a';
				}
				
				tmpId -= keys[i%keys.length];
				if(tmpId < 0){
					tmpId += 52;
				}
//				tmpId %= 52;
				
				System.out.print(stations.get(tmpId));
			}
			System.out.println();
		}
	}

}
