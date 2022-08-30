package com.company;

public class Main {

    public static void main(String[] args) {

        Robot robot;

        robot =new Robot();
        Robot robot2=new Robot("Negro", 500);
        robot.setColor("Azul");
        System.out.println(robot2.toString());
        System.out.println(robot.toString());
        robot2.avanzar();
        System.out.println(robot2.toString());
        robot2.girar();
        robot2.avanzar( 2);

        System.out.println(robot2.toString());
    }
}
