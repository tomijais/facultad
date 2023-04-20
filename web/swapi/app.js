const HTML = document.getElementById("characters");

const request = Promise.resolve(
  fetch("https://swapi.dev/api/people/").then((e) => e.json())
);

request.then((response) => {
  console.log(response);

  let characters = response.results;
  let characterHTML = "";
  for (let i = 0; i < characters.length; i++) {
    let character = characters[i];
    let characterName = character.name;
    let characterHeight = character.height;
    let characterImage = `https://starwars-visualguide.com/assets/img/characters/${
      i + 1
    }.jpg`;
    characterHTML += `
                  <div class="character">
                      <img src="${characterImage}" alt="${characterName}">
                      <h3>${characterName}</h3>
                      <p>Height: ${characterHeight} cm</p>
                  </div>
              `;
  }
  HTML.innerHTML = characterHTML;
});

const params = {
  name: "Tomas",
  age: 21,
  email: "tomas@example.com",
  city: "Buenos Aires",
};
const POST = fetch("https://httpbin.org/post", {
  body: JSON.stringify(params),
  method: "POST",
  headers: {
    "Content-Type": "application/json",
  },
})
  .then((res) => res.json())
  .then((data) => console.log(data));
