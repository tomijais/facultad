package com.company;

import com.company.entidades.Usuario;
import com.company.service.ServiceExeption;
import com.company.service.ServiceUsuario;

public class Main {

    public static void main(String[] args){

        Usuario usuario = new Usuario();
        usuario.setName("Tomas");
        usuario.setDNI("123");
        usuario.setLast_name("Jais");

        ServiceUsuario servicio = new ServiceUsuario();
        try {
            servicio.guardarUsuario(usuario);
        }catch (ServiceExeption e){
            e.printStackTrace();
        }

    }
}
