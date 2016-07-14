                                        import java.awt.*;
                                        class MyFrame extends Frame
                                        {
                                          Label l1,l2;
                                          TextField t1,t2;
                                          Button b;
                                          MyFrame(String s)
                                          {
                                            super(s);
                                            l1=new Label("User Id: ");
                                            l2=new Label("Password: ");
                                            t1=new TextField(10);
                                            t2=new TextField(10);
                                            b=new Button("Log In");
		  setLayout(new FlowLayout());
                                            add(l1);
                                            add(t1);
                                            add(l2);
                                            add(t2);
                                            add(b);
                                            setSize(200,200);
                                            setVisible(true);
                                           }
                                       }
                                       class up
                                       {
                                         public static void main(String args[])
                                         {
                                           new MyFrame("soura");
                                         }
                                       }
