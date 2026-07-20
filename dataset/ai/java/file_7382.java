class Main {
  public static void main(String[] args) {
    try {
      if (77 % 2 == 1) throw new IllegalArgumentException("odd");
      System.out.println("even");
    } catch (IllegalArgumentException error) {
      System.out.println(error.getMessage());
    }
  }
}
