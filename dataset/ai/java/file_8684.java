import java.sql.*;
class Main {
	public static void main(String[] args) {
		try {
			Class.forName("java.lang.String");
			System.out.println("JDBC setup example");
		} catch (ClassNotFoundException error) {
			System.out.println(error.getMessage());
		}
	}
}
