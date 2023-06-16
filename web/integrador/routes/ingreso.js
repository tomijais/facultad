import { Router } from "express";

export const router = Router()
router.get("/login", (req, res) => {
  res.send("<h1>Formulario de inicio de sesión</h1>");
});

router.post("/login", async (req, res) => {
  const { username, password } = req.body;

  try {
    const user = await User.findOne({ username });

    if (user && bcrypt.compareSync(password, user.password)) {
      req.session.user = user;
      res.redirect("/dashboard");
    } else {
      res.send("Credenciales inválidas");
    }
  } catch (error) {
    console.log(error);
    res.send("Error en el servidor");
  }
});

router.get("/register", (req, res) => {
  res.send("<h1>Formulario de registro</h1>");
});

router.post("/register", async (req, res) => {
  const { username, password } = req.body;

  try {
    const hashedPassword = bcrypt.hashSync(password, 10);

    const user = new User({
      username,
      password: hashedPassword,
    });

    await user.save();

    res.redirect("/login");
  } catch (error) {
    console.log(error);
    res.send("Error en el servidor");
  }
});
