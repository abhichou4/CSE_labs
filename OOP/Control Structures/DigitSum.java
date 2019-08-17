import java.util.*;

class DigitSum{

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		System.out.println(digsum(num));
	}

	private static int digsum(int a){
		int dig=0, sum=0, num=a;
		while(a!=0){
			dig+=1;
			a=(int)a/10;
		}
		a=num;
		while(a!=0){
			sum+=a%10;
			a=(int)a/10;
		}
		return sum;
	}
}