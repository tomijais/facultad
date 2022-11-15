package com.company.dao;

import java.util.ArrayList;

public interface IDAO <T>{
    public void guardar(T entidad) throws DAOExeption;
    public void modificar(T entidad) throws DAOExeption;
    public void eliminar(int id) throws DAOExeption;
    public T buscar(int id) throws DAOExeption;
    public ArrayList<T> buscarTodos() throws DAOExeption;

}
