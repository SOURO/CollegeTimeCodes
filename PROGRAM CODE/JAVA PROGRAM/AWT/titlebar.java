import java.awt.*;
class MyFrame1 extends Frame
{
        MenuBar mb;
        Menu m1,m2,m3;
        MenuItem mi1,mi2,mi3,mi4,mi5,mi6;
        MyFrame1(String n)
        {
                super(n);
                mb=new MenuBar();
                m1=new Menu("FILE");
                m2=new Menu("Edit");
                m3=new Menu("HELP");


                mi1=new MenuItem("New");
                mi2=new MenuItem("Open");
                mi3=new MenuItem("Save");
                mi4=new MenuItem("Exit");
                mi5=new MenuItem("COPY");
                mi6=new MenuItem("Paste");
               
                m1.add(mi1);
                m1.add(mi2);
                m1.add(mi3);
                m2.add(mi4);
                m2.add(mi5);
                m3.add(mi6);
                mb.add(m1);
                mb.add(m2);
                mb.add(m3);
                setMenuBar(mb);

                setSize(200,200);
                setVisible(true);
         }
     }
     class titlebar
     {           
        public static void main(String args[])
        {
           new MyFrame1("soura");
        }
     }

