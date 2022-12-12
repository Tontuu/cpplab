class Snake {
	constructor() {
		this.body = [];
		this.x = 0;
		this.y = 0;
		this.body[0] = createVector(this.x, this.y);
		this.xdir= 1;
		this.ydir = 0;
		this.len = 0;
	}
	setDir(x, y) {
		this.xdir = x;
		this.ydir = y;
	}

	grow() {
		let head = this.body[this.body.length - 1].copy()
		this.len++;
		this.body.push(head);
	}
	update() {
		let head = this.body[this.body.length - 1].copy();
		this.body.shift();
		head.x += this.xdir;
		head.y += this.ydir;
		this.body.push(head);
	}
	show() {
		for (let i = 0; i < this.body.length; i++) {
			stroke(0);
			strokeWeight(0.05);
			fill(0, 255, 0);
			rect(this.body[i].x,this.body[i].y,1,1);
		}
	}
	endGame() {
		let x = this.body[this.body.length - 1].x;
		let y = this.body[this.body.length - 1].y;
		for (let i = 0; i < this.body.length - 1; i++) {
			let part = this.body[i];
			if (part.x == x && part.y == y) {
				console.log("hitted yourself");
				return false;
			}
			if (x > w-1 || x < 0 || y > h-1 || y < 0) {
				console.log("hitted the wall")
				return false;
			}
		}
		return true;
	}
}

class Apple {
	constructor() {
		this.pos = createVector(0, 0);
		this.w = floor(width / resolution);
		this.h = floor(height / resolution);
		this.pos.x = floor(random(w));
		this.pos.y = floor(random(h));
		snake = new Snake();
	}
	eaten() {
		this.pos.x = floor(random(w));
		this.pos.y = floor(random(h));
		for (let i = 0; i< snake.body.length; i++) {
			if (this.pos.x == snake.body[i].x && this.pos.y == snake.body[i].y) {
				this.eaten();
			}
		}
	}
	show() {
		noStroke();
		fill(150, 0, 0);
		rect(this.pos.x, this.pos.y, 1, 1);
	}
}
