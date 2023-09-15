import User from "../models/User.js";

export const createAdminUser = async () => {
  const userFound = await User.findOne({ email: "fede@hayes" });

  if (userFound) return;

  const newUser = new User({
    username: "admin",
    email: "admin@localhost",
  });

  newUser.password = await newUser.encryptPassword("fedepassword");

  const admin = await newUser.save();

  console.log("Admin user created", admin);
};
