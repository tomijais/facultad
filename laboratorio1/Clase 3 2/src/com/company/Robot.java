package com.company;


import utiles.Punto;

public class Robot {
    private String color;
    private char direccion;
    private double peso;
    private String estado;
    private Punto posicion;
    private Computadora computadora;

    public Robot()
    {
       direccion='N';
       estado="apagado";
       posicion = new Punto(0,0);
    }
    public Robot(String colorRobot, double peso, Computadora computadora)
    {
        color=colorRobot;
        this.peso=peso;
        this.direccion='N';
        this.estado="apagado";
        posicion = new Punto(0,0);
        this.computadora= computadora;
    }
    public Robot(String color, Computadora computadora)
    {
        this.color=color;
        posicion = new Punto(0,0);
        this.computadora=computadora;
    }

    public void avanzar()
    {
        /*if (!estaEncendido())
            encender();*/
        if (estaEncendido())
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
        else
        {
            System.out.println("Esta apagado " + color);
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
       return computadora.estaEncencida() && estado.equals("encendido");
    }
    public void encender()
    {
        computadora.encender();
        setEstado("encendido");
    }
    public void apagar()
    {
        computadora.apagar();
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

    public void setComputadora(Computadora computadora) {
        this.computadora = computadora;
    }

    public Computadora getComputadora() {
        return computadora;
    }

    public String toString()
    {
        String datos;
        datos="Color: " + color + " Peso: " + peso + " Estado: " + estado + " Posicion: " + posicion.toString();
        datos += " Computadora: " + computadora.toString();
        return datos;
    }
}
