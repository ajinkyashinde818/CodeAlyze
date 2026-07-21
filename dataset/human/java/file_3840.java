import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String input = br.readLine();
		
		int len = input.length();
		
		int xarray[];
		
		String[] splitAlpha = input.split("[a-z&&[^x]]", -1);
//		for(int i = 0; i < splitAlpha.length ; i++){
//			System.out.println(splitAlpha[i]);
//		}
		
		xarray = new int[len + 1];
		
		StringBuffer sb = new StringBuffer();
		int numOfX = 0;
		for(int i = 0; i < len ; i++){
			char c = input.charAt(i);
			
			if(c != 'x'){
				sb.append(c);
			}
			else {
				numOfX++;
			}
		}
		
		String eraseX = sb.toString();
		
		//そもそもx抜きで回文か
		int len2 = eraseX.length();
		for(int i = 0; i < len2 / 2; i++){
			if(eraseX.charAt(i) != eraseX.charAt(len2 - i - 1)){
				System.out.println(-1);
				return;
			}
		}
		
//		//左右のxの個数を調べる
		int result = 0;
		for(int i = 0; i < splitAlpha.length/2 ; i++){
			result += Math.abs(splitAlpha[i].length() - splitAlpha[splitAlpha.length - i - 1].length());
		}
		
		System.out.println(result);
//		int leftX = 0;
//		int rightX = 0;
//		int mid = len2 / 2;
//		for(int i = 0; mid > 0 ; i++){
//			char c = input.charAt(i);
//			
//			if(c == 'x'){
//				leftX++;
//			}
//			else {
//				mid--;
//			}
//		}
//		System.out.println("L "+leftX+" R "+rightX);
	}

}
