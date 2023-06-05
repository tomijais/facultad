const express = require('express');
const app = express();

const quotes = [
  "Life isn't about getting and having, it's about giving and being.",
  "Whatever the mind of man can conceive and believe, it can achieve.",
  "Strive not to be a success, but rather to be of value.",
  "Two roads diverged in a wood, and I—I took the one less traveled by, And that has made all the difference.",
  "I attribute my success to this: I never gave or took any excuse.",
  "You miss 100% of the shots you don't take.",
  "I've missed more than 9000 shots in my career. I've lost almost 300 games. 26 times I've been trusted to take the game winning shot and missed. I've failed over and over and over again in my life. And that is why I succeed.",
  "The most difficult thing is the decision to act, the rest is merely tenacity.",
  "Every strike brings me closer to the next home run.",
  "Definiteness of purpose is the starting point of all achievement.",
  "We must balance conspicuous consumption with conscious capitalism.",
  "Life is what happens to you while you're busy making other plans.",
  "We become what we think about.",
  "Twenty years from now you will be more disappointed by the things that you didn't do than by the ones you did do, so throw off the bowlines, sail away from safe harbor, catch the trade winds in your sails. Explore, Dream, Discover.",
  "Life is 10% what happens to me and 90% of how I react to it.",
  "The most common way people give up their power is by thinking they don't have any.",
  "The mind is everything. What you think you become.",
  "The best time to plant a tree was 20 years ago. The second best time is now.",
  "An unexamined life is not worth living.",
  "Eighty percent of success is showing up."
];

app.get('/', (req, res) => {
  const randomIndex = Math.floor(Math.random() * quotes.length);
  res.send(`<p>${quotes[randomIndex]}</p>`);
});

app.get('/sum', (req, res) => {
  const num1 = parseInt(req.query.num1);
  const num2 = parseInt(req.query.num2);
  const sum = num1 + num2;
  res.send(`<p>${sum}</p>`);
});

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});