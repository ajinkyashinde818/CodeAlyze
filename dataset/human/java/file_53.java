import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String[] tmpArray = br.readLine().split(" ");

		int n = Integer.parseInt(tmpArray[0]);
		int m = Integer.parseInt(tmpArray[1]);

		Node[] array = new Node[n];

		for(int i = 0; i < n; i++){
			array[i] = new Node(i + 1);
		}

		for(int i = 0; i < m; i++){
			int index = Integer.parseInt(br.readLine()) - 1;

			array[index].priority = i;
		}

		Arrays.sort(array);

		for(int i = 0; i < n; i++){
			System.out.println(array[i].key);
		}

	}

}

class Node implements Comparable<Node>{
	int key;
	int priority = -1;

	Node(int key){
		this.key = key;
	}

	@Override
	public int compareTo(Node node) {
		return node.priority - this.priority;
	}
}
