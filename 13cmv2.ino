const int Trigger = 10;   //Pin digital  para el Trigger del sensor
const int Echo = 9;   //Pin digital  para el Echo del sensor
const int IN1=52;
const int IN2=48;
const int IN3=53;
const int IN4=49;
const int sensor=A0; // definicion del pin correspondiente al sensor CNY70
const int negro = 500; //valor frontera del color negro medido por el CNY70
int alante = 0;
void setup(){
  delay(5000);
  pinMode(Trigger,OUTPUT); //pin como salida
 // digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  pinMode(IN1,OUTPUT); //definicion de los pines necesarios como salida, los pines de entrada no son necesarios
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  Serial.begin(9600);}
int ultrasensor(){ //función de lectura del ultrasensor, de tipo int ya que devolverá un valor tipo int
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);//Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  int t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  int d = t/59;//escalamos el tiempo a una distancia en cm
  Serial.print("Distancia: ");
  Serial.print(d);//Se envia el valor de la distancia a través del monitor serie
  Serial.println("cm");
  return d;}//la función ultrasensor devuelve el valor de "d"
void loop(){
  int contador=0; //se define la variable contador, a cada vuelta del void loop, vuelve a 0
  while(ultrasensor()>45 && contador <15000){//el robot girará, evaluando la lectura del ultrasensor.
    alante=0; //cuando el robot vuelve a girar, es decir, no detectar ningún objeto, alante vuelve a 0
    Serial.println(ultrasensor());
    contador++;
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW); 
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    Serial.println("El robot está girando en círculos.");}
    Serial.println("El robot está avanzando");//Si el robot detecta un objeto o realiza un numero determinado de lecturas sin detectar ningun objeto, avanzará
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH); 
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  alante++; //alante es un contador que señala el número de secuencias de avanzado realizadas por el robot. Esto está hecho para que no se quede atascado.
  Serial.println(alante);
  if (alante>=25){//si alante alcanza un valor de 25, se moverá hacia atrás durante 400 ms,
    alante=0;
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW); 
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    delay(400);
    Serial.println("Retroceso");}}//retroceso
