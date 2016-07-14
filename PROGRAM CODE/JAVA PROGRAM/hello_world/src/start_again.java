class apples implements start_again_interface
{
	void show()
	{
		System.out.println("Hello");
	}
}
//main will be alaways void and static
class start_again{
	
	public static void main(String args[])
	{
		apples obj=new apples();
		obj.show();
		System.out.println("World");
	}

}
