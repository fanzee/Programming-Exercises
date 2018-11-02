import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.List;

public class TanksClient extends Frame {

    public static final int FRAME_WIDTH = 1000;
    public static final int FRAME_HEIGHT = 800;

    Tanks myTank = new Tanks(400,300,true, Direction.STOP,this);
    Wall w1 = new Wall(350,250,10,200,this);
    Wall w2 = new Wall(600,400,10,200,this);

    List<Bullet> bullets = new ArrayList<Bullet>();
    List<Explode> explodes = new ArrayList<Explode>();
    List<Tanks> tanks = new ArrayList<Tanks>();

    public static void main(String[] args) {
        TanksClient tanksClient = new TanksClient();
        tanksClient.createFrame();
    }

    public void createFrame(){

        int initTanksNumbers = Integer.parseInt(PropertyControl.getProperty("initTanksNumbers"));
        for(int i = 0;i < initTanksNumbers;i++){
            tanks.add(new Tanks(50+100*i+1,50,false, Direction.D, this));
        }

        this.setTitle("坦克大战 JAVA 版");
        this.setLocation(500,150);
        this.setSize(FRAME_WIDTH,FRAME_HEIGHT);
        this.setBackground(Color.BLACK);
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        this.setResizable(false);
        this.addKeyListener(new KeyboardMonitor());
        setVisible(true);
        new Thread(new PaintThread()).start();
    }

    @Override
    public void paint(Graphics g) {

        myTank.drawTank(g);
        w1.drawWall(g);
        w2.drawWall(g);
        if(tanks.size()==0){
            for(int i = 0;i < Integer.parseInt(PropertyControl.getProperty("reStartNumber"));i++){
                tanks.add(new Tanks(50+150*i,50,false, Direction.D, this));
            }
        }

        for(int i=0;i<bullets.size();i++){
            Bullet b = bullets.get(i);
            b.destroyTanks(tanks);
            b.destroyTank(myTank);
            b.drawBullet(g);
            b.hitWall(w1);
            b.hitWall(w2);
        }
        for(int i = 0;i< explodes.size();i++){
            Explode e = explodes.get(i);
            e.drawExplosion(g);
       }
        for(int i = 0;i< tanks.size();i++){
            Tanks t = tanks.get(i);
            t.drawTank(g);
            t.hitWall(w1);
            t.hitWall(w2);
        }
    }

    private class PaintThread implements Runnable{
        public void  run(){
            while (true){
                repaint();
                try {
                    Thread.sleep(20);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    private class KeyboardMonitor extends KeyAdapter{

        public void keyPressed(KeyEvent e){
            myTank.keyPressed(e);
        }

        public void keyReleased(KeyEvent e) {
            myTank.keyReleased(e);
        }
    }

}
