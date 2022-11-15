package com.company.entidades;

public class Usuario {
    private int id;
    private String name;
    private String last_name;
    private String DNI;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getLast_name() {
        return last_name;
    }

    public void setLast_name(String last_name) {
        this.last_name = last_name;
    }

    public String getDNI() {
        return DNI;
    }

    public void setDNI(String DNI) {
        this.DNI = DNI;
    }

    @Override
    public String toString() {
        return " ID: " + id + " Nombre: " + name + " Apellido: " + last_name + " DNI: " + DNI;
    }
}
