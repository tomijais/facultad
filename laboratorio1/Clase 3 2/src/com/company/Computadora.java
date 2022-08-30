package com.company;

public class Computadora {
    private String procesador;
    private String memoria;
    private String disco;
    private boolean estado;

    public Computadora() {
    }

    public Computadora(String procesador, String memoria, String disco) {
        this.procesador = procesador;
        this.memoria = memoria;
        this.disco = disco;
    }

    public void encender()
    {
        estado= true;
    }
    public void apagar()
    {
        estado=false;
    }
    public boolean estaEncencida()
    {
        return estado;
    }
    public String getProcesador() {
        return procesador;
    }

    public void setProcesador(String procesador) {
        this.procesador = procesador;
    }

    public String getMemoria() {
        return memoria;
    }

    public void setMemoria(String memoria) {
        this.memoria = memoria;
    }

    public String getDisco() {
        return disco;
    }

    public void setDisco(String disco) {
        this.disco = disco;
    }

    @Override
    public String toString() {
        return " \n Computadora{" +
                "procesador='" + procesador + '\'' +
                ", memoria='" + memoria + '\'' +
                ", disco='" + disco + '\'' +
                '}';
    }
}
