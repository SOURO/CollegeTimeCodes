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
	Box()
	{
		System.out.println("Constructing Box");
		height=12.0;
		depth=14.5;
		length=10.5;
	}
}
class Box_demo
{
	public static void main(String args[])
	{
		Box b1=new Box();
		double v=b1.box_vol();
		b1.show(v);
	}
}	
		