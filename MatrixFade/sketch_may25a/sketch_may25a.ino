#include "SmartMatrix_32x32.h"

SmartMatrix matrix;

#define REDTOYELLOW 0
#define YELLOWTOGREEN 1
#define GREENTOCYAN 2
#define CYANTOBLUE 3
#define BLUETOMAGENTA 4
#define MAGENTATORED 5

rgb24 color;
int colorState;

void setup() 
{
  matrix.begin();
  color.red = 0xff;
  color.green = 0x00;
  color.blue = 0x00;
  
  colorState = REDTOYELLOW;
}

void loop()
{
  matrix.fillScreen (color);
  getNextColor();
  
  matrix.swapBuffers(true);
  delay (100);
}

void getNextColor()
{
  
  switch (colorState)
  {
    case REDTOYELLOW:
      color.green++;
      if (color.green == 0xff)
      {
        colorState = YELLOWTOGREEN;
      }
    break;
    
    case YELLOWTOGREEN:
      color.red--;
      if (color.red == 0)
      {
        colorState = GREENTOCYAN;
      }
    break;
    
    case GREENTOCYAN:
      color.blue++;
      if (color.blue == 0xff)
      {
        colorState = CYANTOBLUE;
      }
    break;
    
    case CYANTOBLUE:
      color.green--;
      if (color.green == 0)
      {
        colorState = BLUETOMAGENTA;
      }
    break;
    
    case BLUETOMAGENTA:
      color.red++;
      if (color.red == 0xff)
      {
        colorState = MAGENTATORED;
      }
    break;
    
    case MAGENTATORED:
      color.blue--;
      if (color.blue == 0)
      {
        colorState = REDTOYELLOW;
      }
      break;
  }
}






