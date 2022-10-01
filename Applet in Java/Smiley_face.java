import java.awt.*;
import java.applet.*;
public class Smiley_face extends Applet
{
	public void paint(Graphics g)
	{
		g.setColor(Color.yellow);
		g.fillOval(50,50,600,600);
		g.setColor(Color.black);
		g.drawOval(49,49,600,600);
		g.fillOval(200,200,100,100);
		g.fillOval(400,200,100,100);
		g.drawArc(205,230,300,300,0,-180);
	}
}
/*
<applet code=Smiley_face width=700 height=700></applet>
*/