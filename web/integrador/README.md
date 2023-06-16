# Tablero Colaborativo de Trabajo

Este proyecto es un tablero colaborativo de trabajo construido con Express y MongoDB. Permite gestionar usuarios y tareas, proporcionando funcionalidades de creación, lectura, actualización y eliminación (CRUD) tanto para los usuarios como para las tareas.

## Funcionalidades

- Registro de usuarios
- Inicio de sesión de usuarios
- Gestión de usuarios (crear, leer, actualizar, eliminar)
- Gestión de tareas (crear, leer, actualizar, eliminar)
- Asignación de tareas a usuarios
- Comentarios en las tareas

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
2. Abre el archivo `server.js` y busca la siguiente línea de código:

```javascript
mongoose.connect("mongodb://localhost:27017/mydatabase", {
  useNewUrlParser: true,
  useUnifiedTopology: true,
});
```

3. Reemplaza `'mongodb://localhost:27017/mydatabase'` con la URL de conexión correcta de tu base de datos MongoDB. Asegúrate de que la base de datos exista.

## Ejecutar el servidor

1. Ejecuta node server.js para iniciar el servidor en el puerto 3000.
2. El servidor estará disponible en http://localhost:3000.

## Uso del API

A continuación se presentan las rutas principales del API:

## Usuarios

- GET /users: Obtiene la lista de usuarios.
- GET /users/:id: Obtiene los detalles de un usuario específico.
- POST /users: Crea un nuevo usuario.
- PUT /users/:id: Actualiza los detalles de un usuario específico.
- DELETE /users/:id: Elimina un usuario específico.

## Tareas

- GET /tasks: Obtiene la lista de tareas.
- GET /tasks/:id: Obtiene los detalles de una tarea específica.
- POST /tasks: Crea una nueva tarea.
- PUT /tasks/:id: Actualiza los detalles de una tarea específica.
- DELETE /tasks/:id: Elimina una tarea específica.
