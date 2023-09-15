import { config } from "dotenv";
config();

export const PORT = process.env.PORT || 4000;
export const MONGODB_URI = process.env.MONGODB_URI || "mongodb+srv://admin:admin@cluster0.ubxgt.mongodb.net/?retryWrites=true&w=majority";
