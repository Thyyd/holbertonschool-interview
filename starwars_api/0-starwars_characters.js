#!/usr/bin/node
const request = require('request');
 
const movieId = process.argv[2];
const filmUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;
 
request(filmUrl, (err, res, body) => {
  if (err) return console.error(err);
 
  const characters = JSON.parse(body).characters;
 
  const fetchInOrder = (urls, index) => {
    if (index >= urls.length) return;
 
    request(urls[index], (err, res, body) => {
      if (err) return console.error(err);
      console.log(JSON.parse(body).name);
      fetchInOrder(urls, index + 1);
    });
  };
 
  fetchInOrder(characters, 0);
});
 