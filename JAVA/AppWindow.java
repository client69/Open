package JAVA;
import java.awt.*;

//
import java.awt.event.*;


import java.applet.*;
public class AppWindow extends Frame {
String keymsg = "This is a test.";
String mousemsg = "";
int mouseX=30, mouseY=30;
public AppWindow() {
addKeyListener(new MyKeyAdapter(this));
addMouseListener(new
MyMouseAdapter(this));
addWindowListener(new
MyWindowAdapter()); }
public void paint(Graphics g) {
g.drawString(keymsg, 10, 40);
g.drawString(mousemsg, mouseX,
mouseY); }
public static void main(String args[]) {
AppWindow appwin = new AppWindow();
appwin.setSize(new Dimension(300, 200));
appwin.setTitle("An AWT-Based
Application");
appwin.setVisible(true);}
}
class MyKeyAdapter extends KeyAdapter {
AppWindow appWindow;
public MyKeyAdapter(AppWindow
appWindow) {
this.appWindow = appWindow;
}
public void keyTyped(KeyEvent ke) {
appWindow.keymsg += ke.getKeyChar();
appWindow.repaint();
}; }

class MyMouseAdapter extends MouseAdapter {
    AppWindow appWindow;
    public MyMouseAdapter(AppWindow appWindow) {
    this.appWindow = appWindow;
    }
    public void mousePressed(MouseEvent me) {
    appWindow.mouseX = me.getX();
    appWindow.mouseY = me.getY();
    appWindow.mousemsg = "Mouse Down at " + appWindow.mouseX +
    ", " + appWindow.mouseY;
    appWindow.repaint();
    }
    }
    class MyWindowAdapter extends WindowAdapter {
    public void windowClosing(WindowEvent we) {
    System.exit(0); } }
