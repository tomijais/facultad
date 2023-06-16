// Middleware para verificar si la sesión está iniciada
export const checkAuthenticated = (req, res, next) => {
    if (req.session && req.session.user) {
      // Si la sesión está iniciada, pasa al siguiente middleware
      next();
    } else {
      // Si la sesión no está iniciada, redirecciona al inicio de sesión
      res.redirect('/login');
    }
  };
  