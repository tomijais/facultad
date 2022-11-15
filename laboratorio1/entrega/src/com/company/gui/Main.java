package com.company.gui;

import javax.swing.*;

public class Main {

    public static void main(String[] args){
        FormularioUsuario formularioUsuario = new FormularioUsuario();
        JFrame ventana = new JFrame();
        ventana.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ventana.setContentPane(formularioUsuario);
        ventana.setSize(500,500);
        ventana.setResizable(false);
        ventana.validate();
        ventana.setVisible(true);



    }
}


/*
*
*     public static void main(String[] args){
        PanelManager panel = new PanelManager(1);

        Usuario usuario = new Usuario();
        panel.mostrarFormularioUsuario(usuario);


    }*/