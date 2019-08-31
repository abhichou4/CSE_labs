import java.util.*;

class Time{

	int h, m, s;

	void read(int a, int b, int c){
		h=a; m=b; s=c;
	}

	void display(){
		System.out.println(h+":"+m+":"+s);
	}

	static int to_sec(Time t){
		return t.h*60*60+t.m*60+t.s;
	}

	static Time to_time(int sec){
		Time t = new Time();
		int a = sec/(60*60);
		sec = sec - a*60*60;
		int b = sec/60;
		sec = sec -b*60;
		int c = sec;
		t.read(a, b, c);
		return t;
	}

	Time add(Time t2){
		int sec1 = Time.to_sec(this);
		int sec2 = Time.to_sec(t2);
		return Time.to_time(sec1+sec2);
	}

	Time sub(Time t2){
		int sec1 = Time.to_sec(this);
		int sec2 = Time.to_sec(t2);
		return Time.to_time(Math.abs(sec1-sec2));
	}

	void compare(Time t2){
		int sec1 = Time.to_sec(this);
		int sec2 = Time.to_sec(t2);
		if(sec1>sec2){
			System.out.println(this + "is greater");
		}
		else if(sec2>sec1){
			System.out.println(t2 + "is greater");
		}
	}
}

class time{
	public static void main(String[] args){
		int h,m,s;	
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter hours, min and senconds for t1");
		h = sc.nextInt();
		m = sc.nextInt();
		s = sc.nextInt();
		Time t1 = new Time();
		t1.read(h, m, s);
		System.out.println("Enter hours, min and senconds for t2");
		h = sc.nextInt();
		m = sc.nextInt();
		s = sc.nextInt();
		Time t2 = new Time();
		t2.read(h,m,s);

		t1.display();
		t2.display();



		Time r;
		r = Time.to_time(36001);
		System.out.println(r.h + r.m + r.s);
		r = t1.add(t2);
		r.display();
		r = t1.sub(t2);
		r.display();
	}
}