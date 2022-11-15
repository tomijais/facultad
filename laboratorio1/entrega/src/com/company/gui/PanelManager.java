package com.company.gui;

import com.company.service.ServiceUsuario;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class PanelManager {
    private ServiceUsuario serviceUsuario;

    JFrame ventana;
    JFrame ventanaBotoneraArchivos;

    FormularioUsuario formularioUsuario;

    public PanelManager(){
        ventana = new JFrame("Home Banking");
        ventana.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        formularioUsuario = new FormularioUsuario(this);
        mostrarFormularioUsuario(formularioUsuario,BorderLayout.NORTH);

        ventana.setVisible(true);
        ventana.pack();

    }

    void mostrarFormularioUsuario(JPanel panel, String ubicacion){
        ventana.getContentPane().removeAll(); // Si necesito eliminar las cosas antes o no
        ventana.getContentPane().add(ubicacion,panel);
        ventana.getContentPane().validate();
        ventana.getContentPane().repaint();
        ventana.pack();
    }


}
