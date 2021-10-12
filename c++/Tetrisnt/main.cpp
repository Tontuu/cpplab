#include <iostream>
#include <SFML/Graphics.hpp>
#include "time.h"

const int M = 30;
const int N = 10;

int field[M][N] = {0};

struct Point
  {int x,y;} a[4], b[4];

int figures[7][4] =  {
  1,3,5,7, // I
  2,4,5,7, // Z
  3,5,4,6, // S
  3,5,4,7, // T
  2,3,5,7, // L
  3,5,7,6, // J
  2,3,4,5, // O
};

bool check() {
  for (int i = 0; i < 4; i++) 
    if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0;
    else if (field[a[i].y][a[i].x]) return 0;

  return 1;
};


int main() {
  srand(time(0));

  sf::RenderWindow window (sf::VideoMode(160, 480), "Tetris");

  sf::Texture texture;
  sf::Texture backgroundTexture;
  texture.loadFromFile("assets/tiles.png");
  backgroundTexture.loadFromFile("assets/background.png");

  sf::Sprite background(backgroundTexture);
  background.setTextureRect(sf::IntRect(0, 0, 159, 480));
  sf::Sprite sprite(texture);
  sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));

  int directionX = 0, colorNum = 1;
  bool rotation = 0;
  float timer = 0, delay = 0.2;

  sf::Clock clock;

  // Opening window!
  while (window.isOpen()) {
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;

    sf::Event event;
    while(window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      
      // Setting up KEYS
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) window.close(); 
        else if (event.key.code == sf::Keyboard::K) rotation = true;
        else if (event.key.code == sf::Keyboard::Up) rotation = true;
        else if (event.key.code == sf::Keyboard::H) directionX = -1;
        else if (event.key.code == sf::Keyboard::Left) directionX = -1;
        else if (event.key.code == sf::Keyboard::L) directionX = 1;
        else if (event.key.code == sf::Keyboard::Right) directionX = 1;
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) delay = 0.05;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) delay = 0.05;

    // Moving
    for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].x += directionX; }
    if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i]; 

    // Rotate
    if (rotation) {
      Point p = a[1];
      for (int i = 0; i < 4; i++) {
        int x = a[i].y - p.y;
        int y = a[i].x - p.x;
        a[i].x = p.x - x;
        a[i].y = p.y + y;
      }
      if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];
    }

    // Tick
    if (timer > delay) {
      for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; }
      
      if (!check()) {
        for (int i = 0; i < 4; i++) field[b[i].y][b[i].x] = colorNum;

        colorNum = 1 + rand() % 7;
        int n = rand() % 7;
        for (int i = 0; i < 4; i++) {
          a[i].x = figures[n][i] % 2;
          a[i].y = figures[n][i] / 2;
        }
      }

      timer = 0;
    }
   
    directionX = 0; rotation = 0, delay = 0.3;

    // Check Lines
    int k = M - 1;
    for (int i = M - 1;i > 0; i--) {
      int count = 0;
      for (int j = 0; j < N; j++) {
        if (field[i][j]) count++;
        field[k][j]=field[i][j];
      }
      if (count < N) k--; 
    }


    // Drawing
    window.clear(sf::Color(20, 50, 80));
    background.setPosition(0,0);
    window.draw(background);

    for (int i = 0; i < M; i++)
      for (int j = 0; j < N; j++) {
        if (field[i][j] == 0) continue;
        sprite.setTextureRect(sf::IntRect(field[i][j]*16.25,0,16,16));
        sprite.setPosition(j * 16, i * 16);
        window.draw(sprite);
      }

    for (int i = 0; i < 4; i++) {
      sprite.setTextureRect(sf::IntRect(colorNum*16.25,0,16,16));
      sprite.setPosition(a[i].x * 16, a[i].y * 16);
      window.draw(sprite);
    }
    window.display();
  }

  return 0;
}
