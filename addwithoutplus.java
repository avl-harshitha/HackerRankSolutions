import java.util.Scanner;

class addwithoutplus {
	public static void main(String args[]) {

		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		int b = scan.nextInt();
		System.out.println("the number is");
		while(b != 0) {
			int carry = a & b;
			a = a ^ b;
			b = carry << 1;
		}
		System.out.println(a);
	}


}
