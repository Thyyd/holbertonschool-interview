#!/usr/bin/node

const request = require('request');

// Récupère l'ID du film depuis les arguments
const movieId = process.argv[2];

if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <movie_id>');
  process.exit(1);
}

// URL de l'API Star Wars
const apiUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

// Fonction pour récupérer un personnage par URL
function getCharacter (url) {
  return new Promise((resolve, reject) => {
    request(url, (error, response, body) => {
      if (error) {
        reject(error);
      } else {
        resolve(JSON.parse(body).name);
      }
    });
  });
}

// Récupère le film
request(apiUrl, async (error, response, body) => {
  if (error) {
    console.error('Error:', error);
    return;
  }

  if (response.statusCode !== 200) {
    console.error('Film not found');
    return;
  }

  const filmData = JSON.parse(body);
  const characterUrls = filmData.characters;

  // Récupère tous les personnages dans l'ordre
  for (const url of characterUrls) {
    try {
      const name = await getCharacter(url);
      console.log(name);
    } catch (err) {
      console.error('Error fetching character:', err);
    }
  }
});
