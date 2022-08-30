package com.company;

public class Main {

    public static void main(String[] args) {

        Robot robots[]=new Robot[5];

        Robot robot;
        robot =new Robot("Azul", new Computadora("I5", "8Gb", "500Gb"));

        Computadora computadora= new Computadora("I7", "16GB", "1Tera");

        Robot robot2=new Robot("Negro", 500,computadora);
        Robot robot3=new Robot("Blanco", 1000,new Computadora("I7","16GB","500Gb"));

        computadora.setMemoria("32Gb");

        Computadora computadora1=robot.getComputadora();
        computadora1.setDisco("1Tera");

        robots[0]=robot;
        robots[1]=robot2;
        robots[2]=robot3;
        robots[3]=new Robot("Rojo", 500,new Computadora("I7","16GB","500Gb"));
        robots[4]=new Robot("Verde", 500,new Computadora("I7","16GB","500Gb"));;


        for(int i =0; i<robots.length; i++)
        {
            robots[i].encender();
        }
        robots[4].getComputadora().apagar();
        for(int i =0; i<robots.length; i++)
        {
            robots[i].avanzar();
        }
        for(int i =0; i<robots.length; i++)
        {
            System.out.println(robots[i].toString());
        }

    }
}
