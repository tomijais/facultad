// Obtiene los elementos de la página web
const regInput = document.getElementById("reg");
const cantInput = document.getElementById("cant");
const promInput = document.getElementById("prom");
const mayorInput = document.getElementById("mayor");
const menorInput = document.getElementById("menor");
const registrarBtn = document.getElementById("btnreg");
const resetBtn = document.getElementById("reset");

// Variables para realizar el seguimiento de los valores ingresados
let valores = [];
let cantidad = 0;
let promedio = 0;
let mayor = 0;
let menor = 0;

// Función para actualizar los campos en la página web
function actualizarCampos() {
  cantInput.value = cantidad;
  promInput.value = promedio.toFixed(2);
  mayorInput.value = mayor;
  menorInput.value = menor;
}

// Función para registrar un valor
function registrarValor() {
  const valor = parseFloat(regInput.value);
  if (isNaN(valor)) {
    alert("Ingrese un valor numérico válido.");
    return;
  }
  valores.push(valor);
  cantidad++;
  promedio = valores.reduce((a, b) => a + b) / cantidad;
  mayor = Math.max(...valores);
  menor = Math.min(...valores);
  actualizarCampos();
  regInput.value = "";
}

// Agrega un controlador de eventos al botón Registrar
registrarBtn.addEventListener("click", (e) => {
  e.preventDefault();
  registrarValor();
});

resetBtn.addEventListener("click", (e) => {
  e.preventDefault();
  valores = [];
  cantidad = 0;
  promedio = 0;
  mayor = 0;
  menor = 0;
  actualizarCampos();
});
