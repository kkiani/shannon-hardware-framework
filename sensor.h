class Sensor{
  private:
  int pin;

  public:
  const byte id;
  Sensor(byte id, int pin);
  int value();
};

Sensor::Sensor(byte id, int pin): id(id){
  this->pin = pin;
}

int Sensor::value(){
  return digitalRead(this->pin);
}
