package jdbc;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;


/*
    接口实现类
 */

public class DAOImpl implements DAO {

    Connection connection = null;
    PreparedStatement statement = null;
    ResultSet resultSet = null;

    @Override
    public void query() {
        try {
            String sql = "select * from user";
            connection = util.getConnection();
            statement = connection.prepareStatement(sql);
            resultSet = statement.executeQuery(sql);
            while (resultSet.next()) {
                int id = resultSet.getInt("id");
                String name = resultSet.getString("username");
                System.out.println(id + ": " + name);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            util.release(connection, statement, resultSet);
        }
    }

    @Override
    public void insert() {
        try {
            String sql = "insert into user values(null,'jully',200)";
            connection = util.getConnection();
            statement = connection.prepareStatement(sql);
            int result = statement.executeUpdate(sql);
            if (result > 0) {
                System.out.println("添加成功！");
            } else {
                System.out.println("添加失败！");
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            util.release(connection, statement);
        }
    }

    @Override
    public void delete() {
        try {
            String sql = "delete from user where username='jully'";
            connection = util.getConnection();
            statement = connection.prepareStatement(sql);
            int result = statement.executeUpdate(sql);
            if (result > 0) {
                System.out.println("删除成功！");
            } else {
                System.out.println("删除失败！");
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            util.release(connection, statement);
        }
    }

    @Override
    public void update() {
        try {
            String sql = "update user set username='john' where id=2";
            connection = util.getConnection();
            statement = connection.prepareStatement(sql);
            int result = statement.executeUpdate(sql);
            if (result > 0) {
                System.out.println("更新成功！");
            } else {
                System.out.println("更新失败！");
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            util.release(connection, statement);
        }
    }

}
