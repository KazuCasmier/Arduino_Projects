#include <LiquidCrystal.h>
#include <LedControl.h>

// Setup for the lcd screen as well as an array for all of the leds that are in use for score
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int led_Pin[] = {8, 9, 10, 11, 12, 13};

// all the variables that I used for the program
const int numCols = 16;
const int X_pin = A0;
const int Y_pin = A1;
int player_x = 1;
int player_y = 0;
int coin_count = 0;
int coin_pos_x = random(0, 16);
int coin_pos_y = random(0, 2);
int score = 0;

bool coin_placed = false;

// on screen graphics for the coin and the player aswell as a clear graphic
byte player[] = {B01110, B01110, B00100, B01110, B10101, B00100, B01010, B01010};
byte clear_d[] = { B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };
byte coin[] = { B00000, B00000, B00100, B01110, B01110, B00100, B00000, B00000 };

void setup() {
  Serial.begin(9600);

  // loads the graphics into memory
  lcd.createChar(0, player);
  lcd.createChar(1, clear_d);
  lcd.createChar(2, coin);

  // starts up the screen and creates the character at 1,0
  lcd.begin(16, 2);
  lcd.setCursor(player_x, player_y);
  lcd.write(byte(0));

  // defines all the led pis as outputs
    for (int i =0;i<5;i++)
  {
    pinMode(led_Pin[i], OUTPUT);
  }
}

void loop() {
  lcd.setCursor(player_x, player_y);

  // Movement along the x-axis
  if(analogRead(X_pin) > 510){
    player_x = player_x + 1;
    if (player_x > 15){
      player_x = 15;
    }
    lcd.setCursor(player_x, player_y);
    lcd.write(byte(0));
    lcd.leftToRight();
    lcd.setCursor(player_x-1, player_y);
    lcd.write(byte(1));

  }
  else if(analogRead(X_pin) < 500){
    player_x = player_x - 1;
    if (player_x < 0){
      player_x = 0;
    }
    lcd.setCursor(player_x, player_y);
    lcd.write(byte(0));
    lcd.leftToRight();
    lcd.setCursor(player_x+1, player_y);
    lcd.write(byte(1));
  }

  // movement across the y-axis
  if (analogRead(Y_pin) > 1000){
    player_y--;
    if (player_y < -1){
      player_y++;
    }
    lcd.setCursor(player_x, player_y);
    lcd.write(byte(0));
    lcd.leftToRight();
    lcd.setCursor(player_x, player_y+1);
    lcd.write(byte(1));
  }
  else if(analogRead(Y_pin) < 250){
    player_y++;
    if (player_y >= 1){
      player_y--;
    }
    lcd.setCursor(player_x, player_y);
    lcd.write(byte(0));
    lcd.leftToRight();
    lcd.setCursor(player_x, player_y-1);
    lcd.write(byte(1));
  }


  if (coin_count == 0 && coin_placed == false){
    create_coin();
  }
  else if (coin_count == 1 && coin_placed == true){
    coin_pickup(coin_pos_x, coin_pos_y, player_x, player_y);
    }
  

  // all of the debug prints to the serial monitor
  Serial.print("player x&y: ");
  Serial.print(player_x);
  Serial.print(",");
  Serial.print(player_y);
  Serial.print(" | Score:");
  Serial.print(score);
  Serial.print(" | ");
  Serial.print("Coin X: ");
  Serial.print(coin_pos_x);
  Serial.print("| Coin Y: ");
  Serial.print(coin_pos_y);
  Serial.print(" | ");
  Serial.println(coin_count);
  delay(200);

}

void create_coin()
{
  // Takes a random position on the LCD and creates and places a singular coin
  coin_pos_x = random(0, 16);
  coin_pos_y = random(0, 2);

  lcd.setCursor(coin_pos_x, coin_pos_y);
  lcd.write(byte(2));
  coin_count++;
  coin_placed = true;
  return coin_count;
}

void coin_pickup(int coin_pos_x, int coin_pos_y, int player_x, int player_y)
{
  // I kinda messed up the code before writing this function, and had to come up with some dumb logic to flip the sign of the y-axis for the player
  int bnew = 0;
  if (player_y == -1){
    bnew = 1;
  }
  else if (player_y == 0){
    bnew = 0;
  }

  // Checks if the x and y of the player matches with the x and y of the coin
  // if they match it will add one to the score, decrease the coin count then run the update score function
  // aswell as create another coin
  if(coin_pos_x == player_x && coin_pos_y == bnew)
  {
    score++;
    coin_count--;
    coin_placed = false;
    score_update(score);
    create_coin();
  }
  
}

void score_update(int score)
{
  // I did steal this code from the internet, but the basic idea is
  // creating an array for all of the leds on the board and converting the score to a binary number
  // after that you iterate through the list and comparing the position in the binary number to the correct LED and then
  // decide whether it needs to be on or off
  for (int i =0;i<6;i++)
  {
    if (bitRead(score, i)==1)
    {
      digitalWrite(led_Pin[i], HIGH);
    }
    else
    {
      digitalWrite(led_Pin[i], LOW);
    }
  }
}



