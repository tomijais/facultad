# Tablero Colaborativo de Trabajo

Este proyecto es un tablero colaborativo de trabajo construido con Express y MongoDB. Permite gestionar usuarios y tareas, proporcionando funcionalidades de creación, lectura, actualización y eliminación (CRUD) tanto para los usuarios como para las tareas.

# Descripción

El tablero colaborativo de trabajo es una aplicación web que permite a los usuarios gestionar tareas de forma colaborativa. Los usuarios pueden registrarse, iniciar sesión, crear, ver, actualizar y eliminar tareas, así como asignar tareas a otros usuarios y comentar en las tareas existentes. La aplicación está construida utilizando NestJS como framework de backend, MongoDB como base de datos, JWT para la autenticación de usuarios y HBS como motor de plantillas.

# Arquitectura y Tecnologías Utilizadas

El proyecto sigue una arquitectura basada en el patrón MVC (Modelo-Vista-Controlador) utilizando el framework NestJS. A continuación, se detallan las principales tecnologías utilizadas:

- NestJS: Framework de desarrollo de aplicaciones web en Node.js que proporciona una estructura modular y escalable para el backend.
- MongoDB: Base de datos NoSQL utilizada para almacenar los datos de usuarios y tareas.
- JWT (JSON Web Token): Mecanismo de autenticación utilizado para generar y validar tokens de acceso de usuarios.
- HBS (Handlebars): Motor de plantillas utilizado para renderizar las vistas HTML dinámicas en el servidor.

## Tecnologías utilizadas

- Node.js
- Express.js
- MongoDB
- Mongoose (ORM para MongoDB)

## Configuración

1. Clona este repositorio en tu máquina local.
2. Asegúrate de tener Node.js y MongoDB instalados en tu sistema.
3. Ejecuta `npm install` para instalar las dependencias necesarias.

## Levantar la base de datos en MongoDB

1. Inicia tu servidor local de MongoDB.
2. Abre el archivo `app.module.ts` y busca la siguiente línea de código:

```javascript
    MongooseModule.forRoot(
      'mongodb://localhost:27017/mydatabase',
    ),
```

3. Reemplaza `'mongodb://localhost:27017/mydatabase'` con la URL de conexión correcta de tu base de datos MongoDB. Asegúrate de que la base de datos exista.

## Ejecutar el servidor

1. Ejecuta `npm run start` para iniciar el servidor en el puerto 3000.
2. El servidor estará disponible en http://localhost:3000.

## Uso del API

A continuación se presentan las rutas principales del API:

## Usuarios

- GET /users: Obtiene la lista de usuarios.
- GET /users/:username: Obtiene los detalles de un usuario específico.
- POST /users: Crea un nuevo usuario.
- PATCH /users/:username: Actualiza los detalles de un usuario específico.
- DELETE /users/:username: Elimina un usuario específico.

## Tareas

- GET /tasks: Obtiene la lista de tareas.
- POST /tasks/create: Crea una nueva tarea.
- POST /tasks/update/:id: Actualiza los detalles de una tarea específica.
- POST /tasks/delete/:id: Elimina una tarea específica.


# Pruebas

## Usuarios:

Obtener la lista de usuarios:
```bash
curl -X GET http://localhost:3000/users
```
Obtener los detalles de un usuario específico:
```bash
curl -X GET http://localhost:3000/users/{username}
```
(reemplaza {username} por el nombre de usuario real)

Crear un nuevo usuario:

```bash
curl -X POST -H "Content-Type: application/json" -d '{
  "username": "john_doe",
  "password": "secretpassword",
  "name": "John Doe"
}' http://localhost:3000/users
```
Actualizar los detalles de un usuario específico:
```bash
curl -X PATCH -H "Content-Type: application/json" -d '{
  "name": "John Smith"
}' http://localhost:3000/users/{username}
```
(reemplaza {username} por el nombre de usuario real)

Eliminar un usuario específico:
```bash
curl -X DELETE http://localhost:3000/users/{username}
```
(reemplaza {username} por el nombre de usuario real)

## Tareas:

Obtener la lista de tareas:
```bash
curl -X GET http://localhost:3000/tasks
```
Crear una nueva tarea:
```bash
curl -X POST -H "Content-Type: application/json" -d '{
  "title": "Nueva tarea",
  "description": "Descripción de la tarea"
}' http://localhost:3000/tasks/create
```
Actualizar los detalles de una tarea específica:
```bash
curl -X POST -H "Content-Type: application/json" -d '{
  "title": "Tarea actualizada",
  "description": "Descripción actualizada"
}' http://localhost:3000/tasks/update/{id}
```
(reemplaza {id} por el ID real de la tarea)

Eliminar una tarea específica:
```bash
curl -X POST http://localhost:3000/tasks/delete/{id}
```
