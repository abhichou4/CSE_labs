import java.util.*;

class Stack{

	int[] arr;
	int len, top;

	void make_stack(int n){
		len = n;
		arr = new int[len];
		top = -1;
	}

	boolean isFull(){
		if(top + 1 >= len){
			return true;
		}
		else{
			return false;
		}
	}

	boolean isEmpty(){
		if(top == -1){
			return true;
		}
		else{
			return false;
		}
	}

	void push(int ele){
		if(isFull()){
			System.out.println("Stack Overflow!\n");
		}
		else{
			arr[++top]=ele;
			System.out.println(ele + "added to stack at" + top);
		}
	}

	void pop(){
		if(isEmpty()){
			System.out.println("Stack Undeflow!\n");
		}
		else{
			System.out.println(arr[top--] + "removed from" + (top+1));
		}
	}

	void peek(){
		if(top==-1){
			System.out.println("No element at the top!\n");
		}
		else{
			System.out.println(arr[top] + "is at the top\n");
		}
	}
}

class array_stack{
	public static void main(String[] args){

		Stack stk = new Stack();
		System.out.println("Enter length of stack\n");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		stk.make_stack(n);
		char c; int choice;

		do{
			System.out.println("Choose action to perform\n1.Push\n2.Pop\n2.Peek\n");
			choice = sc.nextInt();

			switch(choice){
				case 1: System.out.println("Enter element to enter\n");
					int ele = sc.nextInt();
					stk.push(ele);
					break;

				case 2: stk.pop(); break; 

				case 3: stk.peek(); break;

				default: System.out.println("choose valid option\n"); break;
			}

			System.out.println("Continue? Yes or No\n");
			c = sc.next().charAt(0);
		} while(c=='Y' || c=='y');
	}
}