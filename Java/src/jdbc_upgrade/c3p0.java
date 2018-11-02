package jdbc_upgrade;


import com.mchange.v2.c3p0.ComboPooledDataSource;
import domain.User;
import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.BeanHandler;
import org.junit.Test;


public class c3p0 {

    @Test
    public void test() {

        try {
            ComboPooledDataSource dataSource = new ComboPooledDataSource();
            QueryRunner queryRunner = new QueryRunner(dataSource);
            //queryRunner.update("insert into user values (null , ? , ? )", "aa", 1000);
            //queryRunner.update("delete from user where id = ?", 1);
            //queryRunner.update("update user set password = ? where id = ?", 321, 2);

            User user = queryRunner.query("select * from user where id = ?", new BeanHandler<User>(User.class), 2);
            System.out.println(user);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
