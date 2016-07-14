class Box
{
	double height,depth,length;
	double box_vol()
	{
		return height * depth * length;
	}
	void show(double v)
	{
		System.out.println("Volume of box is="+v);
	}
	Box(double l,double h,double d)
	{
		System.out.println("Constructing Box");
		height=h;
		depth=d;
		length=l;
	}
}
class Box_demo
{
	public static void main(String args[])
	{
		Box b1=new Box(30.5,12.0,20.2);
		double v=b1.box_vol();
		b1.show(v);
	}
}	
		