import java.awt.*;

public class Explode {

    int x;
    int y;
    int drawStep = 0;
    private boolean live = true;
    private TanksClient tc;
    private static Toolkit tk = Toolkit.getDefaultToolkit();
    private static Image[] imgs = {
            tk.getImage(Explode.class.getClassLoader().getResource("images/爆炸0.png")),
            tk.getImage(Explode.class.getClassLoader().getResource("images/爆炸1.png")),
            tk.getImage(Explode.class.getClassLoader().getResource("images/爆炸2.png")),
            tk.getImage(Explode.class.getClassLoader().getResource("images/爆炸3.png")),
            tk.getImage(Explode.class.getClassLoader().getResource("images/爆炸4.png")),
            tk.getImage(Explode.class.getClassLoader().getResource("images/爆炸5.png")),
            tk.getImage(Explode.class.getClassLoader().getResource("images/爆炸5.png")),
            tk.getImage(Explode.class.getClassLoader().getResource("images/爆炸5.png")),
            tk.getImage(Explode.class.getClassLoader().getResource("images/爆炸4.png")),
            tk.getImage(Explode.class.getClassLoader().getResource("images/爆炸3.png")),
            tk.getImage(Explode.class.getClassLoader().getResource("images/爆炸2.png")),
            tk.getImage(Explode.class.getClassLoader().getResource("images/爆炸1.png")),
            tk.getImage(Explode.class.getClassLoader().getResource("images/爆炸0.png"))
    };

    public Explode(int x, int y, TanksClient tc) {
        this.x = x;
        this.y = y;
        this.tc = tc;
    }

    public void drawExplosion(Graphics g){
        if(!live){
            tc.explodes.remove(this);
            return;
        }
        if(drawStep == imgs.length){
            live = false;
            drawStep = 0;
            return;
        }
        g.drawImage(imgs[drawStep],x,y,null);
        drawStep++;
    }
}
