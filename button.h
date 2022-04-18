class Button{
  public:
  void update();
  Button(int pin);
  void (*pushDownAction)(void);
  void (*pushUpAction)(void);
  
  private:
  int pin;
  bool state = false;
};

Button::Button(int pin){
  this->pin = pin;
}

void Button::update(){
  bool newState = digitalRead(this->pin);

  if (this->state == newState){
    return;
  }

  if (newState == true){
    if (pushDownAction){
      this->pushDownAction();
    }
  } else {
    if (pushUpAction){
      this->pushUpAction();
    }
  }
  
  this->state = newState;
  delay(100);
}
