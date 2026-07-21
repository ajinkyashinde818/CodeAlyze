import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {

		InputStreamReader in = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(in);
		StringBuilder sb = new StringBuilder(br.readLine());
		int q = Integer.parseInt(br.readLine());

		String A = new String();

		int orderFlg = 0;
		StringBuilder sb0 = new StringBuilder();
		StringBuilder sb1 = new StringBuilder();
		StringBuilder sb2 = new StringBuilder();

		A = sb.toString();

		for(int i = 0; i < q; i++) {

			String tmp = br.readLine();
			if(tmp.length() == 1) {
				orderFlg++;
			}else {
				String data = tmp.substring(tmp.length() -1);
				if(tmp.contains("1")) {
					if(orderFlg % 2 == 0) {
						sb1.insert(0,data);
					}else {
						sb2.append(data);
					}
				}else {
					if(orderFlg % 2 == 0) {
						sb2.append(data);
					}else {
						sb1.insert(0, data);
					}
				}

			}
		}
//		System.out.print("db1:"+ sb1 + "\n");
//		System.out.print("db2:"+ sb2 + "\n");

		sb0.append(sb1 + A + sb2);
		if((orderFlg > 0) && (orderFlg % 2 == 1)) {
			sb0.reverse();
		}
		System.out.print(sb0);

	}

}
