import java.util.*;

class InsertDelete{

	private static int i,j,pos;
	private static double ele;
	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		double[] a;
		a = ReadArray();
		System.out.println("1. Insert Elements\n2. Delete Elements");
		int s = sc.nextInt();
		switch(s){
			case 1:
			System.out.println("Insert element to be added and position");
			ele = sc.nextDouble();
			pos = sc.nextInt();
			a = InsertEle(a, ele, pos);
			break;

			case 2:
			System.out.println("Enter element to be deleted and it's postion");
			ele = sc.nextDouble();
			pos = sc.nextInt();
			a = DeleteEle(a, ele, pos);
			break;

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

	private static double[] InsertEle(double[] arr, double ele, double pos){
		double[] temp = new double[arr.length+1];
		for(i=0; i<arr.length; i++){
			temp[i]=arr[i];
		}
		temp[i] = ele;
		arr = temp;
		return arr;
	}

	private static double[] DeleteEle(double[] arr, double ele, double pos){
		double[] temp = new double[arr.length-1];
		for(i=0; i<arr.length-1; i++){
			if(i<pos-1){
				temp[i]=arr[i];
			}
			
			else{
				temp[i]=arr[i+1];
			}
		}
		arr = temp;
		return arr;
	}
}