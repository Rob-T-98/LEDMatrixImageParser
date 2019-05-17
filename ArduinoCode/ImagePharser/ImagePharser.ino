#define row1 2
#define row2 3
#define row3 4
#define row4 5
#define row5 6
#define row6 7
#define row7 8
#define row8 9
#define row9 10
#define row10 11
String incomming = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(0,OUTPUT);//reset pin
  pinMode(1,OUTPUT);//pulse pin
  pinMode(row1,OUTPUT);
  pinMode(row2,OUTPUT);
  pinMode(row3,OUTPUT);
  pinMode(row4,OUTPUT);
  pinMode(row5,OUTPUT);
  pinMode(row6,OUTPUT);
  pinMode(row7,OUTPUT);
  pinMode(row8,OUTPUT);
  pinMode(row9,OUTPUT);
  pinMode(row10,OUTPUT);
}

void loop() 
{
  if(Serial.available()>0) displayImage(Serial.readString());
}

void displayImage(String img)
{
  String imgArr[10];
  for(int i=0;i<=9;i++)
  {
    imgArr[i]=getValue(img,',',i);
  }
  uint32_t pauseTime = 0.1 * 60000L;
  for( uint32_t tStart = millis();  (millis()-tStart) < pauseTime;  ){
    int x=0;
    while(x<=9)
    {
      displayColumn(imgArr[x]);
      digitalWrite(row1, LOW);
      digitalWrite(row2, LOW);
      digitalWrite(row3, LOW);
      digitalWrite(row4, LOW);
      digitalWrite(row5, LOW);
      digitalWrite(row6, LOW);
      digitalWrite(row7, LOW);
      digitalWrite(row8, LOW);
      digitalWrite(row9, LOW);
      digitalWrite(row10, LOW);
      digitalWrite(1, HIGH);
      digitalWrite(1, LOW);
      delay(1);
      x++;
    }
    digitalWrite(0, HIGH);
    digitalWrite(0, LOW);
    delay(1); 
  }
}

void displayColumn(String val)
{
  for(int i=0;i<=9;i++)
  {
    if(val.charAt(i)=='1')
    {
      digitalWrite(i+2, HIGH);
    }
  }
}

String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
