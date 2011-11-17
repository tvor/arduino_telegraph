/*
 * Arduino Telegraph Sounder
 * Code to hook up an old telegraph sounder to an Arduino
 * Copyright Patrick Schless 2011
 * modified to American (Railroad) Morse
 * added numbers and punctuation
 */

#include "TelegraphSounder.h"

TelegraphSounder::TelegraphSounder(uint8_t p) {
  speed = 50;

  pin = p;
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
}

void TelegraphSounder::on(uint8_t count) {
  digitalWrite(pin, HIGH);
  delay(speed * count);
  digitalWrite(pin, LOW);
}

void TelegraphSounder::space() {
  elementGap();
}

void TelegraphSounder::dot() {
  on(1);
  elementGap();
}

void TelegraphSounder::dash() {
  on(3);
  elementGap();
}

void TelegraphSounder::L_dash() {
  on(4);
  elementGap();
}

void TelegraphSounder::zero_dash() {
  on(5);
  elementGap();
}

void TelegraphSounder::elementGap() {
  delay(speed * 1);
}

void TelegraphSounder::letterGap() {
  delay(speed * 2); // minus 1 for element gap
}

void TelegraphSounder::wordGap() {
  delay(speed * 4); // minus 1 for element gap and 2 for letter gap
}

void TelegraphSounder::say(char *word, uint8_t size) {
  for(uint8_t i=0; i<size; i++) {
    switch(word[i]) {
      case('1'):
        dot(); dash(); dash(); dot();
        break;
      case('2'):
        dot(); dot(); dash(); dot(); dot();
        break;
      case('3'):
        dot(); dot(); dot(); dash(); dot();
        break;
      case('4'):
        dot(); dot(); dot(); dot(); dash();
        break;
      case('5'):
        dash(); dash(); dash();
        break;
      case('6'):
        dot(); dot(); dot(); dot(); dot(); dot();
        break;
      case('7'):
        dash(); dash(); dot(); dot();
        break;
      case('8'):
        dash(); dot(); dot(); dot(); dot();
        break;
      case('9'):
        dash(); dot(); dot(); dash();
        break;
      case('0'):
        zero_dash();
        break;
      case('a'):
        dot(); dash();
        break;
      case('b'):
        dash(); dot(); dot(); dot();
        break;
      case('c'):
        dot(); dot(); space(); dot();
        break;
      case('d'):
        dash(); dot(); dot();
        break;
      case('e'):
        dot();
        break;
      case('f'):
        dot(); dash(); dot();
        break;
      case('g'):
        dash(); dash(); dot();
        break;
      case('h'):
        dot(); dot(); dot(); dot();
        break;
      case('i'):
        dot(); dot();
        break;
      case('j'):
        dash(); dot(); dash(); dash();
        break;
      case('k'):
        dash(); dot(); dash();
        break;
      case('l'):
        L_dash();
        break;
      case('m'):
        dash(); dash();
        break;
      case('n'):
        dash(); dot();
        break;
      case('o'):
        dot(); space(); dot();
        break;
      case('p'):
        dot(); dot(); dot(); dot(); dot();
        break;
      case('q'):
        dot(); dot(); dash(); dot();
        break;
      case('r'):
        dot(); space(); dot(); dot();
        break;
      case('s'):
        dot(); dot(); dot();
        break;
      case('t'):
        dash();
        break;
      case('u'):
        dot(); dot(); dash();
        break;
      case('v'):
        dot(); dot(); dot(); dash();
        break;
      case('w'):
        dot(); dash(); dash();
        break;
      case('x'):
        dot(); dash(); dot(); dot();
        break;
      case('y'):
        dot(); dot(); space(); dot(); dot();
        break;
      case('z'):
        dot(); dot(); dot(); space(); dot();
        break;
      case('.'):
        dot(); dot(); dash(); dash(); dot(); dot();
        break;
      case(','):
        dot(); dash(); dot(); dash();
        break;
      case('?'):
        dash(); dot(); dot(); dash(); dot();
        break;
      case('!'):
        dash(); dash(); dash(); dot();
        break;
      case(' '):
        wordGap();
        break;
    }
    if (word[i] != ' ') letterGap();
  }
  digitalWrite(pin, LOW);
}

