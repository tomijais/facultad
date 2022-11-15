package com.company.gui;

import com.company.entidades.Usuario;
import com.company.service.ServiceExeption;
import com.company.service.ServiceUsuario;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class FormularioUsuario extends JPanel {
    ServiceUsuario serviceUsuario;

    JPanel formularioUsuario;

    JLabel jLabelNombre;
    JLabel jLabelApellido;
    JLabel jLabelDNI;

    JTextField jTextFieldNombre;
    JTextField jTextFieldApellido;
    JTextField jTextFieldDNI;



    JButton jButtonGuardar;

    public  FormularioUsuario(){

        formularioUsuario = new JPanel();
        formularioUsuario.setLayout(new GridLayout(3,2));

        jLabelNombre = new JLabel("Nombre");
        jTextFieldNombre = new JTextField(20);

        jLabelApellido = new JLabel("Apellido");
        jTextFieldApellido = new JTextField(20);

        jLabelDNI = new JLabel("DNI");
        jTextFieldDNI = new JTextField(20);

        jButtonGuardar = new JButton("Guardar");


        formularioUsuario.add(jLabelNombre);
        formularioUsuario.add(jLabelApellido);
        formularioUsuario.add(jLabelDNI);

        formularioUsuario.add(jTextFieldNombre);
        formularioUsuario.add(jTextFieldApellido);
        formularioUsuario.add(jTextFieldDNI);

        formularioUsuario.add(jButtonGuardar);

        jButtonGuardar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Usuario usuario = new Usuario();

                usuario.setName(jTextFieldNombre.getText());
                usuario.setLast_name(jTextFieldApellido.getText());
                usuario.setDNI(jTextFieldDNI.getText());

                try {
                    serviceUsuario.guardarUsuario(usuario);
                } catch (ServiceExeption ex) {
                    throw new RuntimeException(ex);
                }
            }
        });

        formularioUsuario.validate();
    }

}

/*
*
* package com.company.gui;

import com.company.entidades.Usuario;
import com.company.service.ServiceExeption;
import com.company.service.ServiceUsuario;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class FormularioUsuario extends JPanel {
    ServiceUsuario serviceUsuario;

    JPanel formularioUsuario;
    JPanel botones;

    JLabel jLabelNombre;
    JLabel jLabelApellido;
    JLabel jLabelDNI;

    JTextField jTextFieldNombre;
    JTextField jTextFieldApellido;
    JTextField jTextFieldDNI;



    JButton jButtonGuardar;
    JButton jButtonNuevo;

    PanelManager panel;

    public FormularioUsuario(PanelManager panelPrincipal){
        panel = panelPrincipal;
        armarFormulario(null);
    }

    public void armarFormulario(Usuario usuario){
        formularioUsuario = new JPanel();

        formularioUsuario.setSize(500,500);
        formularioUsuario.setLayout(new GridLayout(3,2));

        jLabelNombre = new JLabel("Nombre");
        jTextFieldNombre = new JTextField(20);

        jLabelApellido = new JLabel("Apellido");
        jTextFieldApellido = new JTextField(20);

        jLabelDNI = new JLabel("DNI");
        jTextFieldDNI = new JTextField(20);

        jButtonGuardar = new JButton("Guardar");
        jButtonNuevo = new JButton("Nuevo");


        formularioUsuario.add(jLabelNombre);
        formularioUsuario.add(jLabelApellido);
        formularioUsuario.add(jLabelDNI);

        formularioUsuario.add(jLabelNombre);
        formularioUsuario.add(jTextFieldApellido);
        formularioUsuario.add(jTextFieldDNI);

        formularioUsuario.add(jButtonGuardar);
        formularioUsuario.add(jButtonNuevo);

        botones.add(jButtonGuardar);
        botones.add(jButtonNuevo);

        add(botones, BorderLayout.SOUTH);

        jButtonGuardar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                Usuario usuario = new Usuario();

                usuario.setName(jTextFieldNombre.getText());
                usuario.setLast_name(jTextFieldApellido.getText());
                usuario.setDNI(jTextFieldDNI.getText());

                try {
                    serviceUsuario.guardarUsuario(usuario);
                } catch (ServiceExeption e) {
                    JOptionPane.showMessageDialog(null, e.getMessage(),"Error",JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        jButtonNuevo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                vaciarComponentes();

            }
        });

        jLabelNombre.setText(usuario==null?"":usuario.getName());
        jLabelApellido.setText(usuario==null?"":usuario.getLast_name());
        jTextFieldDNI.setText(usuario==null?"":usuario.getDNI());


    }


    public void vaciarComponentes()
    {
        jTextFieldNombre.setText("");
        jTextFieldApellido.setText("");
        jTextFieldDNI.setText("");
    }

}
*/

