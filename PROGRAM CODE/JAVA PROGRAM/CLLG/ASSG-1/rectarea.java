class area
{
	double len,wid;
	area(double x,double y)
	{
		len=x;
		wid=y;
	}
	double cal_area()
	{
		return len*wid;
	}
}
class rectarea
{
	public static void main(String args[])
	{
		area ob=new area(20,50);
		double a=ob.cal_area();
		System.out.print("THE AREA OF THE RECTANGLE IS ="+a);
	}
}