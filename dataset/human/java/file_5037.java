import java.io.*;

public class Main {
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringBuilder s = new StringBuilder(br.readLine());
		int q = Integer.parseInt(br.readLine());
		
		boolean flip = false;
		StringBuilder left = new StringBuilder();
		
		for (int i = 0; i < q; i++) {
			String[] fc = br.readLine().split(" ");
			if (fc[0].equals("1")) {
				flip = !flip;
			} else {
				if (fc[1].equals("1") ^ flip) left.append(fc[2]);
				else s.append(fc[2]);
			}
		}
		
		br.close();

		left.reverse().append(s);
		if (flip) left.reverse();
	
		System.out.println(left.toString());
		
	}
	
}
