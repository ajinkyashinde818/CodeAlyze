import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
public class Main {

	public void run() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		List<Integer> arrayData = new ArrayList<Integer>();
		String[] lineArray = line.split(" ");
		for (String token : lineArray) {
			arrayData.add(Integer.parseInt(token));
		}
		int A = arrayData.get(0);
		int B = arrayData.get(1);
		int K = arrayData.get(2);
		List<Integer> li = new ArrayList<Integer>();
		int smaller = Math.min(A, B);
		for(int i=1; i<=smaller;i++){
	
				if(A%i == 0 && B%i == 0){
					li.add(i);
				}

		}
		
		Collections.reverse(li);
		System.out.println(li.get(K-1));
	}
    public static void main(String[] args) throws Exception {
        new Main().run();
    }

}
