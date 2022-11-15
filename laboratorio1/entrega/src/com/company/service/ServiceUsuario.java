package com.company.service;

import com.company.dao.DAOExeption;
import com.company.dao.DAOUsuario;
import com.company.entidades.Usuario;

import javax.swing.*;
import java.util.ArrayList;

public class ServiceUsuario {
    private DAOUsuario daoUsuario;

    public ServiceUsuario(){
        daoUsuario = new DAOUsuario();
    }

    public void guardarUsuario(Usuario usuario) throws ServiceExeption{
        try {
            daoUsuario.guardar(usuario);
        }catch (DAOExeption e){
            throw new ServiceExeption(e.getMessage());
        }
    }

    public void modificarUsuario(Usuario usuario) throws ServiceExeption{
        try {
            daoUsuario.modificar(usuario);
        }catch (DAOExeption e){
            JOptionPane.showMessageDialog(null,e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public Usuario buscarUsuario(int id) throws ServiceExeption{
        Usuario usuario = null;
        try {
            usuario = daoUsuario.buscar(id);
            return usuario;
        }catch (DAOExeption e){
            throw new ServiceExeption(e.getMessage());
        }
    }
    public ArrayList<Usuario> buscarTodos() throws ServiceExeption{
        ArrayList<Usuario> usuarios;
        try {
            usuarios = daoUsuario.buscarTodos();
            return usuarios;

        }catch (DAOExeption e){
            throw new ServiceExeption(e.getMessage());
        }
    }
    public void borrarUsuario(int id) throws ServiceExeption{
        try {
            daoUsuario.eliminar(id);
        }catch (DAOExeption e){
            throw new ServiceExeption(e.getMessage());
        }
    }

}
