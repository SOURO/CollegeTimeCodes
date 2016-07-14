class Stud
{
	int roll;
             String name;
	String dept;			
	
	void get_roll1()
	{
		roll=025;
		System.out.println("The roll of the student is::"+roll);
		System.out.println();
	}
	void get_name1()
	{
		name="SOURABRATA";
		System.out.println("The name of the student is::"+name);
		System.out.println();
	}
	void get_dept1()
	{
		dept="CSE";
		System.out.println("The department of the student is::"+dept);
	}							
}
class Student
{
	public static void main(String args[])
	{
		Stud s=new Stud();
		s.get_name1();
		s.get_dept1();
		s.get_roll1();
	}
}		
		 