package com.company.dao;

import com.company.entidades.Usuario;
import org.h2.jdbcx.JdbcDataSource;

import java.sql.*;
import java.util.ArrayList;

public class DAOUsuario implements IDAO<Usuario>{

    private String DB_JDBC_DRIVER="org.h2.Driver";
    private String DB_URL="jdbc:h2:file:~/Desktop/facultad/laboratorio1/entrega/db";
    private String DB_USER="sa";
    private String DB_PASSWORD="";


    @Override
    public void guardar(Usuario entidad) throws DAOExeption {
        Connection connection = null;
        PreparedStatement preparedStatement = null;
        try{
            Class.forName(DB_JDBC_DRIVER);
            connection = DriverManager.getConnection(DB_URL, DB_USER
                    , DB_PASSWORD);
            preparedStatement = connection.prepareStatement("INSERT INTO USERS(NAME, LAST_NAME, DNI) VALUES(?,?,?) ");
            System.out.println(preparedStatement);
            preparedStatement.setString(1, entidad.getName());
            preparedStatement.setString(2, entidad.getLast_name());
            preparedStatement.setString(3, entidad.getDNI());
            int resultado = preparedStatement.executeUpdate();
            System.out.println("Registros intersados " + resultado);
        }catch (ClassNotFoundException | SQLException e){
        throw new DAOExeption(e.getMessage());
        }
        finally {
            try {
               if(preparedStatement != null){
                   preparedStatement.close();
               }
            }catch (SQLException e){
                throw new DAOExeption(e.getMessage());
            }
        }
    }

    @Override
    public void modificar(Usuario entidad) throws DAOExeption {
        Connection connection = null;
        PreparedStatement preparedStatement = null;
        try{
            Class.forName(DB_JDBC_DRIVER);
            connection = DriverManager.getConnection(DB_URL, DB_USER
                    , DB_PASSWORD);
            preparedStatement = connection.prepareStatement("UPDATE USERS SET NAME=?, LAST_NAME=?, DNI=? WHERE ID=? ");
            preparedStatement.setString(1, entidad.getName());
            preparedStatement.setString(2, entidad.getLast_name());
            preparedStatement.setString(3, entidad.getDNI());
            preparedStatement.setInt(4, entidad.getId());

            int resultado = preparedStatement.executeUpdate();
            System.out.println("Registros intersados " + resultado);
        }catch (ClassNotFoundException | SQLException e){
            throw new DAOExeption(e.getMessage());
        }
        finally {
            try {
                preparedStatement.close();
            }catch (SQLException e){
                throw new DAOExeption(e.getMessage());
            }
        }
    }

    @Override
    public void eliminar(int id) throws DAOExeption {
        Connection connection = null;
        PreparedStatement preparedStatement = null;
        try{
            Class.forName(DB_JDBC_DRIVER);
            connection = DriverManager.getConnection(DB_URL, DB_USER
                    , DB_PASSWORD);
            preparedStatement = connection.prepareStatement("DELETE FROM USERS WHERE ID=?");
            preparedStatement.setInt(1, id);

            int resultado = preparedStatement.executeUpdate();
            System.out.println("Registros intersados " + resultado);
        }catch (ClassNotFoundException | SQLException e){
            throw new DAOExeption(e.getMessage());
        }
        finally {
            try {
                preparedStatement.close();
            }catch (SQLException e){
                throw new DAOExeption(e.getMessage());
            }
        }
    }

    @Override
    public Usuario buscar(int id) throws DAOExeption {
        Connection connection = null;
        PreparedStatement preparedStatement = null;
        Usuario usuario = null;
        try{
            Class.forName(DB_JDBC_DRIVER);
            connection = DriverManager.getConnection(DB_URL, DB_USER
                    , DB_PASSWORD);
            preparedStatement = connection.prepareStatement("SELECT FROM USERS WHERE ID=?");
            preparedStatement.setInt(1, id);

            ResultSet rs = preparedStatement.executeQuery();

            while (rs.next()){
                usuario = new Usuario();
                usuario.setId(rs.getInt("ID"));
                usuario.setName(rs.getString("NAME"));
                usuario.setLast_name(rs.getString("LAST_NAME"));
                usuario.setDNI(rs.getString("DNI"));
            }
        }catch (ClassNotFoundException | SQLException e){
            throw new DAOExeption(e.getMessage());
        }
        finally {
            try {
                preparedStatement.close();
            }catch (SQLException e){
                throw new DAOExeption(e.getMessage());
            }
        }
        return usuario;
    }

    @Override
    public ArrayList<Usuario> buscarTodos() throws DAOExeption {
        Connection connection = null;
        PreparedStatement preparedStatement = null;
        Usuario usuario = null;
        ArrayList<Usuario> usuarios = new ArrayList<Usuario>();
        try{
            Class.forName(DB_JDBC_DRIVER);
            connection = DriverManager.getConnection(DB_URL, DB_USER
                    , DB_PASSWORD);
            preparedStatement = connection.prepareStatement("SELECT ID as ID, NAME, LAST_NAME, DNI FROM USERS ");

            ResultSet rs = preparedStatement.executeQuery();

            while (rs.next()){
                usuario = new Usuario();
                usuario.setId(rs.getInt("ID"));
                usuario.setName(rs.getString("NAME"));
                usuario.setLast_name(rs.getString("LAST_NAME"));
                usuario.setDNI(rs.getString("DNI"));
                usuarios.add(usuario);
            }
        }catch (ClassNotFoundException | SQLException e){
            throw new DAOExeption(e.getMessage());
        }
        finally {
            try {
                if(preparedStatement != null){
                    preparedStatement.close();
                }
            }catch (SQLException e){
                throw new DAOExeption(e.getMessage());
            }
        }
        return usuarios;
    }

}
