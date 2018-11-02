import java.awt.*;

public class Supplement {
    int x;
    int y;
    int width;
    int height;
    int step = 0;
    private boolean live = true;
    TanksClient tc;
    private int[][] path = {
        {300,300},{300,350},{300,400},{350,400},{400,400},{400,350},{400,300}
    };

    public Supplement() {
        this.x = path[0][0];
        this.y = path[0][1];
        width=height=15;
    }

    public boolean isLive() {
        return live;
    }

    public void setLive(boolean live) {
        this.live = live;
    }

    public void drawSupplement(Graphics g){
        if(!live){
            return;
        }
        Color c = g.getColor();
        g.setColor(Color.BLACK);
        g.fillRect(x,y,width,height);
        g.setColor(c);
        moveSupplement();
    }

    public void moveSupplement(){
        step++;
        if(step == path.length){
            step=0;
        }
        x=path[step][0];
        y=path[step][1];
    }

    public Rectangle getRectangle(){
        return  new Rectangle(x,y,width,height);
    }

}
