#include "FlexiPlot.h"

FlexiTimePlot myPlot;
FlexiXYSeries* seriesSin;

double xVal;

void setup() {
  Serial.begin(115200);

  myPlot.setID("P0");
  seriesSin = myPlot.addSeries("Button");


  xVal = 0;

}

void loop() {

  // xVal += 0.1;
  
  seriesSin->addData( analogRead(A0) );

  myPlot.plot();

  
  delay(60);

}
