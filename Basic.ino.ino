#define cout 12
#define cs0s1 2
#define cs2 3
#define cs3 4
#define ir 11



typedef struct color{
  char* name;
  int s2;
  int s3;
  int min;
  int max;
  int value;
};

int red = 0;
int blue = 0;


int green = 0;

color reds = {"red",LOW,LOW,10,70,0};
color blues = {"blue",LOW,HIGH,5,50,0};
color greens = {"green",HIGH,HIGH,10,70,0};

int irmove = 0;
int irdata = 0;
void setup() {
  // put your setup code here, to run once:

  pinMode(cs0s1, OUTPUT);
  pinMode(cs2, OUTPUT);
  pinMode(cs3, OUTPUT);
  Serial.begin(9600);
}

int setBound(color c){
  
  digitalWrite(cs2, c.s2);
  digitalWrite(cs3, c.s3);
  return pulseIn(cout,LOW);
}

void loop() {
  digitalWrite(cs0s1, HIGH); // set frequency to 100 % DO NOT CHANGE
  char command = Serial.read();
  if (command == 'R'){
    reds.max = setBound(reds);
  }
  else if ( command == 'E' ){
    reds.min = setBounds(reds);
  }
  else if (command == 'B'){
    blues.max = setBounds(blues);
  }
  else if (command == 'V'){
    blues.min = setBounds(blues);
  }
  else if ( command == 'G'){

  }
  else if ( command == 'B'){

  }
  digitalWrite(cs2, LOW);
  digitalWrite(cs3, LOW);
  Serial.print("    Red  value= ");
  red = pulseIn(cout, LOW);
  Serial.print(red);
  digitalWrite(cs2, LOW);
  digitalWrite(cs3, HIGH);
  Serial.print("/  Blue  value= ");
  blue = pulseIn(cout, LOW);
  Serial.print(blue);
  digitalWrite(cs2, HIGH);
  digitalWrite(cs3, HIGH);
  Serial.print("/  Green  value= ");
  green = pulseIn(cout, LOW);
  Serial.print(green);
  Serial.print("   / IR  motion = ");
  irmove = pulseIn(ir,LOW);
  Serial.print(irmove);
  Serial.print("   / IR  presence = ");
  irdata = digitalRead(ir);
  Serial.print(irdata);

  Serial.print('\n');
  


  delay(200);
}
