let snake;
let apple;
let resolution;
let pause;
let w, h;
let applesCount;

function setup() {
  resolution = 20;
  frameRate(10);
  createCanvas(600, 400);
	w = floor(width / resolution);
	h = floor(height / resolution);
  snake = new Snake();
  apple = new Apple();
  applesCount = 0;
  pause = false;
  snake.grow();
  snake.grow();
}

function keyPressed() {
  switch(keyCode) {
    case UP_ARROW:
      if (snake.ydir != 1) {
        snake.setDir(0, -1);
      }
      break;
    case DOWN_ARROW:
      if (snake.ydir != -1) {
        snake.setDir(0, 1);
      }
      break;
    case LEFT_ARROW:
      if (snake.xdir != 1) {
        snake.setDir(-1, 0);
      }
      break;
    case RIGHT_ARROW:
      if (snake.xdir != -1) {
        snake.setDir(1, 0);
      }
      break;
    case ESCAPE:
      togglePause();
      break;
  } 
}

function togglePause() {
  if (pause) {
    pause = false;
  } else {
    pause = true;
  }
}

function draw() {
  if (snake.body[snake.len].x == apple.pos.x && snake.body[snake.len].y == apple.pos.y) {
    apple.eaten();
    snake.grow();
    applesCount++;
    console.log("Eaten");
  }

  scale(resolution);
  background(75);

  snake.show();
  if (!pause) {
    snake.update();
  }
  if (!snake.endGame()) {
    console.log("GameOver");
    noLoop();
  }
  apple.show();

  fill(255);
  textSize(1);
  textStyle(ITALIC);
  text(`apples: ${applesCount}`, w-w+0.2, h-h+19.5);

}

