class Switch{
  private:
  int pin;
  const byte onCode = 0x01;
  const byte offCode = 0x02;
  
  public:
  const byte id;
  Switch(byte id, int pin);
  void executeCodeWithId(byte cmd, byte id);
  void on();
  void off();
  bool state();
};

Switch::Switch(byte id, int pin) : id(id){
  this->pin = pin;
}

void Switch::executeCodeWithId(byte code, byte id){
  if (id != this->id){
    return;
  }
  
  if (code == this->onCode){
    this->on();
  } else if (code == this->offCode){
    this->off();
  }
}

bool Switch::state(){
  return digitalRead(this->pin);
}

void Switch::on(){
  digitalWrite(this->pin, HIGH);
}

void Switch::off(){
  digitalWrite(this->pin, LOW);
}
