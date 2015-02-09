import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner (System.in);
		int n;
		String s;
		n = input.nextInt();
		for (int i=0;i<n;i++) {
			s = input.next();
			if (s.matches("(\\?+)M(\\?+)E(\\?)(\\?+)") == true) {
				int m = s.indexOf('M'), e = s.indexOf('E');
				if (e-1 == s.length()-e-1)
					System.out.println ("theorem");
				else 
					System.out.println ("no-theorem");
			}
			else System.out.println ("no-theorem");
		}
	}

}
