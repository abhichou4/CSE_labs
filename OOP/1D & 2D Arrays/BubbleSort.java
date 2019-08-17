import java.util.*;

class BubbleSort{

	private static int i,j;
	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args){
		double[] a;
		int s;
		a = ReadArray();
		a = ascending(a);
		System.out.println("Sort in\n1. Ascending Order\n2. Descending Order\n");
		s = sc.nextInt();
		switch(s){
			case 1:
			a = ascending(a);
			case 2:
			a = descending(a);
			default:
			System.out.println("Enter valid option");
		}
		PrintArray(a);
	}

	private static double[] ReadArray(){
		System.out.println("Enter number of elements in array");
		int n = sc.nextInt();
		double[] arr = new double[n];
		System.out.println("Enter elements in array");
		for(i=0; i<arr.length; i++){
			arr[i] = sc.nextDouble();
		}
		return arr;
	}

	private static void PrintArray(double[] arr){
		for(double i:arr){
			System.out.println(i);
		}
	}

	private static double[] ascending(double[] arr){
		int i,j;
		double temp;
		for(i=0; i<arr.length-1; i++){
			for(j=i+1;j<=arr.length-1; j++){
				if(arr[j]<arr[i]){
					temp = arr[j];
					arr[j] = arr[i];
					arr[i] = temp;
				}
			}
		}
		return arr;
	}

	private static double[] descending(double[] arr){
		int i,j;
		double temp;
		for(i=0; i<arr.length-1; i++){
			for(j=i; j<=arr.length-1; j++){
				if(arr[j]>arr[i]){
					temp = arr[j];
					arr[j] = arr[i];
					arr[i] = temp;
				}
			}
		}
		return arr;
	}
}