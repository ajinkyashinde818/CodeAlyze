class Main {
	public static void main(String[] args) throws InterruptedException {
		Thread worker = new Thread(() -> System.out.println("running"));
		worker.start();
		worker.join();
	}
}
