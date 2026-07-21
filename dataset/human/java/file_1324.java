import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();

		String[] n_array = new String[n];
		for(int i = 0; i < n; i++) {
			n_array[i] = sc.next();
		}

		String[] m_array = new String[m];
		for(int i = 0; i < m; i++) {
			m_array[i] = sc.next();
		}


		for(int i = 0; i < n - m + 1; i++) {
			for(int j = 0; j < n - m + 1; j++) {
				String first = n_array[i].substring(j, j + m);//n_arrayを考えらえるだけ切り取る
				if(first.equals(m_array[0])) { //切り取った中で、m_arrayの一行目とマッチする場合
					boolean isNG = false;
					for(int k = 1; k < m; k++) {
						String next = n_array[i + k].substring(j, j + m);
						if(!next.equals(m_array[k])) {
							isNG = true;
							break;
						}
					}
					if(!isNG) {
						System.out.println("Yes");
						return;
					}
				}
			}
		}
		System.out.println("No");
	}
}
