import express from "express";
import { connect, Schema, model } from "mongoose";
import pkg from "body-parser";
import { checkAuthenticated } from "./middleware/checkUser";
const session = require("express-session");
const { json } = pkg;
import { router } from "./routes/ingreso";

const app = express();
app.use(json());

app.use(
  session({
    secret: "mi_secreto",
    resave: false,
    saveUninitialized: false,
  })
);

// Conexión a la base de datos
connect("mongodb://localhost:27017/db_integracion", {
  useNewUrlParser: true,
  useUnifiedTopology: true,
});

// Definición del esquema para usuarios
const userSchema = new Schema({
  name: String,
  email: String,
  password: String,
});

// Definición del modelo de usuarios
const User = model("User", userSchema);

// Definición del esquema para tareas
const taskSchema = new Schema({
  title: String,
  description: String,
});

// Definición del modelo de tareas
const Task = model("Task", taskSchema);

app.use("/", router);

// Rutas de usuarios
app.get("/users", async (req, res) => {
  try {
    const users = await User.find();
    res.json(users);
  } catch (error) {
    res.status(500).json({ error: "Error al obtener los usuarios" });
  }
});

app.get("/users/:id", async (req, res) => {
  const userId = req.params.id;
  try {
    const user = await User.findById(userId);
    if (user) {
      res.json(user);
    } else {
      res.status(404).json({ error: "Usuario no encontrado" });
    }
  } catch (error) {
    res.status(500).json({ error: "Error al obtener el usuario" });
  }
});

app.post("/users", async (req, res) => {
  const newUser = req.body;
  try {
    const createdUser = await User.create(newUser);
    res.json(createdUser);
  } catch (error) {
    res.status(500).json({ error: "Error al crear el usuario" });
  }
});

app.put("/users/:id", async (req, res) => {
  const userId = req.params.id;
  const updatedUser = req.body;
  try {
    const user = await User.findByIdAndUpdate(userId, updatedUser, {
      new: true,
    });
    if (user) {
      res.json(user);
    } else {
      res.status(404).json({ error: "Usuario no encontrado" });
    }
  } catch (error) {
    res.status(500).json({ error: "Error al actualizar el usuario" });
  }
});

app.delete("/users/:id", async (req, res) => {
  const userId = req.params.id;
  try {
    const user = await User.findByIdAndDelete(userId);
    if (user) {
      res.sendStatus(200);
    } else {
      res.status(404).json({ error: "Usuario no encontrado" });
    }
  } catch (error) {
    res.status(500).json({ error: "Error al eliminar el usuario" });
  }
});

// Rutas de tareas
app.get("/tasks", async (req, res) => {
  try {
    const tasks = await Task.find();
    res.json(tasks);
  } catch (error) {
    res.status(500).json({ error: "Error al obtener las tareas" });
  }
});

app.post("/tasks", async (req, res) => {
  const newTask = req.body;
  try {
    const createdTask = await Task.create(newTask);
    res.json(createdTask);
  } catch (error) {
    res.status(500).json({ error: "Error al crear la tarea" });
  }
});

app.put("/tasks/:id", async (req, res) => {
  const taskId = req.params.id;
  const updatedTask = req.body;
  try {
    const task = await Task.findByIdAndUpdate(taskId, updatedTask, {
      new: true,
    });
    if (task) {
      res.json(task);
    } else {
      res.status(404).json({ error: "Tarea no encontrada" });
    }
  } catch (error) {
    res.status(500).json({ error: "Error al actualizar la tarea" });
  }
});

app.delete("/tasks/:id", async (req, res) => {
  const taskId = req.params.id;
  try {
    const task = await Task.findByIdAndDelete(taskId);
    if (task) {
      res.sendStatus(200);
    } else {
      res.status(404).json({ error: "Tarea no encontrada" });
    }
  } catch (error) {
    res.status(500).json({ error: "Error al eliminar la tarea" });
  }
});

// Iniciar el servidor
app.listen(3000, () => {
  console.log("Servidor iniciado en el puerto 3000");
});
