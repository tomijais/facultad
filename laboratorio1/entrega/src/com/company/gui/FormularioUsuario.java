package com.company.gui;

import com.company.entidades.Usuario;
import com.company.service.ServiceExeption;
import com.company.service.ServiceUsuario;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class FormularioUsuario extends JPanel {
    ServiceUsuario serviceUsuario;

    JPanel formularioUsuario;
    JPanel mostrarUsuarios;

    JLabel jLabelNombre;
    JLabel jLabelApellido;
    JLabel jLabelDNI;

    JLabel jLabelId;

    JTextField jTextFieldNombre;
    JTextField jTextFieldApellido;
    JTextField jTextFieldDNI;

    JTextField jTextFieldId;



    JButton jButtonCrear;
    JButton jButtonUpdate;
    JButton jButtonDelete;

    JButton jButtonRefreshUsers;


    PanelManager panel;


    JPanel botones;

    JTextArea jTextAreaUsuarios;
    JScrollPane jScrollPaneUsuarios;




    public void armarPanel() throws ServiceExeption {

        formularioUsuario = new JPanel();
        formularioUsuario.setLayout(new GridLayout(8,1));

        jLabelNombre = new JLabel("Nombre");
        jTextFieldNombre = new JTextField(20);

        jLabelApellido = new JLabel("Apellido");
        jTextFieldApellido = new JTextField(20);

        jLabelDNI = new JLabel("DNI");
        jTextFieldDNI = new JTextField(20);

        jLabelId = new JLabel("Id de usuario");
        jTextFieldId = new JTextField(20);

        botones = new JPanel();

        jButtonCrear = new JButton("Crear Usuario");
        jButtonUpdate = new JButton("Actualizar Usuario");
        jButtonDelete = new JButton("Eliminar Usuario");

        botones.add(jButtonCrear, BorderLayout.NORTH);
        botones.add(jButtonUpdate, BorderLayout.NORTH);
        botones.add(jButtonDelete, BorderLayout.NORTH);

        add(botones, BorderLayout.PAGE_START);



        mostrarUsuarios = new JPanel();
        mostrarUsuarios.setLayout(new BorderLayout());
        jButtonRefreshUsers = new JButton("Recargar Usuarios");

        jTextAreaUsuarios = new JTextArea(5, 30);
        jTextAreaUsuarios.setEditable(false);
        jScrollPaneUsuarios = new JScrollPane(jTextAreaUsuarios);

        mostrarUsuarios.add(jTextAreaUsuarios);
        mostrarUsuarios.add(jScrollPaneUsuarios, BorderLayout.NORTH);
        mostrarUsuarios.add(jButtonRefreshUsers, BorderLayout.SOUTH);

        add(mostrarUsuarios, BorderLayout.PAGE_END);
        refrescarPanel();


        jButtonRefreshUsers.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    refrescarPanel();
                } catch (ServiceExeption ex) {
                    throw new RuntimeException(ex);
                }
            }
        });

        jButtonCrear.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                formularioUsuario.add(jLabelNombre);
                formularioUsuario.add(jTextFieldNombre);

                formularioUsuario.add(jLabelApellido);
                formularioUsuario.add(jTextFieldApellido);

                formularioUsuario.add(jLabelDNI);
                formularioUsuario.add(jTextFieldDNI);

                abrirVentana(formularioUsuario, "save");

            }
        });

        jButtonUpdate.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                formularioUsuario.add(jLabelNombre);
                formularioUsuario.add(jTextFieldNombre);

                formularioUsuario.add(jLabelApellido);
                formularioUsuario.add(jTextFieldApellido);

                formularioUsuario.add(jLabelDNI);
                formularioUsuario.add(jTextFieldDNI);

                formularioUsuario.add(jLabelId);
                formularioUsuario.add(jTextFieldId);

                abrirVentana(formularioUsuario, "update");

                formularioUsuario.remove(jLabelNombre);
                formularioUsuario.remove(jTextFieldNombre);

                formularioUsuario.remove(jLabelApellido);
                formularioUsuario.remove(jTextFieldApellido);

                formularioUsuario.remove(jLabelDNI);
                formularioUsuario.remove(jTextFieldDNI);

                formularioUsuario.remove(jLabelId);
                formularioUsuario.remove(jTextFieldId);

            }
        });

        jButtonDelete.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                formularioUsuario.add(jLabelId);
                formularioUsuario.add(jTextFieldId);

                abrirVentana(formularioUsuario, "delete");

                formularioUsuario.remove(jLabelId);
                formularioUsuario.remove(jTextFieldId);

            }
        });





        formularioUsuario.setVisible(true);
        formularioUsuario.validate();
    }

    public FormularioUsuario(PanelManager panelPrincipal) throws ServiceExeption {
        panel = panelPrincipal;
        armarPanel();
    }

    public void abrirVentana(JPanel panel, String action){
        int result = JOptionPane.showConfirmDialog(null, panel, "Crear Usuario", JOptionPane.PLAIN_MESSAGE);


        if (result == JOptionPane.OK_OPTION) {
            System.out.println("You entered " +
                    jTextFieldNombre.getText() + ", " +
                    jTextFieldApellido.getText() + ", " +
                    jTextFieldDNI.getText());

            Usuario usuario = new Usuario();


            if(action.equals("save")){

                usuario.setName(jTextFieldNombre.getText());
                usuario.setLast_name(jTextFieldApellido.getText());
                usuario.setDNI(jTextFieldDNI.getText());

                try {
                    serviceUsuario = new ServiceUsuario();
                    serviceUsuario.guardarUsuario(usuario);
                } catch (ServiceExeption ex) {
                    throw new RuntimeException(ex);
                }finally {
                    jTextFieldNombre.setText("");
                    jTextFieldApellido.setText("");
                    jTextFieldDNI.setText("");
                }
            }

            if(action.equals("update")){

                usuario.setId(Integer.parseInt(jTextFieldId.getText()));
                usuario.setName(jTextFieldNombre.getText());
                usuario.setLast_name(jTextFieldApellido.getText());
                usuario.setDNI(jTextFieldDNI.getText());

                try {
                    serviceUsuario = new ServiceUsuario();
                    serviceUsuario.modificarUsuario(usuario);
                } catch (ServiceExeption ex) {
                    throw new RuntimeException(ex);
                }finally {
                    jTextFieldId.setText("");
                    jTextFieldNombre.setText("");
                    jTextFieldApellido.setText("");
                    jTextFieldDNI.setText("");
                }

            }

            if(action.equals("delete")){

                int id = (Integer.parseInt(jTextFieldId.getText()));

                try {
                    serviceUsuario = new ServiceUsuario();
                    serviceUsuario.borrarUsuario(id);
                } catch (ServiceExeption ex) {
                    throw new RuntimeException(ex);
                }finally {
                    jTextFieldId.setText("");
                    jTextFieldNombre.setText("");
                    jTextFieldApellido.setText("");
                    jTextFieldDNI.setText("");
                }

            }




        } else {
            System.out.println("User canceled / closed the dialog, result = " + result);
        }

    }

    private void refrescarPanel() throws ServiceExeption {
        serviceUsuario = new ServiceUsuario();
        ArrayList<Usuario> usuarios = serviceUsuario.buscarTodos();
        jTextAreaUsuarios.setText("");
        for (int i = 0; i < usuarios.toArray().length; i++) {
            jTextAreaUsuarios.append(usuarios.get(i).toString());
            jTextAreaUsuarios.append("\n");

        }

    }

}
