package com.company;

import java.util.Locale;
import java.util.Scanner;


public class Main {
    public static int suma(int num1, int num2)
    {
        System.out.println("Estoy sumando enteros");
        return num1+ num2;
    }
    public static double suma(double num1, double num2)
    {
        System.out.println("Estoy sumando numeros con coma");
        return num1+num2;
    }
    public static void mensaje(String texto)
    {
        System.out.println(texto);
    }
    public static double calcularIntereses(double valor, double coeficiente)
    {
        double auxiliar;
        auxiliar = valor /100*coeficiente;
        return auxiliar;
    }


    public static void main(String[] args) {
        int numero, edad=20;
        int sumaEdades=0;
        int edades[]=new int[5];
        double num;
        char letra;
//        boolean hay;
        char categoria='A';
        String nombre;
        Scanner scanner= new Scanner(System.in);
        int num1,num2, res1;
        double valor1,valor2, res2;
        num1=10;
        num2=15;
        valor1=9;
        valor2=7;

        res1=suma(num1,num2);
        System.out.println(res1);
        res2=suma(valor1,valor2);
        System.out.println(res2);

        float coeficiente=1.5f;
        double porcentaje=2.5;

        switch (categoria)
        {
            case 'A':
                System.out.println("Es categoria A");
                break;
            case 'B':
                System.out.println("Es categoria B");
                break;
        }
        for(int i=0;i<edades.length;i++) {
            mensaje("Ingresa tu edad en la posicion " + (i+1));
            edades[i] = scanner.nextInt();
        }

        for(int i=0;i<edades.length;i++) {
            System.out.println("La edad en la posicion " + (i + 1) + " " + edades[i]);
            sumaEdades= suma(sumaEdades,edades[i]);
        }
        System.out.println("Edades Promedio " + sumaEdades/edades.length);

        /*
        scanner.nextLine();
        System.out.println("Ingresa tu nombre");
        nombre= scanner.nextLine();



        System.out.println(nombre );
        nombre = nombre.toUpperCase();
        System.out.println("Hola " + nombre + " edad " + edad);

        // +,-,*,/,%
        //<,<=,>,>=,==,!=
        //&&,||


        if (!nombre.equals("Martha"))
            System.out.println("NO es igual");
        else
            System.out.println("Es igual");

        numero= nombre.compareTo("MARTHO");
        System.out.println(numero);
        if (nombre.compareTo("MARTHO")>1) //0,1,-1
            System.out.println(nombre + " es mayor");
        else
            System.out.println(nombre + " es menor ");


*/
    }



}
