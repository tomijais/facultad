package com.company;


import utiles.Punto;

public class Robot {
    private String color;
    private char direccion;
    private double peso;
    private String estado;
    private Punto posicion;

    public Robot()
    {
       direccion='N';
       estado="apagado";
       posicion = new Punto(0,0);
    }
    public Robot(String colorRobot, double peso)
    {
        color=colorRobot;
        this.peso=peso;
        this.direccion='N';
        this.estado="apagado";
        posicion = new Punto(0,0);
    }
    public Robot(String color)
    {
        this.color=color;
        posicion = new Punto(0,0);
    }

    public void avanzar()
    {
        if (!estaEncendido())
            encender();
        switch (getDireccion())
        {
            case 'N':
                posicion.setY(posicion.getY()+1);
                break;
            case 'O':
                posicion.setX(posicion.getX()+1);
                break;
            case 'S':
                posicion.setY(posicion.getY()-1);
                break;
            case 'E':
                posicion.setX(posicion.getX()-1);
        }

    }
    public void avanzar(int pasos)
    {
        for(int i= 0; i<pasos; i++)
            avanzar();
    }
    public void girar()
    {
        switch (direccion)
        {
            case 'N':
                direccion='O';
                break;
            case 'O':
                direccion='S';
                break;
            case 'S':
                direccion='E';
                break;
            case 'E':
                direccion ='N';
        }

    }
    public void girar(int cantidad)
    {
        for(int i=0;i<cantidad;i++)
            girar();
    }
    public boolean estaEncendido()
    {
      /* if (estado.equals("encendido"))
           return true;
       return false;*/
       return estado.equals("encendido");
    }
    public void encender()
    {
        setEstado("encendido");
    }
    public void apagar()
    {
        setEstado("apagado");
    }
    public void setEstado(String estado)
    {
        this.estado=estado;
    }
    public String getColor()
    {
        return color;
    }

    public void setColor(String color)
    {
        this.color=color;
    }
    public char getDireccion()
    {
        return direccion;
    }
    public String toString()
    {
        String datos;
        datos="Color: " + color + " Peso: " + peso + " Estado: " + estado + " Posicion: " + posicion.toString();
        return datos;
    }
}
