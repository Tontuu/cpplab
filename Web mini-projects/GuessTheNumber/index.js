
var randomNumber = Math.floor(Math.random()*100)+1;
var guesses = document.querySelector(".guesses");
var endgameAlert = document.querySelector(".endgameAlert");
var lowOrHigh = document.querySelector(".lowOrHigh");
//var num = document.querySelector(".num");

var guessInput = document.querySelector("#hint-input");
var guessSubmit = document.querySelector("#button-guess-submit");
//num.textContent = randomNumber;

var guessCountPara = document.querySelector("#guess-count")
var guessCount = 9;
var resetButton = document.querySelector("#button-newgame");
let submitButton = document.querySelector("#button-guess-submit");

//classes
var body = document.querySelector('body');

function cardBlink(x) {
	if (x == false) {
		body.classList.remove("red-alert");	
		void body.offsetWidth;
		body.classList.add("red-alert");
	}
	else {
		body.classList.remove("green-alert");
		void body.offsetWidth;
		body.classList.add("green-alert");
	}
}

function setupEndGame() {
	guessInput.disabled = true;
	guessSubmit.disabled = true;
	resetButton.style.visibility = "visible";
	submitButton.style.visibility = "hidden";
	resetButton.style.maxHeight = "45px";
	submitButton.style.maxHeight = "0px";
	resetButton.style.top = "0px";
	resetButton.addEventListener('click',resetGame);
	guesses.style.visibility =  "visible";
	guessCountPara.textContent = guessCount;

}

function resetLoH() {
	lowOrHigh.textContent = ' ';
}
function checkHint() {
	var guessUser = Number(guessInput.value);
	if (guessCount === 9) {
		guesses.textContent = ' ';
	}

	guesses.textContent += guessUser + ' ';

	if (guessUser === randomNumber) {
		resetLoH();
		setupEndGame();
		cardBlink(1);

	}	else if(guessCount === 0) {
		guessCountPara.textContent = 0
		resetLoH();
		setupEndGame();
		cardBlink(0);

	}	else {
		guessCountPara.textContent = guessCount;
		cardBlink(0);
		if (guessUser < randomNumber) {
			lowOrHigh.textContent = 'bigger';
		} else if (guessUser > randomNumber) {
			lowOrHigh.textContent = 'smaller';
		}
	}
	
	guessCount--;
	guessInput.value = '';
	guessInput.focus();
}
	
function resetGame() {
	guessCountPara.textContent = 10;
	guessCount = 9;
	resetButton.style.visibility = "hidden";
	resetButton.style.maxHeight = "0px";
	resetButton.style.top = "28px";
	submitButton.style.visibility = "visible";
	submitButton.style.maxHeight = "45px";
	guesses.style.visibility =  "hidden";

	var resetParas = document.querySelector('.guesses');
	for (var i = 0 ; i < resetParas.length ; i++) {
		resetParas[i].textContent = '';
	}
	
	guessInput.disabled = false;
	guessSubmit.disabled = false;
	guessInput.value = '';
	guesses.textContent = '';
	guessInput.focus();
	endgameAlert.textContent = '';

	randomNumber = Math.floor(Math.random()*100)+1;
//	num.textContent = randomNumber;
}

guessSubmit.addEventListener('click', checkHint);








